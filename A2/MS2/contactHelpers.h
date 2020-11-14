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

