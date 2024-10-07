#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : oldestContactIndex(0), totalContacts(0) {}

void PhoneBook::addContact(const Contact& contact) {
    if (totalContacts < 8) {
        contacts[totalContacts] = contact;
        totalContacts++;
    } else {
        contacts[oldestContactIndex] = contact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

void PhoneBook::displayContactSummary(int index) const {
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << truncateField(contacts[index].getFirstName()) << "|";
    std::cout << std::setw(10) << truncateField(contacts[index].getLastName()) << "|";
    std::cout << std::setw(10) << truncateField(contacts[index].getNickname()) << std::endl;
}

std::string PhoneBook::truncateField(const std::string& field) const {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return field;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; i++) {
        displayContactSummary(i);
    }
}

void PhoneBook::displayContactDetails(int index) const {
    if (index < 0 || index >= totalContacts) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    const Contact& contact = contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
