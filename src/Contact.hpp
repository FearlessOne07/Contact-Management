#pragma once

#include <string>
class Contact {
private:
  std::string _phone;
  std::string _firstName;
  std::string _lastName;
  std::string _email;
  unsigned _id;

public:
  Contact(std::string firstName, std::string lastName, std::string phone,
          std::string email);
  const std::string &GetFirstName() const;
  const std::string &GetLastName() const;
  const std::string &GetEmail() const;
  const std::string &GetPhone() const;
  unsigned GetId() const;
};
