#include "ContactManager.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

ContactManager::ContactManager() {
  _contacts = {};
  ReadFile();
}

void ContactManager::AddContact(std::string firstName, std::string laastName,
                                std::string phone, std::string email) {

  _contacts.emplace_back(Contact(firstName, laastName, phone, email));
}

bool ContactManager::ReadFile() {
  namespace fs = std::filesystem;
  fs::path filePath = fs::current_path().append("contacts.con");
  std::fstream file;

  if (fs::exists(filePath)) {
    std::cout << "Contacts file found, reading...\n\n";
    file.open(filePath, std::ios::in);
    std::string line;
    std::vector<std::string> contact;
    while (std::getline(file, line)) {
      contact = SplitContacts(line, ':');
      if (contact[0].empty() || contact[2].empty()) {
        std::cout << "Firstname and Phone can't be empty!\n";
        return false;
      }
      for (std::string &token : contact) {
        if (token == "") {
          token = "Not Provided";
        }
        std::cout << token << "\n";
      }
      AddContact(contact[0], contact[1], contact[2], contact[3]);
    }
  } else {
    std::cout << "Contacts file not found, a new one will be created...\n";
    file.open(filePath, std::ios::out);
  }
  file.close();
  return true;
}

std::vector<std::string>
ContactManager::SplitContacts(const std::string &string, char delimiter) {
  std::stringstream ss(string);
  std::string token;
  std::vector<std::string> tokenList;

  while (std::getline(ss, token, delimiter)) {
    tokenList.push_back(token);
  }
  return tokenList;
}

const std::vector<Contact> &ContactManager::GetContacts() const {
  return _contacts;
}
