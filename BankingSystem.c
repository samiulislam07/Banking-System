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
cust *ptr;

void depositMoney(char acc[10], double amount)
{
    for(int i=0; i<numCustomers; i++)
    {
        if(strcmp(acc, (ptr+i)->accNo)==0)
        {
            (ptr+i)->balance += amount;
            break;
        }
    }

}

void withdrawMoney(char acc[10], double amount)
{
    for(int i=0; i<numCustomers; i++)
    {
        if(strcmp(acc, (ptr+i)->accNo)==0)
        {
            (ptr+i)->balance= (ptr+i)->balance - amount;
            break;
        }
    }
}

void searchCustomer(char mbl[11])
{
    for(int i=0; i<numCustomers; i++)
    {
        if(strcmp(mbl, (ptr+i)->mobileNo)==0)
        {
            printf("\n\nName: %s\nAccount No: %s\n Balance: %lf\n\n", (ptr+i)->name, (ptr+i)->accNo, (ptr+i)->balance);
            break;
        }
    }
}

void printCustomers()
{
    for(int i=0; i<numCustomers; i++)
    {
        printf("Name: ");
        puts((ptr+i)->name);
        printf("\tAccount No: ");
        puts((ptr+i)->accNo);
        printf("\tMobile No: ");
        puts((ptr+i)->mobileNo);
        printf("\tBalance: %lf\n\n", (ptr+i)->balance);
    }
}

void sumBalance()
{
    double sum=0;

    for(int i=0; i<numCustomers; i++)
    {
        sum += (ptr+i)->balance;
    }

    printf("\n\n\nSum of all balances: %lf\n\n\n", sum);
}

void sortCustomers()
{
    int flag;
    cust temp;
    for(int i=0; i<numCustomers-1; i++)
    {
        flag=0;
        for(int j=0; j<numCustomers-1-i; j++)
        {
            if((ptr+i)->balance < (ptr+i+1)->balance)
            {
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+i+1);
                *(ptr+i+1) = temp;
                flag=1;
            }
            else if((ptr+i)->balance == (ptr+i+1)->balance)
            {
                if((ptr+i)->accNo < (ptr+i+1)->accNo)
                {
                    temp = *(ptr+i);
                    *(ptr+i) = *(ptr+i+1);
                    *(ptr+i+1) = temp;
                    flag=1;
                }
            }
        }
        if(flag==0) break;
    }



    for(int i=0; i<numCustomers; i++)
    {
        printf("Name: %s\nAccount No: %s\nMobile no: %s\nBalance: %lf\n\n", (ptr+i)->name, (ptr+i)->accNo, (ptr+i)->mobileNo, (ptr+i)->balance);
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

    ptr = (cust*)calloc(numCustomers,sizeof(cust));

    for(int i=0; i<numCustomers; i++)
    {
        printf("Enter name: ");
        fflush(stdin);
        gets((ptr+i)->name);
        printf("Enter account number: ");
        fflush(stdin);
        gets((ptr+i)->accNo);
        printf("Enter mobile no: ");
        fflush(stdin);
        gets((ptr+i)->mobileNo);
        printf("Enter balance: ");
        scanf("%lf", &(ptr+i)->balance);
        printf("\n");
    }

    int option;
    char acc[10], mbl[11];
    double amount;
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
        depositMoney(acc, amount);

            break;

        case 2:
        printf("Enter account number: ");
        scanf("%s", acc);
        printf("Enter the amount to be withdrawn: ");
        scanf("%lf", &amount);
        withdrawMoney(acc, amount);

        break;

        case 3:
        sortCustomers();

        break;

        case 4:
        printf("Enter mobile number: ");
        scanf("%s", mbl);
        searchCustomer(mbl);


        break;


        case 5:
        printCustomers();


        break;


        case 6:
        sumBalance();

        break;

        default: printf("Enter correct option\n");
            break;
        }

    }
}
