//================== contact.h =====================

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Contact
{
public:
    Contact();
    Contact(int id, string name, string phoneNumber);
    ~Contact();
    Contact(const Contact& copy);
    Contact& operator=(const Contact& copy);

// getters
    int getId() const;
    string getName() const;
    string getPhoneNumber() const;

//setters
    void setId(int id);
    void setName(string name);
    void setPhoneNumber(string phoneNumber);

private:
    int *id = nullptr;
    string *name = nullptr;
    string *phoneNumber = nullptr;
};


#endif
