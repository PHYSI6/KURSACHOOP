#include "AllFuncMenu.h"

int chooseMainMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 3) % 3;
		if (choose_menu == 0) { setColor(2, 0); cout << " -> Войти в аккаунт" << endl; setColor(15, 0); }
		else cout << " Войти в аккаунт" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Создать новый аккаунт" << endl; setColor(15, 0); }
		else cout << " Создать новый аккаунт" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
		else { cout << " Выйти из программы" << endl; }

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

int showAdminMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Здраствуйте, администратор!" << endl;
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Работа с учетными записями" << endl; setColor(15, 0); }
		else cout << " Работа с учетными записями" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Работа с радиодеталями" << endl; setColor(15, 0); }
		else cout << " Работа с радиодеталями" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Просмотр и поиск данных о радиодеталях" << endl; setColor(15, 0); }
		else { cout << " Просмотр и поиск данных о радиодеталях" << endl; }

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
		else { cout << " Выход в главное меню" << endl; }

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
		else { cout << " Выйти из программы" << endl; }

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

int showMenuAdministration() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 6) % 6;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр учетных записей" << endl; setColor(15, 0); }
		else cout << " Просмотр учетных записей" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Редактирование учетных записей" << endl; setColor(15, 0); }
		else cout << " Редактирование учетных записей" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Добавление учетной записи" << endl; setColor(15, 0); }
		else { cout << " Добавление учетной записи" << endl; }

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Сохранить информацию" << endl; setColor(15, 0); }
		else { cout << " Сохранить информацию" << endl; }

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Выход в меню администратора" << endl; setColor(15, 0); }
		else { cout << " Выход в меню администратора" << endl; }

		if (choose_menu == 5) { setColor(2, 0); cout << " -> Выйти из программы и сохранить информацию" << endl; setColor(15, 0); }
		else { cout << " Выйти из программы и сохранить информацию" << endl; }

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

int chooseAdminsOrUsers() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 3) % 3;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Редактировать администраторов" << endl; setColor(15, 0); }
		else cout << " Редактировать администраторов" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Редактировать пользователей" << endl; setColor(15, 0); }
		else cout << " Редактировать пользователей" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Выход в меню администратора" << endl; setColor(15, 0); }
		else { cout << " Выход в меню администратора" << endl; }

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

int chooseAdmin(Admin*& admins, int& nAdmin) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nAdmin + 1)) % (nAdmin + 1);

		for (int i = 0; i < nAdmin; i++)
			if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << admins[i].GetLogin() << endl; setColor(15, 0); }
			else { cout << " " << i + 1 << " - " << admins[i].GetLogin() << endl; }

		if (choose_menu == nAdmin) { setColor(2, 0); cout << " -> Выйти с выбора администратора" << endl; setColor(15, 0); }
		else cout << " Выйти с выбора администратора" << endl;

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

int chooseWhatRedAdmin(Admin*& admins, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Логин: " << admins[choose].GetLogin() << endl; setColor(15, 0); }
		else cout << " Логин: " << admins[choose].GetLogin() << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Пароль: " << admins[choose].GetPass() << endl; setColor(15, 0); }
		else cout << " Пароль: " << admins[choose].GetPass() << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Права: Администратор" << endl; setColor(15, 0); }
		else { cout << " Права: Администратор" << endl; }

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Выход в меню выбора администратора" << endl; setColor(15, 0); }
		else { cout << " Выход в меню выбора администратора" << endl; }

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

int chooseRoot() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 3) % 3;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Администратор" << endl; setColor(15, 0); }
		else cout << " Администратор" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Пользователь" << endl; setColor(15, 0); }
		else cout << " Пользователь" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Выход из меню выбора прав" << endl; setColor(15, 0); }
		else { cout << " Выход из меню выбора прав" << endl; }

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

int chooseYesOrNot() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		cout << "Вы уверены что хотите сменить права?" << endl;
		cout << "Тогда пользователь исчезнет из меню данного выбора." << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Да" << endl; setColor(15, 0); }
		else cout << " Да" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Нет" << endl; setColor(15, 0); }
		else cout << " Нет" << endl;

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

int chooseUser(User*& users, int& nUsers) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пользователя" << endl;
		choose_menu = (choose_menu + (nUsers + 1)) % (nUsers + 1);

		for (int i = 0; i < nUsers; i++)
			if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << users[i].GetLogin() << endl; setColor(15, 0); }
			else { cout << " " << i + 1 << " - " << users[i].GetLogin() << endl; }

		if (choose_menu == nUsers) { setColor(2, 0); cout << " -> Выйти с выбора пользователя" << endl; setColor(15, 0); }
		else cout << " Выйти с выбора пользователя" << endl;

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

int chooseWhatRedUser(User*& users, int choose, int a) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 8) % 8;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Логин: " << users[choose].GetLogin() << endl; setColor(15, 0); }
		else cout << " Логин: " << users[choose].GetLogin() << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Пароль: " << users[choose].GetPass() << endl; setColor(15, 0); }
		else cout << " Пароль: " << users[choose].GetPass() << endl;

		if (a == 0) {
			if (choose_menu == 2) { setColor(2, 0); cout << " -> Права: Пользователь" << endl; setColor(15, 0); }
			else { cout << " Права: Пользователь" << endl; }
		}

		if (choose_menu == 3) {
			setColor(2, 0);
			if (users[choose].GetName().length() != 0) cout << " -> Имя: " << users[choose].GetName() << endl;
			else cout << " -> Имя: Нет данных" << endl;
			setColor(15, 0);
		}
		else {
			if (users[choose].GetName().length() != 0) cout << " Имя: " << users[choose].GetName() << endl;
			else cout << " Имя: Нет данных" << endl;
		}

		if (choose_menu == 4) {
			setColor(2, 0);
			if (users[choose].GetSName().length() != 0) cout << " -> Фамилия: " << users[choose].GetSName() << endl;
			else cout << " -> Фамилия: Нет данных" << endl;
			setColor(15, 0);
		}
		else {
			if (users[choose].GetSName().length() != 0) cout << " Фамилия: " << users[choose].GetSName() << endl;
			else cout << " Фамилия: Нет данных" << endl;
		}

		if (choose_menu == 5) {
			setColor(2, 0);
			if (users[choose].getPhoneNumber().length() != 0) cout << " -> Номер телефона: +375" << users[choose].getPhoneNumber() << endl;
			else cout << " -> Номер телефона: Нет данных" << endl;
			setColor(15, 0);
		}
		else {
			if (users[choose].getPhoneNumber().length() != 0) cout << " Номер телефона: +375" << users[choose].getPhoneNumber() << endl;
			else cout << " Номер телефона: Нет данных" << endl;
		}

		if (choose_menu == 6) {
			setColor(2, 0);
			if (users[choose].getGander() == 1) cout << " -> Пол: Мужской" << endl;
			else
				if (users[choose].getGander() == 2) cout << " -> Пол: Женский" << endl;
				else cout << " -> Пол: Нет данных" << endl;
			setColor(15, 0);
		}
		else {
			if (users[choose].getGander() == 1) cout << " Пол: Мужской" << endl;
			else
				if (users[choose].getGander() == 2) cout << " Пол: Женский" << endl;
				else cout << " Пол: Нет данных" << endl;
		}

		if (choose_menu == 7) { setColor(2, 0); cout << " -> Выход назад" << endl; setColor(15, 0); }
		else { cout << " Выход назад" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) {
				choose_menu--;
				if (a == 1 && choose_menu == 2) choose_menu--;
			}
			if (keyboard_button == 80) {
				choose_menu++;
				if (a == 1 && choose_menu == 2) choose_menu++;
			}
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhoAdd() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 3) % 3;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Добавить администратора" << endl; setColor(15, 0); }
		else cout << " Добавить администратора" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Добавить пользователя" << endl; setColor(15, 0); }
		else cout << " Добавить пользователя" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Выход в меню администратора" << endl; setColor(15, 0); }
		else { cout << " Выход в меню администратора" << endl; }

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

int chooseRedDetailsMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 6) % 6;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Редактирование данных о радиодеталях" << endl; setColor(15, 0); }
		else cout << " Редактирование данных о радиодеталях" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Добавление радиодеталей в базу" << endl; setColor(15, 0); }
		else cout << " Добавление радиодеталей в базу" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Просмотр всех радиодеталей" << endl; setColor(15, 0); }
		else { cout << " Просмотр всех радиодеталей" << endl; }

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Удаление радиодеталей" << endl; setColor(15, 0); }
		else { cout << " Удаление радиодеталей" << endl; }

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
		else { cout << " Выход в главное меню" << endl; }

		if (choose_menu == 5) { setColor(2, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
		else { cout << " Выйти из программы" << endl; }

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

int chooseWhatRed(Characteristics*& Details, int& nDetails, User*& users, int& nUsers) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nDetails + 1)) % (nDetails + 1);
		for (int i = 0; i < nDetails; i++)
			if (i == choose_menu) {
				int ij = 0;
				setColor(2, 0);
				for (int j = 0; j < nUsers; j++)
					if (users[j].GetRoot() == Details[i].GetRoot()) { ij = j; break; }
				cout << " -> " << i + 1 << " - " << users[ij].GetLogin() << ". Радиодеталь " << Details[i].GetName() << endl;
				setColor(15, 0);
			}
			else {
				int ij = 0;
				for (int j = 0; j < nUsers; j++)
					if (users[j].GetRoot() == Details[i].GetRoot()) { ij = j; break; }
				cout << " " << i + 1 << " - " << users[ij].GetLogin() << ". Радиодеталь " << Details[i].GetName() << endl;
			}

		if (choose_menu == nDetails) { setColor(4, 0); cout << " -> Выйти с выбора пользователя" << endl; setColor(15, 0); }
		else cout << " Выйти с выбора пользователя" << endl;

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

int chooseRedDetails(Characteristics*& details, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 10) % 10;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Название: " << details[choose].GetName() << endl; setColor(15, 0); }
		else cout << " Название: " << details[choose].GetName() << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Стоимость: " << details[choose].GetCost() << endl; setColor(15, 0); }
		else cout << " Стоимость: " << details[choose].GetCost() << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Подтип радиодетали: " << details[choose].GetPodtype() << endl; setColor(15, 0); }
		else cout << "Подтип радиодетали: " << details[choose].GetPodtype() << endl;

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Поставщик: " << details[choose].GetProviderName() << endl; setColor(15, 0); }
		else cout << " Поставщик: " << details[choose].GetProviderName() << endl;

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Номер поставщика: " << details[choose].GetProviderNumber() << endl; setColor(15, 0); }
		else cout << " Номер поставщика: " << details[choose].GetProviderNumber() << endl;

		if (choose_menu == 5) { setColor(2, 0); cout << " -> Рейтинг поставщика: " << details[choose].GetProviderRating() << endl; setColor(15, 0); }
		else cout << " Рейтинг поставщика: " << details[choose].GetProviderRating() << endl;

		if (choose_menu == 6) { setColor(2, 0); cout << " -> Тип радиодетали: " << details[choose].GetType() << endl; setColor(15, 0); }
		else cout << " Тип радиодетали: " << details[choose].GetType() << endl;

		if (choose_menu == 7) { setColor(2, 0); cout << " -> Дата производста: " << details[choose].GetReleaseDate() << endl; setColor(15, 0); }
		else cout << " Дата производства: " << details[choose].GetReleaseDate() << endl;

		if (choose_menu == 8) { setColor(2, 0); cout << " -> Описание: " << details[choose].GetDescription() << endl; setColor(15, 0); }
		else cout << " Описание: " << details[choose].GetDescription() << endl;

		if (choose_menu == 9) { setColor(2, 0); cout << " -> Выход в меню выбора радиодетали" << endl; setColor(15, 0); }
		else { cout << " Выход в меню выбора радиодетали" << endl; }

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

int chooseProcMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 6) % 6;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр всех бронирований" << endl; setColor(15, 0); }
		else cout << " Просмотр всех бронирований" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Поиск всех бронирований пользователя" << endl; setColor(15, 0); }
		else cout << " Поиск всех бронирований пользователя" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " ->Отмена бронирований пользователей" << endl; setColor(15, 0); }
		else cout << " Отмена бронирований пользователя" << endl;

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Сортировать бронирования" << endl; setColor(15, 0); }
		else { cout << " Сортировать бронирования" << endl; }

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
		else { cout << " Выход в главное меню" << endl; }

		if (choose_menu == 5) { setColor(2, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
		else { cout << " Выйти из программы" << endl; }

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

int chooseSort() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Сортировать по алфавиту" << endl; setColor(15, 0); }
		else cout << " Сортировать по алфавиту" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Сортировать по цене" << endl; setColor(15, 0); }
		else cout << " Сортировать по цене" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Сортировать по подтипу" << endl; setColor(15, 0); }
		else cout << " Сортировать по подтипу" << endl;

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Выход в меню" << endl; setColor(15, 0); }
		else { cout << " Выход в меню" << endl; }

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

int chooseHowSort() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 3) % 3;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Сортировать по возрастанию" << endl; setColor(15, 0); }
		else cout << " Сортировать по возрастанию" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Сортировать по убываню" << endl; setColor(15, 0); }
		else cout << " Сортировать по убываню" << endl;

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Выход в меню" << endl; setColor(15, 0); }
		else { cout << " Выход в меню" << endl; }

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

int chooseExitOfFill() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Здраствуйте, Пользователь!" << endl;
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		cout << "Вы не ввели всю информацию о себе. Без нее вы не сможете забронировать деталь." << endl;
		cout << "Заполните информацию, пожалуйста." << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Заполнить аккаунт" << endl; setColor(15, 0); }
		else cout << " Заполнить аккаунт" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
		else cout << " Выход в главное меню" << endl;

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

int chooseUserMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Здраствуйте, пользователь!" << endl;
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 8) % 8;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр всех радиодеталей" << endl; setColor(15, 0); }
		else cout << " Просмотр всех радиодеталей" << endl;

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Просмотр забронированных деталей" << endl; setColor(15, 0); }
		else { cout << " Просмотр забронированных деталей" << endl; }

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Заказать радиодеталь" << endl; setColor(15, 0); }
		else { cout << " Заказать радиодеталь" << endl; }

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Отменить заказ радиодеталей" << endl; setColor(15, 0); }
		else { cout << " Отменить заказ радиодеталей" << endl; }

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Просмотр информации аккаунта" << endl; setColor(15, 0); }
		else { cout << " Просмотр информации аккаунта" << endl; }

		if (choose_menu == 5) { setColor(2, 0); cout << " -> Редактирование данных аккаунта" << endl; setColor(15, 0); }
		else { cout << " Редактирование данных аккаунта" << endl; }

		if (choose_menu == 6) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
		else { cout << " Выход в главное меню" << endl; }

		if (choose_menu == 7) { setColor(2, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
		else { cout << " Выйти из программы" << endl; }

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

int writeMenuDetails(Characteristics*& details, int nDetails)
{
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ деталь" << endl;
		choose_menu = (choose_menu + (nDetails + 1)) % (nDetails + 1);

		for (int i = 0; i < nDetails; i++)
			if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << details[i].GetName() << endl; setColor(15, 0); }
			else { cout << " " << i + 1 << " - " << details[i].GetName() << endl; }

		if (choose_menu == nDetails) { setColor(2, 0); cout << " -> Выйти с выбора детали" << endl; setColor(15, 0); }
		else cout << " Выйти с выбора детали" << endl;

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
