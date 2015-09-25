#include "CPrimer.h"
#include "book.h"
#include <time.h>
#include <Windows.h>
#include <stack>

using namespace std;

int gExt = 0;
extern void func_test();

typedef void(FUNC)(int, int);

void func()
{
	printf("Test Typedef FUNC\n");
}

void funtest(FUNC fun)
{
	fun;
}

int getval()
{
	return GetCurrentTime();
}

template <class type>
class templateFoo{
public:
	type val();
	void vla(type v);
private:
	type _val;
};


int main()
{
	return 0;
}