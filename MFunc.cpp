#include "MenuFunc.h"
#include "AllFuncMenu.h"
#include "Correct.h"
#include "KURSACHOOP.h"
int openAdminMenu(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots, Characteristics*& details, int& nDetails) {
	while (true) {
		int choose = showAdminMenu();
		if (choose == 0) {
			int check = openMenuAdministration(admins, users, nAdmin, nUsers, roots);
			fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
			if (check == 4) return 4;
		}
		else
			if (choose == 1) {
				int check = openMenuRedDetails(details, nDetails, users, nUsers);
				fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
				if (check == 4) return 4;
			}
			else
				if (choose == 2) {
					int check = openProcMenu(details, nDetails, users, nUsers);
					fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
					if (check == 4) return 4;
				}
				else
					if (choose == 3) {
						return 3;
					}
					else
						if (choose == 4) {
							return 4;
						}
	}
}
void redUser(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int a) {
	while (true) {
		int choose1 = chooseWhatRedUser(users, choose, a);
		if (choose1 == 7) break;
		if (choose1 == 0) {
			writeLogin(admins, users, nAdmin, nUsers, choose, 0);
		}
		else
			if (choose1 == 1) {
				users[choose].UpdatePass();
			}
			else
				if (choose1 == 2) {
					int choose2 = chooseRoot();
					if (choose2 == 0) {
						int prov = chooseYesOrNot();
						if (prov == 0) {
							Admin admin(users[choose].GetLogin(), users[choose].GetPass());
							changeSizeAdmins(admins, nAdmin);
							admins[nAdmin - 1] = admin;
							for (int i = choose; i < nUsers - 1; i++) {
								users[i] = users[i + 1];
							}
							nUsers--;
							break;
						}
					}
				}
				else
					if (choose1 == 3) {
						string name;
						cout << "Введите Имя: ";
						name = writeNames();
						system("cls");
						users[choose].UpdateName(name);
					}
					else
						if (choose1 == 4) {
							string name;
							cout << "Введите Фамилию: ";
							name = writeNames();
							system("cls");
							users[choose].UpdateSName(name);
						}
						else

							if (choose1 == 5) {
								string Phone;
								cout << "Введите телефон: +375(";
								Phone = writePhoneNumber();
								system("cls");
								users[choose].UpdatePhoneNumber(Phone);
							}
		if (choose1 == 6) {
			int gender = getGender() + 1;
			users[choose].UpdateGander(gender);
		}
	}
}

void showOneDetail(Characteristics*& details, int choose) {
	cout << "   Имя детали:" << details[choose].GetName() << endl;
	cout << "Стоимость:" << details[choose].GetCost() << endl;
	cout << "Подтип детали:" << details[choose].GetPodtype() << endl;
	cout << "Имя поставщика:" << details[choose].GetProviderName() << endl;
	cout << "Номер поставщика:" << details[choose].GetProviderNumber() << endl;
	cout << "Рейтинг поставщика:" << details[choose].GetProviderRating() << endl;
	cout << "Тип детали:" << details[choose].GetType() << endl;
	cout << "Дата выпуска:" << details[choose].GetReleaseDate() << endl;
	cout << "Описание:" << details[choose].GetDescription() << endl;
	cout << endl;
	cout << endl;
}

void showAllDetails(Characteristics*& details, int& nDetails)
{
	for (int i = 0; i < nDetails; i++) {
		cout << "Деталь № " << i + 1 << endl;
		cout << "Имя детали:" << details[i].GetName() << endl;
		cout << "Стоимость:" << details[i].GetCost() << endl;
		cout << "Подтип радиодетали:" << details[i].GetPodtype() << endl;
		cout << "Имя поставщика:" << details[i].GetProviderName() << endl;
		cout << "Номер поставщика:" << details[i].GetProviderNumber() << endl;
		cout << "Рейтинг поставщика:" << details[i].GetProviderRating() << endl;
		cout << "Тип детали:" << details[i].GetType() << endl;
		cout << "Дата выпуска:" << details[i].GetReleaseDate() << endl;
		cout << "Описание:" << details[i].GetDescription() << endl;
		cout << endl;
		cout << endl;
	}
	if (nDetails == 0) cout << "Список радиодеталей на данный момент пуст." << endl;
	system("pause");
	system("cls");
}
void openMenuSort(Characteristics*& details, int& nDetails, User*& users, int& nUsers) {
	while (true) {
		int choose = chooseSort();
		if (choose == 0) {
			int choose1 = chooseHowSort();
			if (choose1 == 0) {
				for (int i = 0; i < nDetails; i++)
					for (int j = 0; j < nDetails - 1; j++)
						if (details[j].GetName() > details[j + 1].GetName()) {
							Characteristics a;
							a = details[j];
							details[j] = details[j + 1];
							details[j + 1] = a;
						}
			}
			else
				if (choose1 == 1) {
					for (int i = 0; i < nDetails; i++)
						for (int j = 0; j < nDetails - 1; j++)
							if (details[j].GetName() < details[j + 1].GetName()) {
								Characteristics a;
								a = details[j];
								details[j] = details[j + 1];
								details[j + 1] = a;
							}
				}
		}
		else
			if (choose == 1) {
				int choose1 = chooseHowSort();
				if (choose1 == 0) {
					for (int i = 0; i < nDetails; i++)
						for (int j = 0; j < nDetails - 1; j++)
							if (details[j].GetCost() > details[j + 1].GetCost()) {
								Characteristics a;
								a = details[j];
								details[j] = details[j + 1];
								details[j + 1] = a;
							}
				}
				else
					if (choose1 == 1) {
						for (int i = 0; i < nDetails; i++)
							for (int j = 0; j < nDetails - 1; j++)
								if (details[j].GetCost() < details[j + 1].GetCost()) {
									Characteristics a;
									a = details[j];
									details[j] = details[j + 1];
									details[j + 1] = a;
								}
					}
			}
			else
				if (choose == 2) {
					int choose1 = chooseHowSort();
					if (choose1 == 0) {
						for (int i = 0; i < nDetails; i++)
							for (int j = 0; j < nDetails - 1; j++)
								if (details[j].GetPodtype() > details[j + 1].GetPodtype()) {
									Characteristics a;
									a = details[j];
									details[j] = details[j + 1];
									details[j + 1] = a;
								}
					}
					else
						if (choose1 == 1) {
							for (int i = 0; i < nDetails; i++)
								for (int j = 0; j < nDetails - 1; j++)
									if (details[j].GetPodtype() > details[j + 1].GetPodtype()) {
										Characteristics a;
										a = details[j];
										details[j] = details[j + 1];
										details[j + 1] = a;
									}
						}
				}
				else break;
	}
}
int openProcMenu(Characteristics*& details, int& nDetails, User*& users, int& nUsers) {
	while (true) {
		int choose = chooseProcMenu();
		if (choose == 4) break;
		if (choose == 5) return 4;
		if (choose == 0) {
			showReservation(details, nDetails, users, nUsers);
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				cout << "Введите логин пользователя: ";
				string log = writeWords();
				cout << endl;
				int check = 0;
				for (int i = 0; i < nUsers; i++)
					if (users[i].GetLogin() == log) {
						check = 1;
						for (int j = 0; j < nDetails; j++)
							if (users[i].GetRoot() == details[j].GetRoot()) {
								showOneDetail(details, j);
								check = 2;
							}
						break;
					}
				if (check == 0) cout << "Такого пользователя не существует." << endl;
				else
					if (check == 1) cout << "Данный пользователь еще не забронировал деталь." << endl;
				system("pause");
				system("cls");
			}
			else
				if (choose == 3) {
					openMenuSort(details, nDetails, users, nUsers);
				}
				else
					if (choose == 2)
					{
						CancelReservation(users, nUsers, details, nDetails);
					}
	}
	return 0;
}

void addOneDetails(Characteristics*& details, int& nDetails) {
	changeSizeDetails(details, nDetails);
	string s;
	int s1;
	cout << "Введите название радиодетали: ";
	s = writeUniversal();
	details[nDetails - 1].UpdateName(s);
	system("cls");
	cout << "Введите стоимость: ";
	s1 = getInt();
	details[nDetails - 1].UpdateCost(s1);
	system("cls");
	cout << "Введите подтип детали: ";
	s = writeUniversal();
	details[nDetails - 1].UpdatePodtype(s);
	system("cls");
	cout << "Введите имя поставщика: ";
	s = writeUniversal();
	details[nDetails - 1].UpdateProviderName(s);
	system("cls");
	cout << "Введите номер поставщика: +375(";
	s = writePhoneNumber();
	details[nDetails - 1].UpdateProviderNumber(s);
	system("cls");
	cout << "Введите рейтинг поставщика: ";
	s = writeUniversal();
	details[nDetails - 1].UpdateProviderRating(s);
	system("cls");
	cout << "Введите тип радиодетали: ";
	s = writeUniversal();
	details[nDetails - 1].UpdateType(s);
	system("cls");
	details[nDetails - 1].changeReleaseDate();
	system("cls");
	cout << "Введите описание: ";
	s = writeUniversal();
	details[nDetails - 1].UpdateDescription(s);
	system("cls");
}

int openMenuAdministration(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
	while (true) {
		int choose = showMenuAdministration();
		if (choose == 0) {
			showUsers(admins, users, nAdmin, nUsers);
		}
		else
			if (choose == 1) {
				changeMenuUsers(admins, users, nAdmin, nUsers, roots);
			}
			else
				if (choose == 2) {
					addOneUser(admins, users, nAdmin, nUsers, roots);
				}
				else
					if (choose == 3) {
						ofstream fout;
						fout.open("D:\\ADMINS.txt");
						for (int i = 0; i < nAdmin; i++) {
							fout << admins[i];
						}
						fout << nAdmin << endl;
						fout.close();
						fout.open("D:\\USERS.txt");
						for (int i = 0; i < nUsers; i++) {
							fout << users[i];
						}
						fout << nUsers << endl;
						fout.close();
					}
					else
						if (choose == 4) {
							return 0;
						}
						else
							if (choose == 5) {
								return 4;
							}
	}
}

void changeMenuUsers(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
	while (true) {
		int choose = chooseAdminsOrUsers();
		if (choose == 0) {
			openMenuRedAdmin(admins, users, nAdmin, nUsers, roots);
		}
		else
			if (choose == 1) {
				openMenuRedUsers(admins, users, nAdmin, nUsers);
			}
			else
				if (choose == 2) break;
	}
}

void showUsers(Admin*& admins, User*& users, int& nAdmin, int& nUsers) {
	if (nAdmin != 0)
	{
		cout << "       Админиcтраторы: " << endl;
		for (int i = 0; i < nAdmin; i++) {
			admins[i].showInfromation();
			cout << endl;
		}
	}
	if (nUsers != 0) {
		cout << "       Пользователи: " << endl;
		for (int i = 0; i < nUsers; i++) {
			users[i].showInfromation();
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

void openMenuRedAdmin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
	while (true) {
		int choose = chooseAdmin(admins, nAdmin);
		if (choose == nAdmin) break;
		else {
			while (true) {
				int choose1 = chooseWhatRedAdmin(admins, choose);
				if (choose1 == 3) break;
				else
					if (choose1 == 0) {
						writeLogin(admins, users, nAdmin, nUsers, choose, 1);
					}
					else
						if (choose1 == 1) {
							admins[choose].UpdatePass();
						}
						else
							if (choose1 == 2) {
								int choose2 = chooseRoot();
								if (choose2 == 1) {
									int prov = chooseYesOrNot();
									if (prov == 0) {
										changeSizeUsers(users, nUsers);
										users[nUsers - 1].UpdateLogin(admins[choose].GetLogin());
										users[nUsers - 1].UpdatePass(admins[choose].GetPass());
										for (int i = choose; i < nAdmin - 1; i++)
											admins[i] = admins[i + 1];
										nAdmin--;
										break;
									}
								}
							}
			}
		}
	}
}

void openMenuRedUsers(Admin*& admins, User*& users, int& nAdmin, int& nUsers) {
	while (true) {
		int choose = chooseUser(users, nUsers);
		if (choose == nUsers) break;
		else {
			redUser(admins, users, nAdmin, nUsers, choose, 0);
		}
	}
}

void addOneUser(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
	while (true) {
		int choose = chooseWhoAdd();
		if (choose == 2) break;
		Admin admin;
		User user;
		if (choose == 0) {
			changeSizeAdmins(admins, nAdmin);
			admins[nAdmin - 1] = admin;
			writeLogin(admins, users, nAdmin, nUsers, nAdmin - 1, 1);
			admins[nAdmin - 1].UpdatePass();
		}
		else
			if (choose == 1) {
				changeSizeUsers(users, nUsers);
				users[nUsers - 1] = user;
				writeLogin(admins, users, nAdmin, nUsers, nUsers - 1, 0);
				users[nUsers - 1].UpdatePass();
				users[nUsers - 1].updateRoot(roots);
				roots++;
			}
	}
}

int openMenuRedDetails(Characteristics*& details, int& nDetails, User*& users, int& nUsers) {
	while (true) {
		int choose = chooseRedDetailsMenu();
		if (choose == 5) return 4;
		if (choose == 4) break;
		if (choose == 0)
		{
			writeDetails(details, nDetails);
		}
		else
			if (choose == 1) {
				addOneDetails(details, nDetails);
			}
			else
				if (choose == 2) {
					showAllDetails(details, nDetails);
				}
				else
					if (choose == 3)
					{
						delDetails(details, nDetails);
					}
	}
	return 0;
}

int openUserMenu(Admin*& admins, User*& users, int& nAdmin, int& nUsers, Characteristics*& details, int& nDetails, int choose) {
	while (true) {
		if (users[choose].getFilling() == 0) {
			int choose1 = chooseExitOfFill();
			if (choose1 == 1) return 3;
			else {
				redUser(admins, users, nUsers, nAdmin, choose, 1);
				users[choose].checkFilling();
			}
			fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
		}
		else {
			while (true) {
				int choose1 = chooseUserMenu();
				if (choose1 == 1) {
					for (int i = 0; i < nDetails; i++)
						if (users[choose].GetRoot() == details[i].GetRoot()) {
							showOneDetail(details, i);
						}
					system("pause");
					system("cls");
				}
				else
					if (choose1 == 0) {
						showAllDetails(details, nDetails);
					}
					else
						if (choose1 == 2) {
							while (true) {
								int choose2 = writeMenuDetails(details, nDetails);
								if (choose2 == nDetails) break;
								if (details[choose2].GetRoot() != -10) cout << "Эта деталь уже забронированна!";
								else {
									details[choose2].UpdateRoot(users[choose].GetRoot());
									cout << "Деталь забронированна!";
								}
								system("pause");
								system("cls");
							}
							fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
						}
						else
							if (choose1 == 3)
							{
								cout << "Введите точное имя детали которое отменить: ";
								string s = writeUniversal();
								int check = 0;
								for (int i = 0; i < nDetails; i++)
									if ((s == details[i].GetName()) && (users[choose].GetRoot() == details[i].GetRoot())) {
										details[i].UpdateRoot(-10);
										check = 1;
									}
								if (check == 0) cout << "Такой детали вы не заказывали!" << endl;
								else
									cout << "Заказ отменен." << endl;
								system("pause");
								system("cls");
								fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
							}
							else
								if (choose1 == 4) {
									users[choose].showInfromation();
									system("pause");
									system("cls");
									fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
								}
								else
									if (choose1 == 5) {
										redUser(admins, users, nAdmin, nUsers, choose, 1);
										fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
									}
									else
										if (choose1 == 6) return 3;
										else
											if (choose1 == 7) return 4;
			}
		}
	}
	return 0;
}
void CancelReservation(User*& users, int& nUsers, Characteristics*& details, int& nDetails)
{
	cout << "Введите точное имя детали, бронирование которой хотите отменить: ";
	string s = writeUniversal();
	int check = 0;
	for (int i = 0; i < nDetails; i++)
		if (s == details[i].GetName()) {
			details[i].UpdateRoot(-10);
			check = 1;
		}
	if (check == 0) cout << "Такой детали не заказывали!" << endl;
	else
		cout << "Заказ отменен." << endl;
	system("pause");
	system("cls");
}
void writeDetails(Characteristics*& details, int& nDetails)
{
	while (true) {
		int choose = writeMenuDetails(details, nDetails);
		if (choose == nDetails) break;
		while (true) {
			string s;
			int s1;
			int choose1 = chooseRedDetails(details, choose);
			if (choose1 == 9) break;
			if (choose1 == 0) {
				cout << "Введите название радиодетали: ";
				s = writeUniversal();
				details[nDetails - 1].UpdateName(s);
				system("cls");
			}
			else
				if (choose1 == 1) {
					cout << "Введите стоимость: ";
					s1 = getInt();
					details[choose].UpdateCost(s1);
					system("cls");
				}
				else
					if (choose1 == 2) {
						cout << "Введите подтип детали: ";
						s = writeUniversal();
						details[choose].UpdatePodtype(s);
						system("cls");
					}
					else
						if (choose1 == 3) {
							cout << "Введите имя поставщика: ";
							s = writeUniversal();
							details[choose].UpdateProviderName(s);
							system("cls");
						}
						else
							if (choose1 == 4) {
								cout << "Введите номер поставщика: +375(";
								s = writePhoneNumber();
								details[choose].UpdateProviderNumber(s);
								system("cls");
							}
							else
								if (choose1 == 5) {
									cout << "Введите рейтинг поставщика: ";
									s = writeUniversal();
									details[choose].UpdateProviderRating(s);
									system("cls");
								}
								else
									if (choose1 == 6) {
										cout << "Введите тип радиодетали: ";
										s = writeUniversal();
										details[choose].UpdateType(s);
										system("cls");
									}
									else
										if (choose1 == 7) {
											details[choose].changeReleaseDate();
											system("cls");
										}
										else
											if (choose1 == 8) {
												cout << "Введите описание: ";
												s = writeUniversal();
												details[choose].UpdateDescription(s);
												system("cls");
											}
		}
	}
}

void delDetails(Characteristics*& details, int& nDetails)
{
	showAllDetails(details, nDetails);
	int number = 0, q = 0;
	string dname;
	if (nDetails > 0)
	{
		cout << "Введите название детали,которую хотите удалить:";
		dname = writeUniversal();
		for (int i = 0; i < nDetails; i++)
		{
			if (dname == details[i].GetName())
			{
				q++;
				number = i;
				break;
			}
		}
		if (q == 0)
		{
			cout << "Детали с таким название отсутсвуют,проверьте введенные данные!";
		}
		else
		{
			for (int i = number; i < nDetails - 1; i++)
			{
				details[i] = details[i + 1];
			}
			cout << "Деталь успешно удалена!";
			nDetails--;
		}
	}
	else
	{
		cout << "Список деталей пуст!";
	}
}
void showReservation(Characteristics*& details, int& nDetails, User*& users, int& nUsers)
{
	for (int i = 0; i < nUsers; i++)
	{
		for (int j = 0; j < nDetails; j++)
		{
			if (details[j].GetRoot() == users[i].GetRoot())
			{
				cout << "Имя пользователя:" << users[i].GetLogin() << endl;
				cout << "Название забронированной детали:" << details[j].GetName() << endl;
				cout << endl;
			}
		}
	}
}
