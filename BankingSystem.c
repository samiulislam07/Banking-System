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
            p->balance += amount;
            break;
        }
    }
    
}

void withdrawMoney(char acc[10], cust *p, double amount)
{
    for(int i=0; i<numCustomers; i++)
    {
        p = p+i;
        if(!strcmp(acc, p->accNo))
        {
            p->balance= p->balance - amount;
        }
    }
}

void searchCustomer(char mbl[11], cust *p)
{
    for(int i=0; i<numCustomers; i++)
    {
        p = p+i;
        if(!strcmp(mbl, p->mobileNo))
        {
            printf("Name: %s\nAccount No: %s\n Balance: %lf\n\n", p->name, p->accNo, p->balance);
        }
    }
}

void printCustomers(cust *p)
{
    for(int i=0; i<numCustomers; i++)
    {
        p = p+i;
        
        printf("Name: %s, Account No: %s, Mobile no: %s, Balance: %lf\n\n", p->name, p->accNo,p->mobileNo, p->balance);
        
    }
}

void sumBalance(cust *p)
{
    double sum=0;
    
    for(int i=0; i<numCustomers; i++)
    {
        p = p+i;
        
        sum += p->balance;
        
    }

    printf("Sum of all balances: %lf\n\n\n", sum);
}

void sortCustomers(cust *p)
{
    int flag;
    cust temp; cust *ptr = p;
    for(int i=0; i<numCustomers-1; i++)
    {
        ptr = ptr+i;
        flag=0;
        for(int j=0; j<numCustomers-1-i; j++)
        {
            if(ptr->balance < (ptr+1)->balance)
            {
                temp = *ptr;
                *ptr = *(ptr+1);
                *(ptr+1) = temp;
                flag=1;
            }
            else if(ptr->balance == (ptr+1)->balance)
            {
                if(ptr->accNo < (ptr+1)->accNo)
                {
                    temp = *ptr;
                    *ptr = *(ptr+1);
                    *(ptr+1) = temp;
                    flag=1;
                }
            }
        }
        if(flag==0) break;
    }

    

    for(int i=0; i<numCustomers; i++)
    {
        p = p+i;
        
        printf("Name: %s\nAccount No: %s\nMobile no: %s\nBalance: %lf\n\n", p->name, p->accNo,p->mobileNo, p->balance);
        
    }

}

void main()
{
    
    printf("Enter number of customers: ");
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

    int option; char acc[10], mbl[11]; double amount;
    while(1)
    {
        printf("Please select an option- \nChoose 1 to deposit money. \nChoose 2 to withdraw money. \nChoose 3 to sort all customers using their salary. \nChoose 4 to search customers by using their mobileNo. \nChoose 5 to print all the customers. \nChoose 6 to print the sum Of all customer balances. \nChoose 0 to exit.  \nEnter you option: ");

        scanf("%d", &option);
        if(option==0)
        {
            free(ptr);
            break;
        }

        switch (option)
        {
        case 1: 
        printf("Enter account number: ");
        scanf("%s", acc);
        printf("Enter the balance: ");
        scanf("%lf", &amount);
        depositMoney(acc, ptr, amount);

            break;

        case 2: 
        printf("Enter account number: ");
        scanf("%s", acc);
        printf("Enter the amount to be withdrawn: ");
        scanf("%lf", &amount);
        withdrawMoney(acc, ptr, amount);

        break;

        case 3:
        sortCustomers(ptr);

        break;

        case 4:
        printf("Enter mobile number: ");
        scanf("%s", mbl);
        searchCustomer(mbl, ptr);


        break;

        
        case 5:
        printCustomers(ptr);
        

        break;

        
        case 6:
        sumBalance(ptr);

        break;
        
        default: printf("Enter correct option\n");
            break;
        }

    }
}