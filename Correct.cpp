#include "Correct.h"

void CONSOLE_SETTING()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
void fillFiles(Admin*& admins, User*& users, Characteristics*& details, int& nAdmin, int& nUsers, int& nDetails) {
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
	fout.open("D:\\DETAILS.txt");
	for (int i = 0; i < nDetails; i++) {
		fout << details[i];
	}
	fout << nDetails << endl;
	fout.close();
}
void CreateFiles() {
	ifstream check;
	ofstream of;
	check.open("D:\\ADMINS.txt");
	if (!check.is_open()) {
		of.open("D:\\ADMINS.txt");
		of << "0" << endl;
		of.close();
	}
	check.close();
	check.open("D:\\USERS.txt");
	if (!check.is_open()) {
		of.open("D:\\USERS.txt");
		of << "0" << endl;
		of.close();
	}
	check.close();
	check.open("D:\\DETAILS.txt");
	if (!check.is_open()) {
		of.open("D:\\DETAILS.txt");
		of << "0" << endl;
		of.close();
	}
	check.close();
}

void fillSize(int& nAdmins, int& nUsers, int& nDetails)
{
	ifstream check;
	check.open("D:\\ADMINS.txt");
	check.seekg(-3, ios::end);
	check >> nAdmins;
	check.close();
	check.open("D:\\USERS.txt");
	check.seekg(-3, ios::end);
	check >> nUsers;
	check.close();
	check.open("D:\\DETAILS.txt");
	check.seekg(-3, ios::end);
	check >> nDetails;
	check.close();
}

string writeNames() {
	string word;
	int Knopka;
	char symbol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() != 0) break;
			else {
				symbol = (char)Knopka;
				if ((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я')) {
					word = word + symbol;
					cout << symbol;
				}
			}
	}
	cout << endl;
	return word;
}

string writePhoneNumber() {
	string str;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (str.length() != 0) {
					cout << '\b' << " " << '\b';
					str.erase(str.length() - 1);
					if (str.length() == 1) cout << '\b' << " " << '\b';
				}
			}
			else
				if (key == 13 && str.length() == 9) break;
				else
					if (key >= '0' && key <= '9' && str.length() < 9) {
						str = str + (char)key;
						cout << (char)key;
						if (str.length() == 2) cout << ")";
					}
	}
	return str;
}
void setColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int getGender() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Мужской" << endl; setColor(15, 0); }
		else cout << " Мужской" << endl;
		if (choose_menu == 1) { setColor(2, 0); cout << " -> Женский" << endl; setColor(15, 0); }
		else cout << " Женский" << endl;
		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

void changeSizeUsers(User*& users, int& nUsers) {
	nUsers++;
	User* ptr = new User[nUsers];
	for (int i = 0; i < nUsers - 1; i++)
		ptr[i] = users[i];
	users = ptr;
	ptr = NULL;
	delete[]ptr;
}

void changeSizeAdmins(Admin*& admins, int& nAdmin) {
	nAdmin++;
	Admin* ptr = new Admin[nAdmin];
	for (int i = 0; i < nAdmin - 1; i++)
		ptr[i] = admins[i];
	admins = ptr;
	ptr = NULL;
	delete[]ptr;
}

void changeSizeDetails(Characteristics*& details, int& nDetails) {
	nDetails++;
	Characteristics* ptr = new Characteristics[nDetails];
	for (int i = 0; i < nDetails - 1; i++)
		ptr[i] = details[i];
	details = ptr;
	ptr = NULL;
	delete[]ptr;
}

string writePassword() {
	string str;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (str.length() != 0) {
					cout << '\b' << " " << '\b';
					str.erase(str.length() - 1);
				}
			}
			else
				if (key == 13 && str.length() != 0) break;
				else
					if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')) {
						str = str + (char)key;
						cout << "*";
					}
	}
	return str;
}

int fillClasses(Admin*& admins, User*& users, Characteristics*& details, int& nAdmin, int& nUsers, int& nDetails, int& roots) {
	ifstream fin;
	fin.open("D:\\ADMINS.txt");
	Admin admin;
	if (fin.peek() != EOF) {
		for (int i = 0; i < nAdmin; i++) {
			fin >> admin;
			admins[i] = admin;
		}
	}
	fin.close();
	fin.open("D:\\USERS.txt");
	User user;
	if (fin.peek() != EOF) {
		for (int i = 0; i < nUsers; i++) {
			fin >> user;
			users[i] = user;
			roots = max(roots, users[i].GetRoot());
		}
	}
	fin.close();
	fin.open("D:\\DETAILS.txt");
	Characteristics detail;
	if (fin.peek() != EOF) {
		for (int i = 0; i < nDetails; i++) {
			fin >> detail;
			details[i] = detail;
		}
	}
	fin.close();
	return roots;
}

string writeUniversal() {
	string word;
	int Knopka;
	char symbol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() != 0) break;
			else {
				symbol = (char)Knopka;
				if ((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я') || symbol == ' ' || symbol == '.' || symbol == '"' || symbol == '-' || symbol == '+' || symbol == ',' || (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
					word = word + symbol;
					cout << symbol;
				}
			}
	}
	cout << endl;
	return word;
}
