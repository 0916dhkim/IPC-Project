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

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks. 
---------------------------------------------------------------------*/

//--------------------------------
// Function Prototypes
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void);

// Display a pause message and wait for the user
// to press the <ENTER> key.
void pause(void);

// Get a valid integer.
int getInt(void);

// Get a valid integer between min and max (inclusive).
int getIntInRange(int min, int max);

// Return 1 if the user enters 'Y' or 'y'.
// Return 0 if the user enters 'N' or 'n'.
int yes(void);

// Display a menu and let the user select an option.
int menu(void);

// contactManagerSystem:
void contactManagerSystem(void);

// Generic function to get a ten-digit phone number.
void getTenDigitPhone(char phoneNum[]);

// findContactIndex
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader
void displayContactHeader(void);

// displayContactFooter
void displayContactFooter(int count);

// displayContact
void displayContact(const struct Contact *contact);

// displayContacts
void displayContacts(const struct Contact contacts[], int size);

// searchContacts
void searchContacts(const struct Contact contacts[], int size);

// addContact
void addContact(struct Contact contacts[], int size);

// updateContact
void updateContact(struct Contact contacts[], int size);

// deleteContact
void deleteContact(struct Contact contacts[], int size);

// sortContacts
void sortContacts(struct Contact contacts[], int size);
