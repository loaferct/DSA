#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct list
{
    int info;
    struct list *next;
};
typedef struct list node;
node *front = NULL;
node *rear = NULL;

void enqueue();
void dequeue();
void display_queue();

int main()
{
    int option_status = 1;
    int choose;
    while (option_status)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit\n");
        printf("Choose your Option: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display_queue();
            break;

        case 4:
            option_status = 0;
            printf("EXITED!!!!\n");
            break;

        default:
            printf("Invalid Option\n");
        }
    }
    return 0;
}

void enqueue()
{
    node *item;
    item = (node *)malloc(sizeof(node));
    printf("Enter the data to be Enqueued: ");
    scanf("%d", &item->info);
    item->next = NULL;

    if (rear == NULL)
    {
        front = rear = item;
    }
    else
    {
        rear->next = item;
        rear = item;
    }
}

void dequeue()
{
    node *ptr;
    if (front == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        ptr = front;
        front = front->next;
        printf("The dequeued element is %d\n", ptr->info);
        free(ptr);

        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

void display_queue()
{
    node *temp;
    printf("The elements of the queue are: \n");
    temp = front;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
