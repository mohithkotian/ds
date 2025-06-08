#include <stdio.h> 
void tower(int n,char beg,char aux,char end) 
{ 
if(n==0) 
printf("Illegal, Try with non-zero positive Integers\n"); 
else if(n==1) 
printf("Move disc from %c to %c\n",beg,end); 
else 
{ tower(n-1,beg,end,aux); 
tower(1,beg,aux,end); 
tower(n-1,aux,beg,end); 
}} 
void main()  
{ 
int n; 
char a,b,c; 
printf("Enter the number of discs:\n"); 
scanf("%d",&n); 
printf("Tower of Hanoi for %d discs has the following steps:\n",n); 
tower(n,'a','b','c'); 
}
