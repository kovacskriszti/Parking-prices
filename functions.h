#pragma once
// Declararea functiilor din functions.cpp
int ReadPrice();
int ReadInputBanknotes(int);
int ReadInputBanknotes();
void ReturnBanknotes(int banknote, int& remaining);
void ShowRemaining(int);
bool CheckBanknote(int);