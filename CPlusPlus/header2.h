#ifndef _HEADER_2
#define _HEADER_2

#include "CPrimer.h"

static int global_v = 1;

class U_Ptr {
	friend class HasPtr;
	int *ip;
	size_t use;
	U_Ptr(int *p) : ip(p), use(1) {}
	~U_Ptr() { delete ip; }
};

class HasPtr {
public:
	HasPtr(int *p, int i) : ptr(new U_Ptr(p)), val(i) {}
	HasPtr(const HasPtr &orig) : ptr(orig.ptr), val(orig.val) { orig.ptr->use++; }
	HasPtr & operator=(const HasPtr &orig);
	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int i) const { *ptr->ip = i; }
	~HasPtr();
private:
	U_Ptr *ptr;
	int val;
};

class Base {
public:
	void bar(int);
protected:
	int ival;
	int bval;
};

class Derived1 : virtual public Base {
public:
	void bar(char);
	void foo(char);
protected:
	char cval;
};
class Derived2 : virtual public Base {
public:
	void foo(int);
protected:
	int ival;
	char cval;
};
class VMI : public Derived1, public Derived2 {
	void vmi_func()
	{
	}
};

class Empty {
public:
	void emptry_func() { printf("Empty\n"); }
};

typedef void (Empty::*global_func)();

class Screen : public Empty{
public:
	Screen(global_func g) : gf(g) { (this->*gf)(); }
	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& down();
	typedef Screen& (Screen::*funct)();
	static funct menu[];
	global_func gf;

	enum Directions { HOME, FORWARD, BACK, UP, DOWN };;
	Screen& move(Directions);
};

class Outer {
public:
	Outer() {}
protected:
	int inner_v;
};

union legal_members {
	//Outer ot;
};


void normal_func();


#endif