#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string phone,
                 std::string email)
    : _phone(phone), _firstName(firstName), _lastName(lastName), _email(email) {
}

const std::string &Contact::GetFirstName() const { return _firstName; }
const std::string &Contact::GetLastName() const { return _lastName; }
const std::string &Contact::GetEmail() const { return _email; }
const std::string &Contact::GetPhone() const { return _phone; }
unsigned Contact::GetId() const { return _id; }
