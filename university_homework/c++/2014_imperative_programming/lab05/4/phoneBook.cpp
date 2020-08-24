#include <stdio.h>
#include <string.h>
#include "phoneBook.h"
#include "textOperations.h"


const int notFound = -1;
const int equal = 0;


void readContactsFromFile(Contact *contacts, int &contactsAmount, FILE *file)
{
    bool canRead = true;
    while (canRead)
    {
        scanString(contacts[contactsAmount].name, contacts[contactsAmount].nameLength, file);
        if (feof(file))
            canRead = false;
        else
        {
            scanString(contacts[contactsAmount].phoneNumber, contacts[contactsAmount].phoneNumberLength, file);
            contactsAmount++;
        }
    }
}


int nameByPhoneNumberIndex(Contact *contacts, int contactsAmount, char *requiredPhoneNumber)
{
    int i = 0;
    bool phoneNumberIsFound = false;
    while (i < contactsAmount && !phoneNumberIsFound)
    {
        if (strcmp(contacts[i].phoneNumber, requiredPhoneNumber) == equal)
            phoneNumberIsFound = true;
        i++;
    }
    if (phoneNumberIsFound)
        return i - 1;
    else
        return notFound;
}


void addScannedRecordPrintingMessages(Contact *contacts, int &contactsAmount)
{
    if (contactsAmount == maxContactsAmount)
        printf("Error: the maximum number of contacts was reached.\n");
    else
    {
        printf("Enter the name: ");
        scanString(contacts[contactsAmount].name, contacts[contactsAmount].nameLength, stdin);
        printf("Enter the phone number: ");
        scanString(contacts[contactsAmount].phoneNumber, contacts[contactsAmount].phoneNumberLength, stdin);
        if (nameByPhoneNumberIndex(contacts, contactsAmount, contacts[contactsAmount].phoneNumber) == notFound)
        {
            contactsAmount++;
            printf("The contact was added.\n");
        }
        else
            printf("A contact with such a phone number already exists.");
    }
}


void findPhoneNumberByScannedNamePrintingMessages(Contact *contacts, int contactsAmount)
{
    printf("Enter the name: ");
    char requiredName[maxStringLength];
    int requiredNameLength = 0;
    scanString(requiredName, requiredNameLength, stdin);
    printf("The phone numbers of contacts with the name %s:\n", requiredName);
    int contactsCounter = 0;
    for (int i = 0; i < contactsAmount; i++)
        if (strcmp(contacts[i].name, requiredName) == equal)
        {
            contactsCounter++;
            printf("%s\n", contacts[i].phoneNumber);
        }
    if (contactsCounter == 0)
        printf("Nothing was found.\n");
}


void findNameByScannedPhoneNumberPrintingMessages(Contact *contacts, int contactsAmount)
{
    printf("Enter the phone number: ");
    char requiredPhoneNumber[maxStringLength];
    int requiredPhoneNumberLength = 0;
    scanString(requiredPhoneNumber, requiredPhoneNumberLength, stdin);
    int requiredIndex = nameByPhoneNumberIndex(contacts, contactsAmount, requiredPhoneNumber);
    if (requiredIndex == notFound)
        printf("The phone number was not found.\n");
    else
        printf("It is a phone number of %s.\n", contacts[requiredIndex].name);
}


void saveChangesPrintingMessages(FILE *file, Contact *contacts, int contactsAmount, int &savedContactsAmount)
{
    for (int i = savedContactsAmount; i < contactsAmount; i++)
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phoneNumber);
    savedContactsAmount = contactsAmount;
    printf("All changes are saved.\n");
}
