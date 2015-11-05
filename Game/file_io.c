#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*gets is not safe*/
	/*printf("Enter a value :\n");
	char *str;
	gets(str);

	printf("your input value :\n");
	puts(str);*/

	/*fgets is good*/
	const int bufsize = 8;
	char buf[bufsize];
	printf("Enter your name (size <= 8) here:\n"); 
	fgets(buf, bufsize, stdin);
	printf("your name is :%s\n", buf); 

	/*scanf is not safe but easy to get oneline input*/
	printf("Enter a integer and a string:\n");
	char str2[8];
	int val2;
	scanf("%d %s", &val2, str2);
	printf("you input %d and %s\n", val2, str2); 
	
	return 0;
}
