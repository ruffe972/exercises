#include <stdio.h>
#include <string.h>
#include "textOperations.h"
#include "phoneBook.h"


enum Command
{
    exitCommand,
    addRecordCommand,
    findPhoneNumberByNameCommand,
    findNameByPhoneNumberCommand,
    saveCommand,
    nullCommand
};


void printIntroduction()
{
    printf("\nThe maximum number of contacts is %d.", maxContactsAmount);
    printf("\nThe maximum number of characters in a name or a phone number is %d.", maxStringLength);
    printf("\nThe phone numbers should always be formatted in the same way.");
    printf("\nChanging or deleting contacts is not supported.");
    printf("\nRecord format in the text file: name<\\n>phone number<\\n>.");
    printf("\nExtra symbols in the text file are not allowed.");
    printf("\n\nCommands:\n0 - exit\n1 - add a new record\n");
    printf("2 - get the phone number by name\n3 - get the name by phone number\n4 - save changes\n\n");
}





int main()
{
    char contactsFileName[maxStringLength];
    printf("Enter contacts file name: ");
    int contactsFileNameLength = 0;
    scanString(contactsFileName, contactsFileNameLength, stdin);
    if (contactsFileNameLength == 0)
    {
        strcpy(contactsFileName, "contacts.txt");
        printf("%s\n", contactsFileName);
    }
    printIntroduction();    
    FILE* contactsFile = fopen(contactsFileName, "a+");
    int contactsAmount = 0;
    Contact contacts[maxContactsAmount];
    readContactsFromFile(contacts, contactsAmount, contactsFile);
    int savedContactsAmount = contactsAmount;
    int command = nullCommand;
    while (command != exitCommand)
    {
        scanf("%d", &command);
        switch (command)
        {
        case addRecordCommand:
        {
            addScannedRecordPrintingMessages(contacts, contactsAmount);
            break;
        }
        case findPhoneNumberByNameCommand:
        {
            findPhoneNumberByScannedNamePrintingMessages(contacts, contactsAmount);
            break;
        }
        case findNameByPhoneNumberCommand:
        {
            findNameByScannedPhoneNumberPrintingMessages(contacts, contactsAmount);
            break;
        }        
        case saveCommand:
        {
            saveChangesPrintingMessages(contactsFile, contacts, contactsAmount, savedContactsAmount);
            break;
        }
        }
        printf("\n");
    }
    fclose(contactsFile);
    return 0;
}
