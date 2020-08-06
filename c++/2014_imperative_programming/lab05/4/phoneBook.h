#pragma once
#include <stdio.h>
#include "textOperations.h"


const int maxContactsAmount = 1000;

struct Contact
{
    char name[maxStringLength];
    int nameLength;
    char phoneNumber[maxStringLength];
    int phoneNumberLength;
};

void readContactsFromFile(Contact *contacts, int &contactsAmount, FILE *file);
int nameByPhoneNumberIndex(Contact *contacts, int contactsAmount, char *requiredPhoneNumber);
void addScannedRecordPrintingMessages(Contact *contacts, int &contactsAmount);
void findPhoneNumberByScannedNamePrintingMessages(Contact *contacts, int contactsAmount);
void findNameByScannedPhoneNumberPrintingMessages(Contact *contacts, int contactsAmount);
void saveChangesPrintingMessages(FILE *file, Contact *contacts, int contactsAmount, int &savedContactsAmount);
