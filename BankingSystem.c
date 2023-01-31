#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct customer
{
    char name[100];
    char accNo[10];
    char mobileNo[11];
    double balance;
} cust;

int numCustomers;

void depositMoney(char acc[10], cust *p, double amount)
{
    for(int i=0; i<numCustomers; i++)
    {
        p = p+i;
        if(!strcmp(acc, p->accNo))
        {
            p->balance= amount;
        }
    }
    
}

void main()
{
    
    scanf("%d", &numCustomers);

    if(numCustomers<=0 || numCustomers>100)
    {
        return;
    }
    printf("%d", numCustomers);

    cust *ptr;
    ptr = (cust*)calloc(numCustomers, sizeof(cust));

    for(int i=0; i<numCustomers; i++)
    {
        ptr = ptr+i;
        printf("Enter name: ");
        fflush(stdin);
        gets(ptr->name);
        printf("Enter account number: ");
        scanf("%s", ptr->accNo);
        printf("Enter mobile no: ");
        scanf("%s", ptr->mobileNo);
        printf("Enter balance: ");
        scanf("%lf", &ptr->balance);

    }

    ptr = ptr-(numCustomers-1);

    int option; char acc[10];
    while(1)
    {
        printf("Please select an option- /nChoose 1 to deposit money. /nChoose 2 to withdraw money. /nChoose 3 to sort all customers using their salary. /nChoose 4 to search customers by using their mobileNo. /nChoose 5 to print all the customers. /nChoose 6 to print the sum Of all customer balances. /nChoose 0 to exit.  /nEnter you option: ");

        scanf("%d", &option);
        if(option==0)
        {
            break;
        }

        switch (option)
        {
        case 1: 
        printf("Enter account number: ");
        scanf("%s", acc);
        double amount;
        printf("Enter the balance: ");
        scanf("%lf", &amount);
        depositMoney(acc, ptr, amount);

            break;

        case 2: 
        
        default:
            break;
        }

    }
}