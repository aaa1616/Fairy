#ifndef _BOOK_H
#define _BOOK_H

#include "CPrimer.h"

using namespace std;

class Bulk_item;
class Private_item;
class Protected_item;

class Item_base {
public:
	Item_base(const string &book = "", double sales_price = 0.0) : isbn(book), price(sales_price) { Item_base *p = this; p->net_price(1); }
	string book() const { return isbn; }
	virtual void magic() = 0;
	virtual double net_price(size_t n) const { printf("Item_base %lf\n", price); return 0; }
	virtual ~Item_base() {}
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base {
public:
	void magic() {}
	//virtual double net_price(size_t n) const { printf("Bulk_item %lf\n", price); return 0; }
	double net_price(double n) const { printf("Bulk_item\n"); return 0; }
	int public_test;
	Bulk_item(const string &book = "public", double sales_price = 0.0) : Item_base(book, sales_price) { Item_base *p = this; p->net_price(1); }
	void memfcn(const Bulk_item &d, const Item_base &b);
	void set_price(double prs) { price = prs; }
protected:
	int protected_test;
private:
	int private_test;
};

class Private_item : private Item_base {
public:
	Private_item(const string &book = "private", double sales_price = 0.0) : Item_base(book, sales_price) {}
};

class Private_de_item : private Private_item {

};

class Protected_item: protected Item_base {
public:
	Protected_item(const string &book = "", double sales_price = 0.0) : Item_base(book, sales_price) {}
};

void print_total(const Item_base &item);

#endif