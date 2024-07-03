#pragma once

#include "Contact.hpp"
#include <vector>

class ContactManager {
private:
  std::vector<Contact> _contacts;

public:
  ContactManager();

  void AddContact(std::string firstName, std::string laastName,
                  std::string phone, std::string email);
};
