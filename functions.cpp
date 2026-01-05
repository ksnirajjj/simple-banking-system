#include <iostream>
#include "banking.hpp"
#include "json.hpp"
#include <random>
#include <fstream>

using namespace std; 
using json = nlohmann::json; 

void createAccNo(){
    srand(time(0)); 
    ifstream file("banking_data.json");
    json data; 

    file >> data; 

    while(true){
        int random = rand(); // generates an acc no for the user
        string rand = to_string(random); 

        if (!data["accounts"].contains(rand)) {
            cout << "Your acc no is: " << rand << endl; 
            break; 
        } 
    }
    
     
}

int main(){
    createAccNo(); 
}



