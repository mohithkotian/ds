#include <stdio.h> 
#include <stdlib.h> 
#define MAX_DAYS 7
struct day 
{ 
char *dayname; 
int date;
char *activity; 
}; 
void create(struct day *calendar) 
{ int i;
for(i=0;i<MAX_DAYS;i++)
{
calendar[i].dayname=(char *)malloc(20*sizeof(char));
calendar[i].activity=(char *)malloc(20*sizeof(char));
}
}
void read(struct day *calendar) 
{ 
int i;
for (i =0;i<MAX_DAYS;i++) 
{ printf("enter the details of day %d\n",i + 1);
printf("enter the day:");
scanf("%s",calendar[i].dayname);
printf("enter the date:");
scanf("%d",&calendar[i].date); 
printf("enter the details of activity:");
scanf("%[^\n]",&calendar[i].activity);
getchar(); 
fgets(calendar[i].activity, 20, stdin);
}}
void display(struct day *calendar) 
{ int i;
printf("%-10s %-10s %-30s\n", "Day", "Date", "Activity description"); 
for (i = 0; i < MAX_DAYS;i++)
{
printf("%-10s %-10d %-30s\n", calendar[i].dayname, calendar[i].date, calendar[i].activity);
}}
void freememory(struct day *calendar)
{
int i;
for (i = 0; i < MAX_DAYS; i++)
{
free(calendar[i].dayname);
free(calendar[i].activity);
}}
int main() 
{int i;
struct day *calendar;
calendar = (struct day *)malloc(MAX_DAYS*sizeof(struct day)); 
if (calendar == NULL) 
{
printf("memory allocation not possible\n"); 
exit(0);}
create(calendar);
read(calendar);
display(calendar);
freememory(calendar);
free(calendar);
return 0;} 
