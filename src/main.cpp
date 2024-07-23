#include "ContactManager.hpp"
#include <ios>
#include <iostream>
#include <limits>
#include <string>

// Colors
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD_BLACK "\033[1m\033[30m"
#define BOLD_RED "\033[1m\033[31m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN "\033[1m\033[36m"
#define BOLD_WHITE "\033[1m\033[37m"
#define CLEAR_SCREEN "\033[2J\033[H"

void View(const ContactManager &conMan);
void Add(const ContactManager &conMan);

int main(void) {
  ContactManager conMan;

  enum Action : unsigned int { EXIT = 0, VIEW, ADD, DELETE, EDIT };
  unsigned int action = 0;
  bool selected = false;
  std::cout << CLEAR_SCREEN;
  while (!selected) {
    selected = true;
    std::cout << BOLD_YELLOW << "What do you want to do?" << RESET << "\n";
    std::cout << BOLD_WHITE << "1 - View Contacts\n";
    std::cout << BOLD_WHITE << "2 - Add Contact\n";
    std::cout << BOLD_WHITE << "3 - Delete Contact\n";
    std::cout << BOLD_WHITE << "4 - Edit Contact\n";
    std::cout << BOLD_WHITE << "0 - Exit\n";
    std::cout << RESET << '\n';
    std::cout << "(1/2/3/4/0): ";
    std::cin >> action;
    std::cout << "\n";

    if (std::cin.fail() || action > 4) {
      selected = false;
      std::cout << BOLD_RED << "Invalid option! Try Again!" << RESET << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      action = 0;
    }
  }

  switch (static_cast<Action>(action)) {
  case EXIT:
    return 0;
    break;
  case VIEW:
    View(conMan);
    break;
  case ADD:
    Add(conMan);
    break;
  case DELETE:
    break;
  case EDIT:
    break;
  default:
    return -1;
  }
}

void View(const ContactManager &conMan) {
  enum Action : unsigned { EXIT = 0 };
  if (conMan.GetContacts().size() == 0) {
    std::cout << BOLD_YELLOW << "There are no contacts to view!" << RESET
              << "\n";
  } else {
    for (const Contact &contact : conMan.GetContacts()) {
      std::cout << contact.GetFirstName() << " " << contact.GetLastName()
                << "\n";
    }
  }
}

void Add(const ContactManager &conMan) {
  std::string firstName;
  bool firstEntered = false;
  std::string lastName;
  bool lastEntered = false;
  std::string email;
  bool emailEntered = false;
  std::string phone;
  bool phoneEntered = false;

  while (!firstEntered) {
    firstEntered = true;
    std::cout << "First name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, firstName);
    if (std::cin.fail()) {
      std::cout << "Invalid Input! Try again!\n";
      firstEntered = false;
    } else if (firstName.length() == 0) {
      std::cout << "First name cannot be empty!\n";
      firstEntered = false;
    } else if (firstName.length() < 3) {
      std::cout << "First name must be at least three characters long\n";
      firstEntered = false;
    }
  }

  while (!lastEntered) {
    lastEntered = true;
    std::cout << "Last name: ";
    std::getline(std::cin, lastName);
    if (std::cin.fail()) {
      std::cout << "Invalid Input! Try again!\n";
      lastEntered = false;
    } else if (lastName.length() == 0) {
      lastName = "Not Entered";
    } else if (lastName.length() < 3) {
      std::cout << "Last name must be at least three characters long\n";
      lastEntered = false;
    }
  }

  while (!phoneEntered) {
    phoneEntered = true;
    std::cout << "Phone: ";
    std::getline(std::cin, phone);
    if (std::cin.fail()) {
      std::cout << "Invalid Input! Try again!\n";
      phoneEntered = false;
    } else if (phone.length() == 0) {
      std::cout << "Phone cannot be empty!\n";
      phoneEntered = false;
    } else if (phone.length() != 11) {
      std::cout << "Phone must be at eleven characters long\n";
      phoneEntered = false;
    }
  }

  while (!emailEntered) {
    emailEntered = true;
    std::cout << "Email: ";
    std::getline(std::cin, email);
    if (std::cin.fail()) {
      std::cout << "Invalid Input! Try again!\n";
      emailEntered = false;
    } else if (email.length() == 0) {
      email = "Not Entered";
    } else if (email.length() < 3) {
      std::cout << "email must be at least three characters long\n";
      emailEntered = false;
    }
  }

  std::cout << firstName << ":" << lastName << ":" << phone << ":" << email
            << "\n";
}
