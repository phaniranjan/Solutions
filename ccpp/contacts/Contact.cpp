//================= contact.cpp ========================

#include "Contact.h"

Contact::Contact()
{
    this->id = new int(-1);
    this->name = new string("No Name");
    this->phoneNumber = new string("No Phone Number");
}

Contact::Contact(int id, string name, string phoneNumber)
{
// Implement Overloaded Constructor
// Remember to initialize pointers on the heap!
    this->id = new int(id);
    this->name = new string(name);
    this->phoneNumber = new string(phoneNumber);
}

Contact::~Contact()
{
// Implement Destructor
    if(this->id != nullptr)
        delete this->id;
    if(this->name != nullptr)
        delete this->name;
    if(this->phoneNumber != nullptr)
        delete this->phoneNumber;
}

Contact::Contact(const Contact &copy)
{
// Implement Copy Constructor
    this->id = new int(copy.getId());
    this->name = new string(copy.getName());
    this->phoneNumber = new string(copy.getPhoneNumber());
}

Contact &Contact::operator=(const Contact &copy)
{
// Implement Copy Assignment Operator
    if(this == &copy) // Checks for self Assignment
        return *this;
    this->id = new int(copy.getId());
    this->name = new string(copy.getName());
    this->phoneNumber = new string(copy.getPhoneNumber());

    return *this;
}


// getters
int Contact::getId() const
{
    return *(this->id);
}
string Contact::getName() const
{
    return *(this->name);
}
string Contact::getPhoneNumber() const
{
    return *(this->phoneNumber);
}

//setters
void Contact::setId(int id)
{
    *(this->id) = id;
}
void Contact::setName(string name)
{
    *(this->name) = name;
}
void Contact::setPhoneNumber(string phoneNumber)
{
    *(this->phoneNumber) = phoneNumber;
}
