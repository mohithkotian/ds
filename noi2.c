#include<stdio.h>
char str[50],pat[50],rep[50],ans[50];
void read()
{
printf("enter the main string:");
scanf("%[^\n]",str);
getchar();
printf("enter the pattern string:");
scanf("%[^\n]",pat);
getchar();
printf("enter the replace string:");
scanf("%[^\n]",rep);
}
void searchreplace()
{
int i,j,m,c,k,flag=0;
i=j=m=c=0;
while(str[c]!='\0')
{
if(str[m]==pat[i])
{i++;
m++;
if(pat[i]=='\0'){
flag=1;
for(k=0;rep[k]!='\0';k++,j++)
ans[j]=rep[k];
c=m;
i=0;
}}
else{
ans[j]=str[c];
j++;
c++;
m=c;
i=0;
}}
if(flag==1)
{printf("pattern found\n");
ans[j]='\0';
printf("%s",ans);}
else
{printf("pattern not found\n");
}}
void main()
{
read();
searchreplace();}
