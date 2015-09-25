#ifndef _HEADER_1
#define _HEADER_1

#include "CPrimer.h"

class Sales_item {
public:
	double avg_prive() const;
	Sales_item set() const;
	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}
	Sales_item() : units_sold(0), revenue(0.0) {}
	typedef string::size_type index;
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

#endif