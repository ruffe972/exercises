#pragma once

struct Set;
Set* createSet();

void printDebug(Set* set);
void printAscending(Set* set);
void printDescending(Set* set);

void deleteSet(Set* set);
bool elementExists(int value, Set* set);
void addElement(int value, Set* set);
void removeElement(int value, Set* set);
