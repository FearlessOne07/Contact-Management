#include "ContactManager.hpp"
#include <iostream>
#include <limits>

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

int main(void) {
  ContactManager conMan;

  enum Action : unsigned int { EXIT = 0, VIEW, ADD, DELETE, EDIT };
  unsigned int action = 0;
  bool selected = false;
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
    break;
  case ADD:
    break;
  case DELETE:
    break;
  case EDIT:
    break;
  default:
    return -1;
  }
}
