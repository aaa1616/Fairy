#ifndef _SOURCE_H
#define _SOURCE_H

#include <string>

using namespace std;

class Sales_item {
public:
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs) const {
		return isbn == rhs.isbn;
	}
	string isbn;
	unsigned units_sold;
	double revenue;
};

#endif // !_SOURCE_H
