/*In this lab, you will be creating a class that implements the Rule of Three (A Destructor, A Copy Constructor, and a Copy Assignment Operator). You are to create a program that prompts users to enter in contact information, dynamically create each object, then print the information of each contact to the screen. Some code has already been provided for you. To receive full credit make sure to implement the following:

Default Constructor - set Contact id to -1
Overloaded Constructor - used to set the Contact name, phoneNumber and id (Should take in 3 parameters)
Destructor
Copy Constructor
Copy Assignment Operator
Any other useful functions (getters/setters) */
============== main.cpp =======================

#include <iostream>
#include <vector>
#include "Contact.h"

    using namespace std;

int main()
{
    const int NUM_OF_CONTACTS = 3;
    vector<Contact *> contacts;

    for (int i = 0; i < NUM_OF_CONTACTS; i++)
    {
        string name, phoneNumber;
        cout << "Enter a name: ";
        cin >> name;
        cout << "Enter a phoneNumber: ";
        cin >> phoneNumber;

// Use i, name, and phone number to dynamically create a Contact object on the heap
// HINT: Use the Overloaded Constructor here!
        Contact * newContact = new Contact(i+1,name,phoneNumber);

// Add the Contact * to the vector...
        contacts.push_back(newContact);
    }
    cout << "\n\n----- Contacts ----- \n\n";

// Loop through the vector of contacts and print out each contact info

    std::vector<Contact *>::iterator itrContact;
    for(itrContact = contacts.begin(); itrContact !=contacts.end(); itrContact++)
    {
        cout<< " Id : " << (*itrContact)->getId();
        cout<< " Name : " << (*itrContact)->getName();
        cout<< " Phone-Number : " << (*itrContact)->getPhoneNumber() <<endl;
    }

// Make sure to call the destructor of each Contact object by looping through the vector and using the delete keyword

    for(int i = 0; i < NUM_OF_CONTACTS; i++)
    {
        delete contacts[i];
    }

    return 0;
}
