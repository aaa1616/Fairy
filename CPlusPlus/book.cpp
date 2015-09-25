#include "book.h"

void print_total(const Item_base &item)
{
	printf("%lf\n", item.net_price(1));
}

//void Item_base::magic()
//{
//	Bulk_item test;
//	string temp = test.isbn = isbn;
//	printf("%s\n", temp.c_str());
//}

void Bulk_item::memfcn(const Bulk_item &d, const Item_base &b)
{
}