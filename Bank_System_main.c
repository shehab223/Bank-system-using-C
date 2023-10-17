/*********************************************
 * Author:				   Shehab Mohamed 
 * Creation Data:		 9 Sep, 2023
 * Version:				   v1.2
 * Compiler:			   GCC
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.2		  09 Sep, 2023	  Shehab Mohamed	         Final Program
*********************************************/

#include <stdio.h>
#include "STD_TYPES.h"
#include "FUNC.h"



void main (void)
{
    u32 select;
    u32 win = 3;
    u32 adm;
    u32 adm_window;
    u32 choose;
    u32 id;
    u32 client;

    printf("Welcome to IMT Bank\n");
    printf("\n");
    while (win == 3)
    {
        printf("Please select: \n");
        printf("1. Admin Window\n");
        printf("2. Client Window\n");
        printf("3. Exit program\n");
        printf("\n");
        
        scanf ("%d",&select);
        win = window_select(select);

        if (win == 1)
        {
            adm = admin_window();
            if (adm == 0)
            {
                printf("TRY AGAIN\n");
                printf("\n");
                win =3;
            }
            else
            {
                u8 k=1;
                while (k==1)
                {
                    printf("\n");
                    printf("Choose Action to perform:\n");
                    printf("\n");
                    printf("1. Create new account\n");
                    printf("2. Open Existing account\n");
                    printf("3. Exit system\n");
                    printf("\n");
                    scanf ("%d",&adm_window);

                    switch (adm_window)
                    {
                        case 1:
                        {
                            account* acc = (account*) malloc(sizeof(account));
                            create_account(acc);
                            break;
                        }
                        case 2:
                        {
                            Existing_account();  
                            break;
                        }
                        default :
                        {
                            k=0;
                            win = 3;
                            break;
                        }

                    }
                }
            }
        }
        else if (win == 2)
        {
            u32 pass;

            printf("Enter account id:\n");
            scanf ("%d",&id);
            printf("Enter your password:\n");
            scanf ("%d",&pass);

            client = client_window(id,pass);

            if(client == 0)
            {
                printf("TRY AGAIN\n");
                printf("\n");
                win =3;   
            }
            else if (client == 1)
            {
                account* user_acc;
                user_acc = search_by_id(id);
                u8 k=1;
                while (k==1)
                {
                    printf("\n");
                    printf("Hi %s",user_acc->name);
                    printf("\n");
                    printf("Your cuurent balance = %d",user_acc->balance);
                
                    printf("\n");
                    printf("Choose action :\n");
                    printf("\n");
                    printf("1. Make a transaction\n");
                    printf("2. Change account password\n");
                    printf("3. Get cash\n");
                    printf("4. Deposit in account\n");
                    printf("5. Return to main menu\n");
                    printf("\n");
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
                            transaction(other_id,money,user_acc);
                            break;
                        }
                        case 2:
                        {
                            change_password(id);
                            break;
                        }
                        case 3:
                        {
                            u32 money;
                            printf("Enter amount of cash to withdraw: ");
                            scanf ("%d",&money);
                            withdraw_cash(money,user_acc);
                            break;
                        }
                        case 4:
                        {
                            u32 money;
                            printf("Enter amount of cash to deposit: ");
                            scanf ("%d",&money);
                            deposit_cash(money,user_acc);
                            break;
                        }
                        case 5:
                        {
                            k=0;
                            win =3;
                            break;
                        }
                        default:
                        {
                            printf("Wrong entery please try again");
                            break;
                        }
                }   }
            }

        }
    
    }

}
