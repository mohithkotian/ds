#include <stdio.h> 
#include<math.h> 
#include<string.h> 
float compute(char symbol,float op1,float op2) 
{ switch(symbol) 
{ 
case '+': return op1+op2; 
break; 
case '-': return op1-op2; 
break; 
case '*': return op1*op2; 
break; 
case '/': return op1/op2; 
break; 
case '$': return op1+op2; 
break; 
default: return 0; }} 
void main() { 
float s[20],res,op1,op2; 
int top,i;
char postfix[50],op1,op2;
printf("enter the postfix expression");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++;)
{
symbol=postfix[i];
if (isdigit(symbol))
s[++top]=symbol-'0';
else 
{ 
op2=s[top--]; 
op1=s[top--]; 
res=compute(symbol,op1,op2); 
s[++top]=res; 
} 
} 
res=s[top--]; 
printf("The result is %f",res); 
} 
