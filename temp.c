#include<stdio.h>
#include<stdlib.h>
void main()
{
/*FILE *fptr;
char c;
fptr=fopen("rel.txt","r");
while(c!=EOF)
{
	c=fgetc(fptr);
if(c==' ')
printf("Hello.");
}
if(c==EOF)
	printf("df");
*/

{ 
int size = 4; 

/* Stored in heap segment like other dynamically allocated things */
char *str = (char *)malloc(sizeof(char)*size); 
*(str+0) = 'G'; 
*(str+1) = 'f'; 
*(str+2) = 'G';	 
//*(str+3) = '\0'; 
*(str+1) = 'n'; /* No problem: String is now GnG */
printf("%s \n",str); 
free(str);
printf("jg %s",str);
} 

}
