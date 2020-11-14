/* -------------------------------------------
Name: Donghyeon Kim
Student number: 151613197
Email: dkim167@myseneca.ca
Section: NSS
Date: 2020/11/14
----------------------------------------------
Assignment: 2
Milestone:  2
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
