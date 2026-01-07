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

#endif