#include "KURSACHOOP.h"
#include "AllFuncMenu.h"
#include "Correct.h"
#include "MenuFunc.h"
string writeWords() {
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
						cout << (char)key;
					}
	}
	return str;
}
void writeLogin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int chois) {
	string log;
	int check = 0;
	while (true) {
		cout << "Введите Логин: ";
		log = writeWords();
		for (int i = 0; i < nAdmin; i++)
			if (admins[i].GetLogin() == log && i != choose) {
				check = 1;
				break;
			}
		for (int i = 0; i < nUsers; i++)
			if (users[i].GetLogin() == log) {
				check = 1;
				break;
			}
		if (log == "oleg") check = 1;
		if (check == 0) break;
		system("cls");
		check = 0;
		cout << "Такой логин уже существует!!!" << endl;
	}
	system("cls");
	if (chois == 0) {
		users[choose].login = log;
	}
	else
		admins[choose].login = log;
}

ostream& operator<<(ostream& os, Admin& admin) {
	os << admin.GetLogin() << endl << encpyrtPass(admin.GetPass()) << endl;
	return os;
}

istream& operator>>(istream& is, Admin& admin) {
	string s;
	getline(is, s);
	admin.UpdateLogin(s);
	getline(is, s);
	admin.UpdatePass(deencryptPass(s));
	return is;
}

istream& operator>>(istream& is, User& user) {
	string s;
	getline(is, s);
	user.UpdateLogin(s);
	getline(is, s);
	user.UpdatePass(deencryptPass(s));
	getline(is, s);
	user.UpdateName(s);
	getline(is, s);
	user.UpdateSName(s);
	getline(is, s);
	user.UpdateGander(stoi(s));
	getline(is, s);
	user.UpdatePhoneNumber(s);
	getline(is, s);
	user.updateFilling(stoi(s));
	getline(is, s);
	user.updateRoot(stoi(s));
	return is;
}

ostream& operator<<(ostream& os, User& user) {
	os << user.GetLogin() << endl << encpyrtPass(user.GetPass()) << endl << user.GetName() << endl;
	os << user.GetSName() << endl << user.getGander() << endl;
	os << user.getPhoneNumber() << endl << user.getFilling() << endl;
	os << user.GetRoot() << endl;
	return os;
}

ostream& operator<<(ostream& out, Characteristics& details) {
	out << details.GetName() << endl << details.GetCost() << endl << details.GetPodtype() << endl;
	out << details.GetProviderName() << endl << details.GetProviderNumber() << endl << details.GetProviderRating() << endl;
	out << details.GetType() << endl << details.GetReleaseDate() << endl << details.GetDescription() << endl;
	out << details.GetRoot() << endl;
	return out;
}

istream& operator>>(istream& in, Characteristics& details) {
	string s;
	getline(in, s);
	details.UpdateName(s);
	getline(in, s);
	details.UpdateCost(stoi(s));
	getline(in, s);
	details.UpdatePodtype(s);
	getline(in, s);
	details.UpdateProviderName(s);
	getline(in, s);
	details.UpdateProviderNumber(s);
	getline(in, s);
	details.UpdateProviderRating(s);
	getline(in, s);
	details.UpdateType(s);
	getline(in, s);
	details.UpdateReleaseDate(s);
	getline(in, s);
	details.UpdateDescription(s);
	getline(in, s);
	details.UpdateRoot(stoi(s));
	return in;
}

int main()
{
	CONSOLE_SETTING();
	ifstream check;
	ofstream of;
	CreateFiles();
	string login = "daniil";
	string password = "12345678";
	int nAdmin = 0;
	int nUsers = 0;
	int nDetails = 0;
	fillSize(nAdmin, nUsers, nDetails);
	Admin* admins = new Admin[nAdmin];
	User* users = new User[nUsers];
	Characteristics* details = new Characteristics[nDetails];
	int roots = 0;
	roots = fillClasses(admins, users, details, nAdmin, nUsers, nDetails, roots);
	while (true)
	{
		int checks = 0;
		int choose = chooseMainMenu();
		if (choose == 0) {
			int check = 0;
			string log, pass;
			cout << "Введите логин: ";
			log = writeWords();
			cout << endl;
			cout << "Введите пароль: ";
			pass = writePassword();
			system("cls");
			if (log == login && pass == password) {
				checks = openAdminMenu(admins, users, nAdmin, nUsers, roots, details, nDetails);
				check = 1;
			}
			else {
				if (check == 0) {
					for (int i = 0; i < nAdmin; i++)
						if (admins[i].GetLogin() == log && admins[i].GetPass() == pass) {
							checks = openAdminMenu(admins, users, nAdmin, nUsers, roots, details, nDetails);
							check = 1;
							break;
						}
				}
				if (check == 0) {
					for (int i = 0; i < nUsers; i++)
						if (users[i].GetLogin() == log && users[i].GetPass() == pass) {
							checks = openUserMenu(admins, users, nAdmin, nUsers, details, nDetails, i);
							check = 1;
							break;
						}
				}
			}
			if (checks == 4 && check == 1) break;
			if (checks != 3) {
				cout << "Вы ввели неверный логин или пароль." << endl;
				cout << "Попробуйте еще раз." << endl;
				system("pause");
			}
			system("cls");
		}
		else
			if (choose == 1) {
				string log, pass;
				int check = 0;
				while (true) {
					cout << "Введите логин: ";
					log = writeWords();
					for (int i = 0; i < nAdmin; i++)
						if (admins[i].GetLogin() == log) {
							check = 1;
							break;
						}
					for (int i = 0; i < nUsers; i++)
						if (users[i].GetLogin() == log) {
							check = 1;
							break;
						}
					if (log == login) {
						check = 1;
					}
					if (check == 0) break;
					system("cls");
					check = 0;
					cout << "Такой логин уже существует!!!" << endl;
				}
				cout << endl;
				cout << "Введите пароль: ";
				pass = writePassword();
				User user(log, pass);
				changeSizeUsers(users, nUsers);
				users[nUsers - 1] = user;
				users[nUsers - 1].updateRoot(roots + 1);
				roots++;
				system("cls");
			}
			else
				break;
	}
	fillFiles(admins, users, details, nAdmin, nUsers, nDetails);
	delete[]details;
	delete[]admins;
	delete[]users;
}
int writeDate(int ch, int siz) {
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
				if (key == 13 && str.length() <= siz && stoi(str) <= ch && str.length() != 0) break;
				else
					if (key >= '0' && key <= '9' && str.length() < siz) {
						str = str + (char)key;
						cout << (char)key;
					}
	}
	return stoi(str);
}

string encpyrtPass(string pass)
{
	string encpyrt;
	for (int i = 0; i < pass.length(); i++)
	{
		char c = pass[i];
		c = c + '*';
		encpyrt.push_back(c);
	}
	return encpyrt;
}

string deencryptPass(string encrypt)
{
	string deencrypt;
	for (int i = 0; i < encrypt.length(); i++)
	{
		char c = encrypt[i];
		c = c - '*';
		deencrypt.push_back(c);
	}
	return deencrypt;
}
