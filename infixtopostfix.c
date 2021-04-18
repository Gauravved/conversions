#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversions.h"
int main()
{
	char ch;
	do
	{
		char c[50],post[50];
		printf("Enter the infix expression:");
		scanf("%s",c);
		strcpy(post,prefix(c));
		printf("The postfix expression is: %s",post);
		printf("\n\nDo you want to enter more expressions? [y/n] :");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
