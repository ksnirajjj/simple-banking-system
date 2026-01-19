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
            if(!isFrozen(email)){
            if(logIn(email, pin)){
                loginPage:
                displayInfo(email); 
                int choice2; 
                cout << "What would you like to do? " << endl; 
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;  
                cout << "3. Transfer" << endl; 
                cout << "4. View History" << endl; 
                cin >> choice2; 
                double amount;
                string email2;  
                int placeHolder; 

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
                        cout << "------------------------------" << endl; 
                        viewHistory(email); 
                        cout << "------------------------------" << endl; 
                        cout << "Press any key to continue: "; 
                        cin >> placeHolder; 
                        goto loginPage; 
                        break; 
                }; 
                }
            else{
                goto menu; 
            }
            }
            break; 

        case 2:
            createBankAccount();
            cout << "Acount created successfully" << endl; 
            goto menu; 
            break;  
        
        case 987654:
            int choice3; 
            displayAdminInfo(); 
            cin >> choice3;
            string email3, email4, email5; 

        
            switch(choice3){
                case 1:
                    cout << "Enter the email associated with the account you wish to freeze: "; 
                    cin >> email3; 
                    freezeEmail(email3); 
                    cout << "Task successful." << endl; 
                    break; 
                
                case 2:
                    cout << "Enter the email associated with the account you wish to change: "; 
                    cin >> email4; 
                    changeAccDetails(email4); 
                    cout << "Task successful. " << endl; 
                    break; 
            }
    }; 

}