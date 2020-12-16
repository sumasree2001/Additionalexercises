#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int is_datatype(char * str)
{
  char* dts[5]={"int","char","float","double","unsigned int"};
  for(int i=0;i<5;i++)
  {
    if(strcmp(str,dts[i])==0)return 1;
   }
   return 0;
 }
  
void check(char * str)
{
  char fword[100];//to capture datatype
  int i=0,p=0;
  while(str[i] != ' ')
  {
    fword[p++]=str[i++];
   }
   fword[p]='\0';
   i++;
   if(is_datatype(fword))
   {
      char fname[100];//to store func name
	  int l=0;
	  while(isalpha(str[i]))
	  {
	    fname[l++]=str[i++];
	   }
	   fname[l]='\0';
	   if(str[i]=='(')
	   {
	     printf("datatype=%s\t",fword);
		 printf("fname=%s\t",fname);
		 i++;
		 int count=0;
		 while(str[i]!=')')
		 {
		    if(str[i]==',')
			  count++;
			i++;
		  }
		  if(count>0)
		  printf("no of arg=%d\n",count+1);
	      else
		  printf("no of arg=%d\n",count);
		} 
   }
 }
int main()
{
   char filename[100];
   printf("enter file name");
   scanf("%s",filename);
   FILE * fp1=fopen(filename,"r");
   char buf[2048];
   while(fgets(buf,2048,fp1)!= NULL)
     {
		check(buf);
	  }
}
		    