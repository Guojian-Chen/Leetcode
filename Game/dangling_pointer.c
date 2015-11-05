#include<stdio.h>

int main()
{
	int *ptr = NULL;
	{
		int x = 10;
		ptr = &x;
	}
	printf("ptr is %p, and value is %d\n", (void*)ptr, *ptr);
	printf("ptr is 0x%x, and value is %d\n", (unsigned int)ptr, *ptr);
}
