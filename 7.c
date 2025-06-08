#include<stdio.h>
#include<stdlib.h>
struct node 
{
char ssn[25], name[25], dept[10], designation[25];
int sal;
long int phone;
struct node *llink, *rlink;
};
typedef struct node *NODE;
NODE first = NULL;
int count = 0;
NODE create()
{
NODE enode;
enode = (NODE)malloc(sizeof(struct node));
if (enode == NULL) {
printf("\nRunning out of memory");
exit(0);
}
printf("\nEnter the SSN, Name, Department, Designation, Salary, Phone No of the employee:\n");
scanf("%s %s %s %s %d %ld", enode->ssn, enode->name, enode->dept, enode->designation, &enode->sal, &enode->phone);
enode->llink = NULL;
enode->rlink = NULL;
count++;
return enode;
}
NODE insertfront()
{
NODE temp;
temp = create();
if (first == NULL)
{
return temp;
}
temp->rlink = first;
first->llink = temp;
return temp;
}
void display()
{
NODE cur;
int nodeno = 1;
cur = first;
if (cur == NULL) 
{
printf("\nNo Contents to display in DLL");
return;
}
while (cur != NULL)
{
printf("\nNode %d || SSN: %s | Name: %s | Department: %s | Designation: %s | Salary: %d | Phone: %ld",
nodeno, cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phone);
cur = cur->rlink;
nodeno++;
}
printf("\nTotal number of employee nodes: %d", count);
}
NODE deletefront()
{
NODE temp;
if (first == NULL)
{
printf("\nDoubly Linked List is empty");
return NULL;
}
if (first->rlink == NULL) 
{
printf("\nThe employee node with SSN %s is deleted", first->ssn);
free(first);
count--;
return NULL;
}
temp = first;
first = first->rlink;
first->llink = NULL;
printf("\nThe employee node with SSN %s is deleted", temp->ssn);
free(temp);
count--;
return first;
}
NODE insertend()
{
NODE cur, temp;
temp = create();
if (first == NULL) 
{
return temp;
}
cur = first;
while (cur->rlink != NULL) 
{
cur = cur->rlink;
}
cur->rlink = temp;
temp->llink = cur;
return first;
}
NODE deleteend()
{
NODE cur;
if (first == NULL)
{
printf("\nDoubly Linked List is empty");
return NULL;
}
if (first->rlink == NULL)
{
printf("\nThe employee node with SSN %s is deleted", first->ssn);
free(first);
count--;
return NULL;
}
cur = first;
while (cur->rlink != NULL) 
{
cur = cur->rlink;
}
printf("\nThe employee node with SSN %s is deleted", cur->ssn);
cur->llink->rlink = NULL;
free(cur);
count--;
return first;
}
void deqdemo()
{
int ch;
while (1)
{
printf("\nDemo Double-Ended Queue Operations");
printf("\n1: Insert at Front\n2: Delete from Front\n3: Insert at Rear\n4: Delete from Rear\n5: Display\n6: Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: first = insertfront(); break;
case 2: first = deletefront(); break;
case 3: first = insertend(); break;
case 4: first = deleteend(); break;
case 5: display(); break;
case 6: return;
default: printf("\nInvalid choice, try again.");
}
}
}
int main()
{
int ch, n, i;
while (1) {
printf("\n\n~~~ Menu ~~~");
printf("\n1: Create DLL of Employee Nodes");
printf("\n2: Display");
printf("\n3: Insert at End");
printf("\n4: Delete from End");
printf("\n5: Insert at Front");
printf("\n6: Delete from Front");
printf("\n7: Double Ended Queue Demo using DLL");
printf("\n8: Exit\n");
printf("\nPlease enter your choice: ");
scanf("%d", &ch);
switch (ch) 
{
case 1: printf("\nEnter the no of Employees: "); scanf("%d", &n);
for (i = 1; i <= n; i++) first = insertend(); break;
case 2: display(); break;
case 3: first = insertend(); break;
case 4: first = deleteend(); break;
case 5: first = insertfront(); break;
case 6: first = deletefront(); break;
case 7: deqdemo(); break;
case 8: exit(0);
default: printf("\nPlease Enter a valid choice");
}
}
}
