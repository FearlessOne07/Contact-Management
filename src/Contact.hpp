#pragma once

#include <string>
class Contact {
private:
  std::string _phone;
  std::string _firstName;
  std::string _lastName;
  std::string _email;

public:
  Contact(std::string firstName, std::string lastName, std::string phone,
          std::string email);

  const std::string &GetFirstName() const { return _firstName; }
  const std::string &GetLastName() const { return _lastName; }
  const std::string &GetEmail() const { return _email; }
  const std::string &GetPhone() const { return _phone; }
};
