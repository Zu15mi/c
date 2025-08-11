#include <stdio.h>

#define MAX 80

int main()
{
	char exp[MAX];
	printf("\n Input :");
	scanf("%[^\n]", exp);
	int i, num; 
	int c;
	for(i=0; exp[i]!='\0'; i++)
	
		{
		c=exp[i];
		if(c==' ')
	{
	printf("\nNum=%d", num);
	num=0;		
	}
		num=num*10+ (c-'0');
		}
	printf("\nNum=%d", num);
	return 0;	 
	
}
