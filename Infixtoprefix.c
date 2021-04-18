#include "conversions.h"
#include <string.h>
int main() 
{
	char ch;
	do
	{
		system("CLS");
		char c[50],p[50];
		int i,j;
		printf("Enter the infix Expression:");
		scanf("%s",c);
		strrev(c);
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]=='(' || c[i]=='['||c[i]=='{'||c[i]=='<')
			{
				if(c[i]=='(')
				{
					c[i]=')';
				}
				else if(c[i]=='[')
				{
					c[i]=']';
				}
				else if(c[i]=='{')
				{
					c[i]='}';
				}
				else if(c[i]=='<')
				{
					c[i]='>';
				}
			}
			else if(c[i]==')'||c[i]==']'||c[i]=='}'||c[i]=='>')
			{
				if(c[i]==')')
				{
					c[i]='(';
				}
				else if(c[i]==']')
				{
					c[i]='[';
				}
				else if(c[i]=='}')
				{
					c[i]='{';
				}
				else if(c[i]=='>')
				{
					c[i]='<';
				}
			}
		}
		strcpy(p,prefix(c));
		strrev(p);
		printf("The prefix expression is: %s\n",p);
		printf("\nDo you want to enter more expressions?[y/n]:");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
