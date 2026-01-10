#include <iostream>
#include "banking.hpp"
#include "json.hpp"
#include <random>
#include <fstream>

using namespace std; 
using json = nlohmann::json; 

int main(){
    menu:
    int choice; 
    cout << "---------------------------------------------" << endl; 
    cout << "Welcome to my Bank" << endl; 
    cout << "Please select: " << endl; 
    cout << "1. Log In " << endl; 
    cout << "2. Create New Account" << endl; 
    cout << "3. Exit" << endl; 
    cin >> choice; 
    string email; 
    int pin; 

    switch(choice){
        case 1:
            cout << "Enter your email: "; 
            cin >> email; 
            cout << "Enter your pin: "; 
            cin >> pin; 
            if(logIn(email, pin)){
                loginPage:
                displayInfo(email); 
                int choice2; 
                cout << "What would you like to do? " << endl; 
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;  
                cout << "3. Transfer" << endl; 
                cout << "4. Transaction Type" << endl; 
                cin >> choice2; 
                double amount;
                string email2;  

                switch(choice2){
                    case 1:
                        cout << "Enter the amount to be deposited: "; 
                        cin >> amount; 
                        deposit(amount,email); 
                        moneyHistory(email, "deposit", amount, "N/A"); 
                        cout << "Your deposit has been accepted. " << endl; 
                        goto loginPage; 
                        break; 
                    case 2:
                        cout << "Enter the amount to be withdrawn: "; 
                        cin >> amount; 
                        withDraw(amount,email); 
                        moneyHistory(email, "withdraw", amount, "N/A"); 
                        cout << "Your withdraw has been successful.  " << endl; 
                        goto loginPage; 
                        break; 
                    case 3:
                        cout << "Enter the amount to be transferred: "; 
                        cin >> amount; 
                        cout << "Enter the reciepent's email: " << endl; 
                        cin >> email2; 
                        transfer(amount, email, email2); 
                        moneyHistory(email, "transfer", amount, email2); 
                        cout << "Your transfer has been successful. " << endl; 
                        goto loginPage; 
                        break;
                    case 4: 
                        
                }; 
            }
            else{
                goto menu; 
            }
            break; 

        case 2:
            createBankAccount();
            cout << "Acount created successfully" << endl; 
            goto menu; 
            break;  

    

    }; 

}