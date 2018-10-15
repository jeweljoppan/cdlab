//program simple lexical analyzer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void main()
{
	FILE *fptr;
	int i=0,k,n,flag;
	char rel[100],c,t[10];
	char key[10][20]={"int","main","void","printf","if","else","for","while"};
	fptr=fopen("rel.txt","r");
	if(fptr== NULL)
	{
		printf("ERROR");
		exit(0);
        }
	c=fgetc(fptr);
	while(c!=EOF)
	{
		n=0;
		flag=0;
		while(isdigit(c))
		{
			n*=10;
			n+=c-'0';
			c=fgetc(fptr);
			flag=1;
		}
		if(flag==1)
		{
			printf("%d : num\n",n);
			continue;
		}
		else if(c =='<')
		{
			c=fgetc(fptr);
			if(c == '=')
			{
				printf("<= : LE\n");
				c=fgetc(fptr);
			}
			else
			{
				printf("< : LT\n");
			}
		}
		else if(c=='>')
                {
			c=fgetc(fptr);
                        if(c=='=')
                        {
                                printf(">= : GE\n");
				c=fgetc(fptr);
                        }
                        else
                        {
                                printf("> : GT\n");
                        }
                }
		else if(c=='!')
                {
			c=fgetc(fptr);
                        if(c=='=')
                        {
                                printf("!= : NE\n");
                                c=fgetc(fptr);
                        }
		}
		else if(isalpha(c))
		{
                	while (isalpha(c))
                	{
                        	t[n]=c;
                        	n++;
				c=fgetc(fptr);
                	}
			t[n]='\0';
                	for(int j=0;j<10;j++)
                	{
                        	if(strcmp(key[j],t)==0)
                        	{
					flag=1;
       	                	        printf("%s : keyword\n",t);
                        	}
			}
			if(flag==0)
			printf("%s : id\n", t);
		}
		else if(c=='"')
		{
			while(c=fgetc(fptr))
				if(c=='"')
				{
					c=fgetc(fptr);
					break;
				}
		}
		else
		{
			c=fgetc(fptr);
		}

	}
}

