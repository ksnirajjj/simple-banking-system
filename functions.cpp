#include <iostream>
#include "banking.hpp"
#include "json.hpp"
#include <random>
#include <fstream>


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
    cout << "------------------------------------------" << endl; 
    cout << "Enter your full legal name: " << endl; 
    cin >> name; 

    account = createAccNo(); 
    balance = 0; 

    ifstream file("banking_data.json"); 
    json data; 
    file >> data; 

    data["accounts"][account] = {
        {"balance", balance},
        {"name", name}, 
    }; 

    ofstream out("banking_data.json"); 

    out << data.dump(4); 
    file.close(); 
}

int main(){
    createBankAccount(); 
}



