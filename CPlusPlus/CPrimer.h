#ifndef _CPRIMER_H
#define _CPRIMER_H

#include <stdio.h>
#include <vector>
#include <bitset>
#include <iostream>
#include <math.h>

using namespace std;

extern int gExt;

int getval();

class Foo{
public:
	int val[10];
	Foo()  { printf("Default\n"); }
	Foo(int a) { printf("Construct\n"); }
	Foo(Foo &f) { printf("Copy\n"); }
	Foo& operator= (const Foo &f) { printf("Assign\n"); return *this; }
	~Foo() { printf("Destroy\n"); }
};

class Bar :Foo {
public:
	Bar() : str("123"), f(123) { }
	string str;
	Foo f;
};

class X {
public:
	int x;
	X() { printf("X\n"); }
	//virtual void funcx() {}
};

class Y {
public:
	int y;
};

class A : virtual public X{
public:
	A() { printf("A\n"); }
	int a;
	virtual void funa(){}
};

class B : virtual public X{
public:
	B() { printf("B\n"); }
	int b;
	virtual void funb(){}
};

class D {
public:
	int d;
	virtual void fund() {}
};

class C : public A, public B {
public:
	C() { printf("C\n"); }
	int c;
	void func1() { c++; }
	virtual void func(){}
	virtual void funb() { c++; }
};

class A1{
public:
	A1() { printf("A1 construct\n"); }
	//virtual void funa() { printf("A1 construct\n"); };
	int a1;
};

class B1 : virtual public A1{
public:
	B1() { printf("B1 construct\n"); }
	int b1;
	virtual void funb() {}
private :
	void test1() {}
};

class D1 : public B1 {

};

class C1 :virtual public B1, public A1 {
public:
	int c1;
	virtual void func() {}
};

class Test1 {
public:
	int x;
	~Test1() { printf("Test\n"); }
};

class Test2 : public Test1 {
	virtual void func() {}
};

#endif