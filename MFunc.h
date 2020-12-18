#pragma once
#include "KURSACHOOP.h"
int openAdminMenu(Admin*&, User*&, int&, int&, int&, Characteristics*&, int&);
void redUser(Admin*&, User*&, int&, int&, int, int);
void showOneDetail(Characteristics*&, int c);
void showAllDetails(Characteristics*&, int&);
void openMenuSort(Characteristics*&, int&, User*&, int&);
int openProcMenu(Characteristics*&, int&, User*&, int&);
void addOneDetails(Characteristics*&, int&);
int openMenuAdministration(Admin*&, User*&, int&, int&, int&);
void changeMenuUsers(Admin*&, User*&, int&, int&, int&);
void showUsers(Admin*&, User*&, int&, int&);
void openMenuRedAdmin(Admin*&, User*&, int&, int&, int&);
void openMenuRedUsers(Admin*&, User*&, int&, int&);
void addOneUser(Admin*&, User*&, int&, int&, int&);
int openMenuRedDetails(Characteristics*&, int&, User*&, int&);
int openUserMenu(Admin*&, User*&, int&, int&, Characteristics*&, int&, int);
void writeDetails(Characteristics*&, int&);
void delDetails(Characteristics*&, int&);
void showReservation(Characteristics*&, int&, User*&, int&);
void CancelReservation(User*&, int&, Characteristics*&, int&);
