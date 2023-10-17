#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.h"



// struct account to contain all accounts' data
typedef struct account
{
    u32 name[50];
    u32 address[100];
    u32 ID;
    u32 age;
    u32 guardian_id;
    u32 status;
    u32 balance;
    u32 password;
    struct account* next;

}account;

u32  window_select(u32 win);
u32  admin_window ();
u32 client_window(u32 id,u32 pass);
u32  check_id(u32 id_to_check);
account* search_by_id(u32 id_to_search);
void create_account(account *acc);
u32 check_status(account* x);
void transaction (u32 other_id,u32 money,account* first_acc);
u32  Existing_account();
void withdraw_cash(u32 money,account* dummy);
void deposit_cash(u32 money,account* dummy);
void Change_status(account *acc);
void change_password(u32 id);




account* headptr = NULL; // head pointer of linked list
account* search;
account* crt;

// user choosing window
u32 window_select(u32 win)
{
    switch (win)
    {
        case 1:
        {
            printf("Admin Window:\n");
            return 1;
            break;
        }

        case 2:
        {
            printf("client Window:\n");
            return 2;
            break;
        }
        
        case 3:
        {
            printf("Program closed\n");
            return 0;
            break;
        }

        default:
        {
            printf("Wrong Entery Please try again\n");
            return 3;
            break;
        }
                
    }
}

// admin window
u32 admin_window ()
{
    u8 admin_username[] = "admin"; // admin username and password
    u32 admin_password;
    u8 username[6] ;                // username entered

    printf("Please enter username: \n");
    scanf ("%s",username);
    printf("Please enter Password: \n");
    scanf ("%d",&admin_password);
    
    // check for entered username and password validity

    if (strcmp(username,admin_username) == 0 && admin_password == 123)
    {
        return 1;
    }
    else
    {
        printf("Wrong user name or password\n");
        return 0;
    }
}

// creat new account
void create_account(account *acc)
{
    // Admin entering customer data

    printf("Enter Full name: ");    
    scanf (" %[^\n]s",&(acc->name));
    //printf("%s\n",acc->name);

    printf("Enter Full address: ");
    scanf (" %[^\n]s",&(acc->address));
    //printf("%s\n",acc->address);

    printf("Enter age: ");
    scanf ("%d",&(acc->age));
    //printf("%d\n",acc->age);

    printf("Enter ID: ");
    scanf ("%d",&(acc->ID));
    //printf("%d\n",acc->ID); 
    u8 exists = check_id(acc->ID);
    if(exists == 1)
    {
        printf("This id is already taken");
        return ;
    }
    else
    {
        if (acc->age < 21)
        {
        printf("Enter gaurdian id: ");
        scanf ("%d",&(acc->guardian_id));
        //printf("%d\n",acc->guardian_id);
        }
        else 
        {
            acc->guardian_id = 0 ;
        }

        printf("Enter Balance: ");
        scanf ("%d",&(acc->balance));
        //printf("%d\n",acc->balance);

        acc->password = (1000+(rand()%(2000-1000)));    // random generated password between 1000-2000
        printf("Your password is : %d\n",acc->password);
        printf("\n");

        acc ->status = 1; // at first account is status set to active by default

        // adding account to linked list

        if(headptr == NULL) 
        {
            headptr = acc;
            acc ->next = NULL;
        }
        else
        {
            account* current = headptr; 

            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = acc;
            acc->next = NULL;
        }
    }

}

//Checks id validity

u32 check_id(u32 id_to_check)
{
    crt = headptr;
    while(crt != NULL && crt->ID != id_to_check)
    {
        crt = crt->next;
    }
    if(crt == NULL)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

account* search_by_id(u32 id_to_search)
{
    search = headptr;
    while (search->ID != id_to_search)
    {
        search = search->next;
    }
    return search;
}

u32 check_status(account* x)
{
    if (x->status == 1)
    {
        return 1;   // active account
    }
    else if (x->status == 2)
    {
        return 2;   // restricted account
    }
    else
    {
        return 0;  // closed account
    }
}
//accessing an existing account using account id

u32 Existing_account()
{
        u32 choose;
        u32 id;
        account* dummy = headptr;
        
        printf("Please Enter account ID: ");
        scanf("%d",&id);
        printf("\n");

        if(headptr == NULL)
        {
            printf("No accounts\n");
            return 0;
        }

        u32 k = check_id(id);
        
        if(k==0)
        {
            printf("Wrong ID! Please try again\n");
            Existing_account();
        }
        else
        {
            while (k==1)
            {
                printf("\n");
                printf("Choose action :\n");
                printf("\n");
                printf("1. Make a transaction\n");
                printf("2. Change account status\n");
                printf("3. Get cash\n");
                printf("4. Deposit in account\n");
                printf("5. Return to main menu\n");

                scanf("%d",&choose);
                switch (choose)
                {
                    case 1:
                    {
                        u32 other_id;
                        u32 money;

                        printf("Please enter the id of the other account: ");
                        scanf ("%d",&other_id);
                        printf("Enter amount of money to transfer: ");
                        scanf ("%d",&money);
                        transaction(other_id,money,dummy);
                        break;
                    }
                    case 2:
                    {
                        printf("Change Account status:\n");
                        account* Acc = search_by_id (id);
                        //printf("status = %d\n",Acc->status);
                        Change_status(Acc);
                        //printf("status = %d\n",Acc->status);
                        break;
                    }

                    case 3:
                    {
                        u32 money;
                        printf("Enter amount of cash to withdraw: ");
                        scanf ("%d",&money);
                        withdraw_cash(money,dummy);
                        break;
                    }
                    
                    case 4:
                    {
                        u32 money;
                        printf("Enter amount of cash to deposit: ");
                        scanf ("%d",&money);
                        deposit_cash(money,dummy);
                        break;
                    }
                    case 5:
                    {
                        k=0;
                        break;
                    }
                }
            }
        }
}




void transaction (u32 other_id,u32 money,account* first_acc)
{
    u32 ret = check_id (other_id);
    if (ret == 0)
    {
        printf("invalid id\n");
        return;
    }
    else if(money > first_acc->balance)
    {
        printf("insufficient Cash amount\n");
    }
    else 
    {
        account* Acc1 = search_by_id(other_id);
        u32 c1 = check_status(Acc1);
        u32 c2 = check_status(first_acc);
        if(c1 != 1 || c2 != 1)
        {
            printf("One of the accounts is not active\n");
        }
        else
        {
            //  printf("%d\n",x->balance);
            //  printf("%d\n",Acc->balance);

            first_acc->balance = (first_acc->balance) - money ;
            search->balance = (Acc1->balance) + money;

            //  printf("%d\n",x->balance);
            //  printf("%d\n",Acc1->balance);
            printf("Successfull transaction!\n");
        }
    
    }
}

void withdraw_cash(u32 money,account* dummy)
{
    u32 c = check_status(dummy);
    if (c == 1)
    {
        if(dummy->balance >= money)
        {
            dummy->balance = (dummy->balance) - money;
            printf("Successfull withdraw\n");
        }
        else
        {
            printf("insufficient Cash amount\n");
        }
    }
    else
    {
        printf("Your account is not active\n");
    }
    
}

void deposit_cash(u32 money,account* dummy)
{   
    u32 c = check_status(dummy);
    if (c == 1)
    {
        dummy->balance = (dummy->balance) + money;
        printf("Successfull deposit\n");
    }
    else
    {
        printf("Your account is not active\n");
    }
}

void Change_status(account *acc)
{
    u32 new_status;
    u8 x=0;
    u8* string = (u8*) malloc (20);

    if (acc->status == 1)
    {
        string = "Active";
    }
    else if (acc->status == 2)
    {
        string= "Restricted";
    }
    else
    {
        string = "Closed";
    }
    while (x==0)
    {
        printf("Current account status is: %s\n",string);

        printf("1. Change to active\n");
        printf("2. Change to restricted\n");
        printf("3. Change to closed\n");
        scanf("%d",&new_status);

        switch(new_status)
        {
            case 1:
            {
                acc->status = 1;
                x=1;
                break;
            }
            case 2:
            {
                acc->status = 2;
                x=1;
                break;
            }
            case 3:
            {
                acc->status = 0;
                x=1;
                break;
            }
            default:
            {
                printf("Invalid input please try again\n");
                x=0;
                break;
            }
        }
    }
}


u32 client_window(u32 id,u32 pass)
{
    u32 check;
    account* acc;

    if(headptr == NULL)
    {
        printf("No Account Exists\n");
    }
    else
    {
        check = check_id(id);
        if(check == 1)
        {
            acc = search_by_id(id);
            if(acc->password == pass)
            {
                return 1;
            }
            else
            {
                printf("Wrong password\n");
                return 0;
            }
        }
        else
        {
            printf("Invalid ID");
            return 0;
        }
    }

}

void change_password(u32 id)
{
    account* acc;
    u32 password;
    u32 new_password;

    acc = search_by_id(id);
    printf("please enter your current password:\n");
    scanf ("%d",&password);

    if(acc->password == password)
    {
        printf("Please enter your new only numbers password :");
        scanf("%d",&new_password);
        acc->password = new_password;
    }
    else 
    {
        printf("Wrong password\nPlease try again\n");
    }

}