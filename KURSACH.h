#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <functional>
using namespace std;
class Admin;
class User;
string writeWords();
string encpyrtPass(string);
string deencryptPass(string);
int writeDate(int, int);
class Administration {
protected:
	string login;
	string password;
public:
	virtual ~Administration() = default;
	Administration() {};
	Administration(string log, string pass) {
		login = log;
		password = pass;
	}
	virtual string GetPass() = 0;
	virtual string GetLogin() = 0;
	virtual void UpdatePass(string) = 0;
	virtual void UpdateLogin(string) = 0;
	virtual void showInfromation() = 0;
};

class UserFunc :public Administration {
public:
	UserFunc() {};
	UserFunc(string log, string pass) :Administration(log, pass) {
	}
	virtual void UpdateName(string) = 0;
	virtual void UpdateSName(string) = 0;
	virtual void UpdateGander(int) = 0;
	virtual void UpdatePhoneNumber(string) = 0;
	virtual void updateFilling(int) = 0;
	virtual void updateRoot(int) = 0;
	virtual string GetName() = 0;
	virtual string GetSName() = 0;
	virtual int getGander() = 0;
	virtual string getPhoneNumber() = 0;
	virtual int getFilling() = 0;
	virtual void UpdatePass() = 0;
	virtual int GetRoot() = 0;
};

class AdminFunc :public Administration {
public:
	AdminFunc() {};
	AdminFunc(string log, string pass) :Administration(log, pass)
	{
	}
	virtual void UpdatePass() = 0;
};

class User :public UserFunc {
private:
	string user_name;
	string user_surname;
	int gender;
	string phone_number;
	int filling;
	int root;
public:
	User() {
		user_name = "";
		user_surname = "";
		gender = 0;
		phone_number = "";
		filling = 0;
		root = 0;
	};
	User(const User& user) {
		login = user.login;
		password = user.password;
		user_name = user.user_name;
		user_surname = user.user_surname;
		gender = user.gender;
		phone_number = user.phone_number;
		filling = user.filling;
		root = user.root;
	}
	User(string log, string pass) :UserFunc(log, pass) {
		user_name = "";
		user_surname = "";
		gender = 0;
		phone_number = "";
		filling = 0;
		root = 0;
	}
	string GetLogin() {
		return login;
	}
	string GetPass() {
		return password;
	}
	void UpdateLogin(string log) {
		login = log;
	}
	void UpdatePass(string pass) {
		password = pass;
	}
	string GetName() {
		return user_name;
	}
	string GetSName() {
		return user_surname;
	}
	int getGander() {
		return gender;
	}
	string getPhoneNumber() {
		return phone_number;
	}
	int getFilling() {
		return filling;
	}
	int GetRoot() {
		return root;
	}
	void UpdateName(string ptr) {
		user_name = ptr;
	}
	void UpdateSName(string ptr) {
		user_surname = ptr;
	}

	void UpdateGander(int ptr) {
		gender = ptr;
	}
	void UpdatePhoneNumber(string ptr) {
		phone_number = ptr;
	}
	void updateFilling(int ptr) {
		filling = ptr;
	}
	void updateRoot(int ptr) {
		root = ptr;
	}
	void showInfromation() {
		cout << " Логин: " << login << endl;
		cout << " Пароль: " << password << endl;
		cout << " Имя: ";
		if (user_name.length() != 0) cout << user_name << endl;
		else cout << " Нет данных" << endl;
		cout << " Фамилия: ";
		if (user_surname.length() != 0) cout << user_surname << endl;
		else cout << " Нет данных" << endl;
		cout << " Пол: ";
		if (gender == 1) cout << " Мужской" << endl;
		else if (gender == 2) cout << " Женский" << endl;
		else cout << " Нет данных" << endl;
		cout << " Номер телефона: ";
		if (phone_number.length() != 0) cout << "+375(" << phone_number[0] << phone_number[1] << ")" << phone_number[2] << phone_number[3] <<
			phone_number[4] << phone_number[5] << phone_number[6] << phone_number[7] << phone_number[8] << endl;
		else cout << " Нет данных" << endl;
	}
	friend void writeLogin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int chois);
	void UpdatePass() {
		string pass;
		cout << "Введите Пароль: ";
		pass = writeWords();
		system("cls");
		password = pass;
	}
	void checkFilling() {
		if (user_name.length() != 0 && user_surname.length() != 0 && phone_number.length() != 0 && gender != 0)
			filling = 1;
	}
};

class Admin :public AdminFunc {
public:
	Admin() {};
	Admin(const Admin& admin) {
		login = admin.login;
		password = admin.password;
	}
	Admin(string log, string pass) :AdminFunc(log, pass) {
	}
	string GetPass() {
		return password;
	}
	string GetLogin() {
		return login;
	}
	void UpdatePass(string pass) {
		password = pass;
	}
	void UpdateLogin(string log) {
		login = log;
	}
	void showInfromation() {
		cout << " Логин: " << login << endl;
		cout << " Пароль: " << password << endl;
	}
	friend void writeLogin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int chois);
	void UpdatePass() {
		string pass;
		cout << "Введите Пароль: ";
		pass = writeWords();
		system("cls");
		password = pass;
	}
};

class FunRadioDetails
{
public:
	virtual string GetName() = 0;
	virtual int GetCost() = 0;
	virtual string GetPodtype() = 0;
	virtual string GetProviderName() = 0;
	virtual string GetProviderNumber() = 0;
	virtual string GetProviderRating() = 0;
	virtual string GetType() = 0;
	virtual string GetReleaseDate() = 0;
	virtual string GetDescription() = 0;
	virtual void UpdateName(string) = 0;
	virtual void UpdateCost(int) = 0;
	virtual void UpdatePodtype(string) = 0;
	virtual void UpdateProviderName(string) = 0;
	virtual void UpdateProviderNumber(string) = 0;
	virtual void UpdateProviderRating(string) = 0;
	virtual void UpdateType(string) = 0;
	virtual void UpdateReleaseDate(string) = 0;
	virtual void UpdateDescription(string) = 0;
	virtual int GetRoot() = 0;
	virtual void UpdateRoot(int) = 0;
};
class RadioDetails :public FunRadioDetails
{
protected:
	string name;
	int cost = 0;
	string podtype;
public:
	RadioDetails()
	{
	}
	string GetName()
	{
		return name;
	}
	void UpdateName(string NAME)
	{
		name = NAME;
	}
	int GetCost()
	{
		return cost;
	}
	void UpdateCost(int COST)
	{
		cost = COST;
	}
	string GetPodtype()
	{
		return podtype;
	}
	void UpdatePodtype(string PODTYPE)
	{
		podtype = PODTYPE;
	}
};

class Provider :public RadioDetails
{
protected:
	string provider_name;
	string provider_number;
	string provider_rating;
public:
	Provider() {}
	string GetProviderName()
	{
		return provider_name;
	}
	void UpdateProviderName(string PROVIDERNAME)
	{
		provider_name = PROVIDERNAME;
	}
	string GetProviderNumber()
	{
		return provider_number;
	}
	void UpdateProviderNumber(string NUMBER)
	{
		provider_number = NUMBER;
	}
	string GetProviderRating()
	{
		return provider_rating;
	}
	void UpdateProviderRating(string RATING)
	{
		provider_rating = RATING;
	}
};

class Characteristics :public Provider
{
private:
	string type;
	string release_date;
	string description;
	int root = -10;
public:
	Characteristics() {}
	string GetType()
	{
		return type;
	}
	string GetReleaseDate()
	{
		return release_date;
	}
	string GetDescription()
	{
		return description;
	}
	int GetRoot()
	{
		return root;
	}
	void UpdateType(string TYPE)
	{
		type = TYPE;
	}
	void UpdateReleaseDate(string RELEASE_DATE)
	{
		release_date = RELEASE_DATE;
	}
	void UpdateDescription(string DESCRIPTION)
	{
		description = DESCRIPTION;
	}
	void UpdateRoot(int ROOT)
	{
		root = ROOT;
	}
	void changeReleaseDate() {
		cout << "Введите год изготовления: ";
		int year = writeDate(2020, 4);
		cout << endl;
		cout << "Введите месяц изготовления: ";
		int month = writeDate(12, 2);
		cout << endl;
		int d;
		if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
			d = 31;
		}
		else
			if (month == 1) {
				if ((year % 4 == 0) && (year % 100 == 0)) {
					d = 29;
				}
				else
					d = 28;
			}
			else
				d = 30;
		cout << "Введите день изготовления: ";
		int day = writeDate(d, 2);
		cout << endl;
		release_date = to_string(day) + "." + to_string(month) + "." + to_string(year);
		system("cls");
	}
};

ostream& operator<<(ostream&, Admin&);
istream& operator>>(istream&, Admin&);
ostream& operator<<(ostream&, User&);
istream& operator>>(istream&, User&);
ostream& operator<<(ostream&, Characteristics&);
istream& operator>>(istream&, Characteristics&);
