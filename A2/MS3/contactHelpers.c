/* -------------------------------------------
Name: Donghyeon Kim
Student number: 151613197
Email: dkim167@myseneca.ca
Section: NSS
Date: 2020/11/29
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"

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

    while (!shouldExit) {
        option = menu();
        printf("\n");
        switch (option) {
            case 1:
                printf("<<< Feature 1 is unavailable >>>\n\n");
                pause();
                break;
            case 2:
                printf("<<< Feature 2 is unavailable >>>\n\n");
                pause();
                break;
            case 3:
                printf("<<< Feature 3 is unavailable >>>\n\n");
                pause();
                break;
            case 4:
                printf("<<< Feature 4 is unavailable >>>\n\n");
                pause();
                break;
            case 5:
                printf("<<< Feature 5 is unavailable >>>\n\n");
                pause();
                break;
            case 6:
                printf("<<< Feature 6 is unavailable >>>\n\n");
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

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1) 
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
void displayContactHeader(void) {
}

// displayContactFooter
void displayContactFooter(int count) {
}


// displayContact
void displayContact(const struct Contact *contact) {
}

// displayContacts
void displayContacts(const struct Contact contacts[], int size) {
}


// searchContacts
void searchContacts(const struct Contact contacts[], int size) {
}


// addContact
void addContact(struct Contact contacts[], int size) {
}


// updateContact
void updateContact(struct Contact contacts[], int size) {
}


// deleteContact
void deleteContact(struct Contact contacts[], int size) {
}


// sortContacts
void sortContacts(struct Contact contacts[], int size) {
}
