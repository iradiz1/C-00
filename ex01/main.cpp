#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;

        if (command == "ADD") {
            Contact newContact;
            std::string input;

            std::cout << "Enter First Name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;;
            newContact.setFirstName(input);

            std::cout << "Enter Last Name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.setLastName(input);

            std::cout << "Enter Nickname: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.setNickname(input);

            std::cout << "Enter Phone Number: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.setPhoneNumber(input);

            std::cout << "Enter Darkest Secret: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.setDarkestSecret(input);

            phonebook.addContact(newContact);

        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            std::cout << "Enter the index of the contact to display: ";
            std::string input;
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            try
            {
                int index = std::stoi(input);
                phonebook.displayContactDetails(index);
            }
            catch(const std::exception& e)
            {
                std::cerr << "invalid index nbr" << '\n';
            }
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
