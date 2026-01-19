#ifndef banking_hpp
#define banking_hpp

using namespace std; 

void createAccno(); // generate new acc no for creating new account

void createBankAccount();  // create a new account

bool checkEmail(string email); // checking if an email is already there

bool logIn(string email, int pin); // log in to exsting account

void displayInfo(string email); 

void deposit(double amount, string email); 

void withDraw(double amount, string email); 

void transfer(double amount, string sender, string receiver); 

void moneyHistory(string email, string transactionType, double amount, string email2); 

void viewHistory(string email); 

void displayAdminInfo(); 

void freezeEmail(string email); 

bool isFrozen(string email); 

void changeAccDetails(string email); 

#endif