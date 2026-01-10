#include <iostream>
#include "banking.hpp"
#include "json.hpp"
#include <random>
#include <fstream>
#include <string>


using namespace std; 
using json = nlohmann::json; 

string createAccNo(){
    srand(time(0)); 
    ifstream file("banking_data.json");
    json data; 

    file >> data; 
    string account; 

    while(true){
        int random = rand(); // generates an acc no for the user
        string rand = to_string(random); 

        if (!data["accounts"].contains(rand)) {
            cout << "Your acc no is: " << rand << endl; 
            account = rand; 
            break; 
        } 
    }
    return account; 
}

void createBankAccount(){
    string name; 
    double balance; 
    string account; 
    string email; 
    int pin; 
    cout << "------------------------------------------" << endl; 
    cout << "Enter your full legal name: "; 
    getline(cin >> ws, name); 
    while(true){
    cout << "Enter your email: "; 
    getline(cin, email); 
    if(!checkEmail(email)){
        break; 
    }
    else{
        cout << "Email already registered with us." << endl; 
    }
    }
    cout << "Enter your pin: " << endl; 
    cin >> pin; 
    

    account = createAccNo(); 
    balance = 0; 

    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    data["accounts"][account] = {
        {"balance", balance},
        {"name", name}, 
        {"email", email}, 
        {"pin", pin}
    }; 

    ofstream out("banking_data.json"); 

    out << data.dump(4); 
    file.close(); 
}

bool checkEmail(string email){
    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    for(auto it= data["accounts"].begin(); it != data["accounts"].end(); it++){
        json& account = it.value(); 
        if(account["email"] == email) return true; 
    }
    return false; 


}


bool logIn(string email, int pin){
    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 
    
    for(auto it = data["accounts"].begin();it!=data["accounts"].end(); it++){
        json& account = it.value(); 

        if(account["email"] == email){
            if(account["pin"] == pin){
                return true; 
            }
            else{
                cout << "Incorrect pin" << endl; 
                return false; 
            }
        }
    }
    cout << "Email does not exist" << endl; 
    return false; 
}

void displayInfo(string email){
    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    for(auto it= data["accounts"].begin(); it!= data["accounts"].end(); it++){
        json& account = it.value(); 

        if(account["email"] == email){
            cout << "----------------------------------------------" << endl; 
            cout << "Account number: "; 
            cout << it.key() << endl; 
            cout << "Account name: "; 
            cout << account["name"] << endl; 
            cout << "Balance: "; 
            cout << account["balance"] << endl; 
        }
    }
}

void deposit(double amount, string email){
    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    for(auto it = data["accounts"].begin(); it != data["accounts"].end(); it++){
        json& account = it.value(); 

        if(account["email"] == email){
            account["balance"] = account["balance"].get<double>() + amount; 
            break;  
        }
    }
    ofstream out("banking_data.json"); 
    out << data.dump(4); 
}
    
void withDraw(double amount, string email){
    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    for(auto it = data["accounts"].begin(); it != data["accounts"].end(); it++){
        json& account = it.value(); 

        if(account["email"] == email){
            if(account["balance"].get<double>() < amount){
                cout << "Insufficient balance. " << endl; 
                break; 
            }
            account["balance"] = account["balance"].get<double>() - amount; 
            break;  
        }
    }
    ofstream out("banking_data.json"); 
    out << data.dump(4); 
}

void transfer(double amount, string sender, string receiver){
    withDraw(amount, sender); 
    deposit(amount, receiver); 
}

void moneyHistory(string email, string transactionType, double amount, string email2){
    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    data["transfers"][email] = {
        {"amount", amount},
        {"Transaction type", transactionType}, 
        {"Transferred to: ", email2}, 
        {"date: ", time(nullptr)}
    }; 

    ofstream out("banking_data.json"); 

    out << data.dump(4); 
    file.close(); 
}

void viewHistory(){
    
}
