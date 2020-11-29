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
#include <string.h>
#include <ctype.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5
//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void) {
    while (getchar() != '\n'); // empty execution code block on purpose
}

void pause(void) {
    printf("(Press Enter to continue)");
    clearKeyboard();
}

int getInt(void) {
    char nl = 'x';
    int value = 0;

    while (nl != '\n') {
        scanf("%d%c", &value, &nl);
        if (nl != '\n') {
            // Invalid input.
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }

    return value;
}

int getIntInRange(int min, int max) {
    int value = 0;
    int valid = 0;
    while (!valid) {
        value = getInt();
        if (value >= min && value <= max) {
            valid = 1;
        } else {
            // Invalid input.
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    }

    return value;
}

int yes(void) {
    char nl = 0;
    char value = 0;

    while (nl != '\n') {
        scanf("%c%c", &value, &nl);
        if (nl != '\n') {
            // Invalid input.
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
    }

    if (value == 'Y' || value == 'y') {
        return 1;
    }
    return 0;
}

int menu(void) {
    // Display menu.
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");

    return getIntInRange(0, 6);
}

void contactManagerSystem(void) {
    int shouldExit = 0;
    int option = 0;
    struct Contact contacts[MAXCONTACTS] = {
        {
            {
                "Rick",
                {'\0'},
                "Grimes"
            },
            {
                11,
                "Trailer Park",
                0,
                "A7A 2J2",
                "King City"
            },
            {
                "4161112222",
                "4162223333",
                "4163334444"
            }
        },
        {
            {
                "Maggie",
                "R.",
                "Greene"
            },
            {
                55,
                "Hightop House",
                0,
                "A9A 3K3",
                "Bolton"
            },
            {
                "9051112222",
                "9052223333",
                "9053334444"
            }
        },
        {
            {
                "Morgan",
                "A.",
                "Jones"
            },
            {
                77,
                "Cottage Lane",
                0,
                "C7C 9Q9",
                "Peterborough"
            },
            {
                "7051112222",
                "7052223333",
                "7053334444"
            }
        },
        {
            {
                "Sasha",
                {'\0'},
                "Williams"
            },
            {
                55,
                "Hightop House",
                0,
                "A9A 3K3",
                "Bolton"
            },
            {
                "9052223333",
                "9052223333",
                "9054445555"
            }
        }
    };

    while (!shouldExit) {
        option = menu();
        printf("\n");
        switch (option) {
            case 1:
                displayContacts(contacts, MAXCONTACTS);
                pause();
                break;
            case 2:
                addContact(contacts, MAXCONTACTS);
                pause();
                break;
            case 3:
                updateContact(contacts, MAXCONTACTS);
                pause();
                break;
            case 4:
                deleteContact(contacts, MAXCONTACTS);
                pause();
                break;
            case 5:
                searchContacts(contacts, MAXCONTACTS);
                pause();
                break;
            case 6:
                sortContacts(contacts, MAXCONTACTS);
                pause();
                break;
            default:
                printf("Exit the program? (Y)es/(N)o: ");
                shouldExit = yes();
                break;
        }
        printf("\n");
    }

    printf("Contact Management System: terminated\n");
}

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int isNumeric = 0;
    int i = 0;

    while (needInput == 1) 
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // Validate each char is numeric.
        isNumeric = 1;
        for (i = 0; i < 10 && isNumeric; i++) {
            if (!isdigit(phoneNum[i])) {
                isNumeric = 0;
            }
        }

        // Validate length 10 numeric digits.
        if (strlen(phoneNum) == 10 && isNumeric) {
            needInput = 0;
        } else {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
    int ret = -1;
    int i = 0;
    for (i = 0; i < size && ret == -1; i++) {
        if (0 == strcmp(contacts[i].numbers.cell, cellNum)) {
            // Cell number matched.
            ret = i;
        }
    }

    return ret;
}


// displayContactHeader
void displayContactHeader(void) {
    int i = 0;

    // First line
    printf("+");
    for (i = 0; i < 77; i++) printf("-");
    printf("+\n");

    // Second line
    printf("|");
    for (i = 0; i < 30; i++) printf(" ");
    printf("Contacts Listing");
    for (i = 0; i < 31; i++) printf(" ");
    printf("|\n");

    // Third line
    printf("+");
    for (i = 0; i < 77; i++) printf("-");
    printf("+\n");
}

// displayContactFooter
void displayContactFooter(int count) {
    int i = 0;
    // First line
    printf("+");
    for (i = 0; i < 77; i++) printf("-");
    printf("+\n");

    // Second line
    printf("Total contacts: %d\n\n", count);
}


// displayContact
void displayContact(const struct Contact *contact) {
    // First line
    printf(" ");
    printf("%s ", contact->name.firstName);
    if (strlen(contact->name.middleInitial) != 0) {
        // has middle initial
        printf("%s ", contact->name.middleInitial);
    }
    printf("%s\n", contact->name.lastName);

    // Second line
    printf(
        "    C: %-10s   H: %-10s   B: %-10s\n",
        contact->numbers.cell,
        contact->numbers.home,
        contact->numbers.business
    );

    // Third line
    printf(
        "       %d %s, ",
        contact->address.streetNumber,
        contact->address.street
    );
    if (contact->address.apartmentNumber) {
        printf(
            "Apt# %d, ",
            contact->address.apartmentNumber
        );
    }
    printf(
        "%s, %s\n",
        contact->address.city,
        contact->address.postalCode
    );
}

// displayContacts
void displayContacts(const struct Contact contacts[], int size) {
    int numValidContacts = 0;
    int i = 0;

    displayContactHeader();
    for (i = 0; i < size; i++) {
        // Validate.
        if (contacts[i].numbers.cell[0] != '\0') {
            // Valid.
            numValidContacts++;
            displayContact(&contacts[i]);
        }
    }
    displayContactFooter(numValidContacts);
}

// searchContacts
void searchContacts(const struct Contact contacts[], int size) {
    char cellNum[11] = { 0 };
    int index = -1;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
}


// addContact
void addContact(struct Contact contacts[], int size) {
    int emptyIndex = findContactIndex(contacts, size, "");
    if (emptyIndex == -1) {
        // Full.
        printf("*** ERROR: The contact list is full! ***\n\n");
    } else {
        getContact(&contacts[emptyIndex]);
        printf("--- New contact added! ---\n\n");
    }
}


// updateContact
void updateContact(struct Contact contacts[], int size) {
    char cellNum[11] = { 0 };
    int index = -1;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes()) {
            getName(&contacts[index].name);
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes()) {
            getAddress(&contacts[index].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes()) {
            getNumbers(&contacts[index].numbers);
        }
        printf("--- Contact Updated! ---\n\n");
    }
}


// deleteContact
void deleteContact(struct Contact contacts[], int size) {
    char cellNum[11] = { 0 };
    int index = -1;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        if (yes()) {
            contacts[index].numbers.cell[0] = '\0';
            printf("---Contact deleted! ---\n");
        }
        printf("\n");
    }
}

int partition(struct Contact contacts[], int lo, int hi) {
    struct Contact temp = { 0 };
    char* pivot = contacts[hi].numbers.cell;
    int i = lo;
    int j = 0;

    for (j = lo; j <= hi; j++) {
        if (strcmp(contacts[j].numbers.cell, pivot) < 0) {
            temp = contacts[i];
            contacts[i] = contacts[j];
            contacts[j] = temp;
            i++;
        }
    }

    temp = contacts[i];
    contacts[i] = contacts[hi];
    contacts[hi] = temp;

    return i;
}

void quickSort(struct Contact contacts[], int lo, int hi) {
    int p = 0;
    if (lo < hi) {
        p = partition(contacts, lo, hi);
        quickSort(contacts, lo, p - 1);
        quickSort(contacts, p + 1, hi);
    }
}

// sortContacts
void sortContacts(struct Contact contacts[], int size) {
    quickSort(contacts, 0, size - 1);
    printf("--- Contacts sorted! ---\n\n");
}
