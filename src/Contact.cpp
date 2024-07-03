#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string phone,
                 std::string email)
    : _phone(phone), _firstName(firstName), _lastName(lastName), _email(email) {
}
