#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct list 
{
    int info;
    struct list *next;
};
typedef struct list node;
node *ptr, *start = NULL;

void push();
void pop();
void display();
void search();

int main()
{
    int option_status = 1;
    int choose;
    while (option_status)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\n");
        printf("\nChoose your Option: ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                push();
            break;

            case 2:
                pop();
            break;

            case 3:
                display();
            break;

            case 4:
                search();
            break;
            
            case 5:
                option_status = 0;
                printf("EXITED!!!!\n");
            break;

            default:
                printf("Invalid Option\n");
        }
    }
    return 0;
}

void push()
{
    node *item,*temp;
    item = (node*)malloc(sizeof(node));
    printf("Enter the data to be Inserted: ");
    scanf("%d",&item->info);
    item->next = NULL;

    if (start == NULL)
    {
        start = item;
    }

    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = item;
    }

}

void pop()
{
    node *ptr,*loc;

    if(start == NULL)
    {
        printf("The list is empty\n");
    }

    else if(start->next == NULL)
    {
        printf("The deleted element is %d\n",start->info);
    }

    else
    {
        ptr = start;
    
        while(ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }

        loc->next = NULL;
        printf("The deleted element is %d\n",ptr->info);
        free(ptr);
    }
}

void display()
{
    node *temp;
    printf("The elements of linked list are: \n");
    temp = start;
    while(temp != NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

void search()
{
    node *temp;
    int num, count = 0;
    printf("Enter a number to be searched: ");
    scanf ("%d",&num);
    temp = start;
    do
    {
        count++;
        
        if (temp->info == num)
        {
            printf("The number is at %d postion\n",count);
            getch();
            temp = NULL;
            return;
        }

        else
        {
            temp = temp->next;
        }

    } while(temp != NULL);
    printf("\nThis number doesnt exist in the list\n");
}