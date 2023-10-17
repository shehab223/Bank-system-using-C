# Bank-system-using-C

This project is a banking system using C language.
At the start of the program the user is asked to choose between customer window or admin window.

Admin wimdow:
The admin will be asked to enter his user name and password to access admin features.

Admin window consists of 3 main features:
1. Create New Account:
  In this Feature you will be asked to enter the following parameters
  - Full Name
  - Full Address
  - Age 
  - National ID
  - Guardian National ID 
  (If Age < 21 you will be asked automatically for Guardian National ID)
  - Balance
  - A random password will be assigned to this account
  
 2. Open Existing Account:
    In this Feature you will be asked to enter Client Bank Account ID then
    choose between the following features:
    1. Make a transaction
       In this feature you will be asked to enter the Bank Account ID you want to
       transfer money to. Then you will be asked to enter amount of money to 
       transfer it to the this account.
       The program will check if the amount of money is less than your client’s   
       balance and that both accounts are Active or the transaction won’t be completed.

    2. Change Account Status:
       In this feature you will be asked to enter the Bank Account Status, you want for
       this account
       1- Set Account to Active State
       2- Set Account to Restricted State
       3- Set Account to Closed
      
    3. Get Cash
       In this feature you will be asked to enter the cash amount you want from
       this account and it will be reduced from the account balance 
       after making sure the cash amount is less than the account balance.
      
    4. Deposit in Account
       In this feature you will be asked to enter the cash amount you want to add to this account.
      
    5. Return to main menu
    6. Exit the system
    
Client Window:
To Enter this Window, Client must use correct Bank Account ID and Password.
In this window Client can perform the following actions:

1. Make a transaction:
   In this feature client will be asked to enter the Bank Account ID to transfer money to.
   Then you will be asked to enter amount of money to transfer it to the this account.
   The program will check if the amount of money is less than your client’s balance and that both accounts are Active or the transaction won’t be completed.

2. Change account password:
   In this feature the client will be asked to enter the old password and if it was correct he will be asked to enter the new password.

3. Get cash:
   In this feature you will be asked to enter the cash amount you want from his account and
   it will be reduced from account balance after making sure the cash amount is less than the account balance.

4. Deposit in account:
   In this feature client will be asked to enter the cash amount you want to add
   to this account.

5. Return to Main menu.
