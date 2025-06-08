#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int ch, front = 0, rear = -1, count = 0;
char q[MAX], item;

void insert() 
{
    if (count == MAX)
    {
        printf("\nQueue is Full");
    } 
    else 
    {
        rear = (rear + 1) % MAX; // Move rear to the next position circularly
        q[rear] = item;
        count++;
    }
}

void del()
{
    if (count == 0) 
    {
        printf("\nQueue is Empty");
    } 
    else
    {
        item = q[front];
        printf("\nDeleted item is: %c", item);
        front = (front + 1) % MAX; // Move front to the next position circularly
        count--;
    }
}

void display() 
{
    if (count == 0)
    {
        printf("\nQueue is Empty");
    }
    else 
    {
        printf("\nContents of Queue:\n");
        for (int i = 0; i < count; i++) {
            printf("%c\t", q[(front + i) % MAX]);
        }
    }
}

int main() {
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:printf("\nEnter the character / item to be inserted: ");scanf(" %c", &item); 
                insert();break;
            case 2:del();break;
            case 3:display();break;
            case 4:exit(0);
            default: printf("\nInvalid choice, try again.");
        }
    } while (ch != 4);

    return 0;
}
