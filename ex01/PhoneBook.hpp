#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int oldestContactIndex;
    int totalContacts;

    void displayContactSummary(int index) const;
    std::string truncateField(const std::string& field) const;

public:
    PhoneBook();

    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
};