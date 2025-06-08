#include <stdio.h>
#include <stdlib.h>
#define size 5
int s[size];
int top = -1;
void push() 
{
int item;
if (top == size - 1) {
printf("Stack Overflow\n");
return;
}
printf("Enter an item: ");
scanf("%d", &item);
s[++top] = item;
}
void pop()
{
if (top == -1) {
printf("Stack Underflow\n");
return;
}
printf("Deleted item = %d\n", s[top--]);
}
void palindrome()
{
int flag = 1, i;
if (top == -1) {
printf("Stack is empty\n");
return;
}
printf("Stack contents are:\n");
for (i = top; i >= 0; i--)
printf("%d\t", s[i]);
printf("\n");
for (i = 0; i <= top / 2; i++) {
if (s[i] != s[top - i]) {
flag = 0;
break;
}}
if (flag == 1)
printf("It is a palindrome\n");
else
printf("It is not a palindrome\n");
}
void display() 
{
int i;
if (top == -1) {
printf("Stack is empty (Underflow)\n");
return;
}
printf("Contents of the stack are:\n");
for (i = top; i >= 0; i--)
printf("%d\n", s[i]);
}
int main() 
{
int ch;
while (1) {
printf("\n1. Push\n2. Pop\n3. Palindrome\n4. Display\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:push();break;
case 2:pop();break;
case 3:palindrome(); break;
case 4:display();break;
case 5:exit(0);
default:printf("Invalid choice\n");
}}
return 0;
}
