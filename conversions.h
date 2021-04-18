#include <stdio.h>
#include <stdlib.h>
int num=0;
typedef struct Node
{
	char ch;
	int k;
	struct Node *addr;
}node;
void createstack(char,int, char post[]);
char pop(char);
node *top,*temp,*curr,*del;
char* prefix(char c[50])
{
	char cm;
		top=NULL;
		num=0;
		char post[50];
		int i,j,flag=0,n;
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]=='+' || c[i]=='-')
			{
				j=1;
				createstack(c[i],j,post);
			}
			else if(c[i]=='*' || c[i]=='/')
			{
				j=2;
				createstack(c[i],j,post);
			}
			else if(c[i]=='^')
			{
				j=3;
				createstack(c[i],j,post);
			}
			else if(c[i]=='(' || c[i]=='['||c[i]=='{'||c[i]=='<')
			{
				j=0;
				createstack(c[i],j,post);
				n=i;
				if(c[i]=='(')
				{
					while(c[n]!=')')
					{
						if(c[n]=='\0')
						{
							system("CLS");
							printf("The equation %s is incorrect. The bracket is not closed!",c);
							flag=1;
							break;
						}
						n++;
					}
				}
				else if(c[i]=='[')
				{
					while(c[n]!=']')
					{
						if(c[n]=='\0')
						{
							system("CLS");
							printf("The equation %s is incorrect. The bracket is not closed!",c);
							flag=1;
							break;
						}
						n++;
					}
				}
				else if(c[i]=='{')
				{
					while(c[n]!='}')
					{
						if(c[n]=='\0')
						{
							system("CLS");
							printf("The equation %s is incorrect. The bracket is not closed!",c);
							flag=1;
							break;
						}
						n++;
					}
				}
				else if(c[i]=='<')
				{
					while(c[n]!='>')
					{
						if(c[n]=='\0')
						{
							system("CLS");
							printf("The equation %s is incorrect. The bracket is not closed!",c);
							flag=1;
							break;
						}
						n++;
					}
				}
			}
			else if(c[i]==')'||c[i]==']'||c[i]=='}'||c[i]=='>')
			{
				if(c[i]==')')
				{
					while(top->ch!='(')
					{
						post[num]=pop(top->ch);
						num++;
						if(top==NULL)
						{
							break;
						}
					}
				}
				else if(c[i]==']')
				{
					while(top->ch!='[')
					{
						post[num]=pop(top->ch);
						num++;
						if(top==NULL)
						{
							break;
						}
					}
				}
				else if(c[i]=='}')
				{
					while(top->ch!='{')
					{
						post[num]=pop(top->ch);
						num++;
						if(top==NULL)
						{
							break;
						}
					}
				}
				else if(c[i]=='>')
				{
					while(top->ch!='<')
					{
						post[num]=pop(top->ch);
						num++;
						if(top==NULL)
						{
							break;
						}
					}
				}
				if(top==NULL)
				{
					system("CLS");
					printf("The equation %s is incorrect. Closing bracket without a opening bracket",c);
					flag=1;
				}
				else
				{
					pop(top->ch);
					flag=0;
				}
			}
			else
			{
				post[num]=c[i];
				num++;
			}
		}
		while(top!=NULL)
		{
			post[num]=pop(top->ch);
			num++;
		}
		if(flag!=1)
		{
			for(i=0;i<num;i++);
			post[i]='\0';
		}
	return post;
}
void createstack(char c,int j,char post[])
{
	char n;
	temp=malloc(sizeof(struct Node));
	temp->ch=c;
	temp->k=j;
	temp->addr=top;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		if(j!=0)
		{
			while(top!=NULL)
			{
				if(top->k >= temp->k)
				{
					n=top->ch;
					post[num]=pop(n);
					num++;
				}
				else
				{
					break;
				}
			}
		}
		temp->addr=top;
		top=temp;
	}
}
char pop(char c)
{
	curr=top;
	top=top->addr;
	if(curr->ch!='(')
	{
		return (curr->ch);	
	}	
	free(curr);
}
