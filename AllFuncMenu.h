#pragma once
#include "Correct.h"
#include "KURSACHOOP.h"
int chooseMainMenu();
int showAdminMenu();
int showMenuAdministration();
int chooseAdminsOrUsers();
int chooseAdmin(Admin*&, int&);
int chooseWhatRedAdmin(Admin*&, int);
int chooseRoot();
int chooseYesOrNot();
int chooseUser(User*&, int&);
int chooseWhatRedUser(User*&, int, int);
int chooseWhoAdd();
int chooseRedDetailsMenu();
int chooseWhatRed(Characteristics*&, int&, User*&, int&);
int chooseRedDetails(Characteristics*&, int);
int chooseProcMenu();
int chooseSort();
int chooseHowSort();
int chooseExitOfFill();
int chooseUserMenu();
int writeMenuDetails(Characteristics*&, int);
