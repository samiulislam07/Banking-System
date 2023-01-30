#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct customer
{
    char name[100];
    int accNo[10];
    int mobileNo[11];
    double balance;
} cust;

void main()
{
    int numCustomers;
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
}