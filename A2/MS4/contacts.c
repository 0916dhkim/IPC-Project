/* -------------------------------------------
Name: Donghyeon Kim
Student number: 151613197
Email: dkim167@myseneca.ca
Section: NSS
Date: 2020/11/29
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"


// getName
void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    if (yes())
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    } else {
        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress
void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    do {
        address->streetNumber = getInt();
        if (address->streetNumber <= 0) {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }
    } while (address->streetNumber <= 0);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes())
    {
        printf("Please enter the contact's apartment number: ");
        do {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber <= 0) {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
        } while (address->apartmentNumber <= 0);
    } else {
        address->apartmentNumber = 0;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers
void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");

    if (yes()) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    } else {
        numbers->home[0] = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    if (yes()) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    } else {
        numbers->business[0] = '\0';
    }
}

// getContact
void getContact(struct Contact *contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
