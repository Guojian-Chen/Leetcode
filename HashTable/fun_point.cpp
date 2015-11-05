// A simple C program to show function pointers as parameter
/*Function Pointers Summary

	Syntax

	Declaring:
	Declare a function pointer as though you were declaring a function, 
	except with a name like *foo instead of just foo:
	void (*foo)(int);

	Initializing

	You can get the address of a function simply by naming it:
	void foo();
	func_pointer = foo;
	
	or by prefixing the name of the function with an ampersand:
	void foo();
	func_pointer = &foo;
	
	Invoking

	Invoke the function pointed to just as if you were calling a function.
	func_pointer( arg1, arg2 );
	or you may optionally dereference the function pointer before calling the function it points to:
	(*func_pointer)( arg1, arg2 );
*/
#include <stdio.h>

// Two simple functions
void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }

// A function that receives a simple function
// as parameter and calls the function
void wrapper(void (*fun)())
{
	fun();
}

int main()
{
	wrapper(fun1);
	wrapper(fun2);
	return 0;
}

