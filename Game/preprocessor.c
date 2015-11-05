#include <stdio.h>
#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)

int main()
{
    /*preprocessor but not compiler */
    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );

	printf("%s\n",h(f(1,2)));
	printf("%s\n",g(f(1,2)));
	return 0;
}
