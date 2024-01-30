#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct list 
{
    int info;
    struct list *next;
};
typedef struct list node;
node *ptr, *start;

void insert_at_beginning();
void insert_at_end();
void insert_at_sp_position();
void delete_first();
void delete_last();
void delete_sp_position();
void display();
void search();

int main()
{
    int option_status = 1;
    int choose;
    while (option_status)
    {
        printf("1.Insert at beginnning\n2.Insert at End\n3.Insert at specific Position\n4.Delete first node\n5.Delete last node\n6.Delete at specific postion\n7.Display all Elements\n8.Search\n9.Exit");
        printf("\nChoose your Option: ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                insert_at_beginning();
            break;

            case 2:
                insert_at_end();
            break;

            case 3:
                insert_at_sp_position();
            break;

            case 4:
                delete_first();
            break;

            case 5:
                delete_last();
            break;

            case 6:
                delete_sp_position();
            break;

            case 7:
                display();
            break;

            case 8:
                search();
            break;
            
            case 9:
                option_status = 0;
                printf("EXITED!!!!\n");
            break;

            default:
                printf("Invalid Option\n");
        }
    }
    return 0;
}

void insert_at_beginning()
{
    node *item;
    item = (node*)malloc(sizeof(node));
    printf("Enter the data to be Inserted: ");
    scanf("%d",&item->info);
    
    if(start==NULL)
    {
        start = item;
        item->next = NULL;
    }

    else
    {
        item->next = start;
        start = item;
    }
}

void insert_at_end()
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

void insert_at_sp_position()
{
    int count = 1, position;
    node *item, *temp;
    temp = start;
    item = (node*)malloc(sizeof(node));
    printf("Enter the position to place the data: ");
    scanf("%d",&position);
    printf("Enter the data to be Inserted: ");
    scanf("%d",&item->info);
    while(count<position)
    {
        temp = temp->next;
        count++;
    }
    item->next = temp->next;
    temp->next = item;
}

void delete_first()
{
    node *ptr;
    if(start == NULL)
    {
        printf("The list is empty.\n");
    }

    else if(start->next == NULL)
    {
        printf("The deleted element is %d\n",start->info);
        ptr = start;
        free(ptr);
        start = NULL;
    }

    else
    {
        ptr = start;
        start = start->next;
        printf("The deleted element is %d\n",ptr->info);
        free(ptr);
    }
}

void delete_last()
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

void delete_sp_position()
{
    node *ptr, *temp;
    int n, count = 1;
    if (start == NULL)
    {
        printf("Empty list\n");
    }

    else
    {
        printf("Enter a postion: ");
        scanf("%d", &n);
        ptr = start;
        while(count < n)
        {
            count++;
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        printf("The deleted element is:%d\n",temp->info);
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
        
