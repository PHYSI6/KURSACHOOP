#pragma once
#include "KURSACHOOP.h"
void CONSOLE_SETTING();
int getInt();
void CreateFiles();
void fillSize(int&, int&, int&);
string writeNames();
string writePhoneNumber();
void setColor(int, int);
int getGender();
void changeSizeUsers(User*&, int&);
void changeSizeAdmins(Admin*&, int&);
void changeSizeDetails(Characteristics*&, int&);
string writePassword();
string writeNames();
int fillClasses(Admin*&, User*&, Characteristics*&, int&, int&, int&, int&);
void fillFiles(Admin*&, User*&, Characteristics*&, int&, int&, int&);
string writeUniversal();
