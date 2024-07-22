#pragma once

#include "Contact.hpp"
#include <string>
#include <vector>

class ContactManager {
private:
  std::vector<Contact> _contacts;

private:
  bool ReadFile();
  std::vector<std::string> SplitContacts(const std::string &string,
                                         char delimiter);

public:
  ContactManager();

  void AddContact(std::string firstName, std::string laastName,
                  std::string phone, std::string email);
  const std::vector<Contact> &GetContacts() const;
};
