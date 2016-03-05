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

class A {
public:
	A() { printf("A\n"); }
	~A() { printf("des\n"); }
private:
	int a = 1;
};

class B {
public:
	B() { printf("B\n"); }
	B(const B& b) { printf("copy B\n"); }
};

class C {
public:
	C(B t) : b(t) {};
	int v;
	A a;
	B b;
};

#endif