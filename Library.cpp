#include<iostream>
#include<fstream>
#include"Library.h"

///общи функции
void open(std::ofstream& out, const char* fileName)
{
	if (!out)
	{
		std::cout << "ERROR!\n";
		return;
	}
	out.open(fileName, std::ios::in|std::ios::out);
	std::cout << "Successfully opened " << fileName << std::endl;
}

void close(std::ofstream& out, const char* fileName)
{
	open(out, fileName);
	out.close();
	std::cout << "Successfully closed " << fileName << std::endl;
}

void save(std::ofstream& out, const char* fileName)
{
	open(out, fileName);
	std::cout << "Successfully saved " << fileName << std::endl;
	close(out, fileName);
}

void saveas(std::ofstream& out, const char* fileName, const char* newFileName)
{
	open(out, fileName);
	delete[] fileName;
	fileName = newFileName;
	std::cout << "Successfully saved as " << newFileName << std::endl;
	close(out, fileName);
}

void help()
{
	std::cout << "The following commands are supported:\n";
	std::cout << "open <file>         opens <file>\t"
		<< "close               closes currently open file\t"
		<< "save                saves the currently open file\t"
		<< "saveas <file>       saves the currenty opened file in <file>\t"
		<< "help                prints this information\t"
		<< "exit                exists the program\n";
}

void exit()
{
	std::cout << "Exiting the program...\n";
}

///операции, поддържани от библиотеката
void Library::login()
{
	///потребителя влиза в системата
	char* name, pass;
	std::cout << "username: ";
	std::cin >> name;
	std::cout << "password: ";
	std::cin >> pass;

	if (name == User::getUsername())
	{
		std::cout << "Welcome, " << name << " !\n";
	}
	else
	{
		std::cout << "Incorrect username or password!\n";
	}
	char* name2, pass2;
	std::cin >> name2;
	if (name2 == name)
	{
		std::cout << "You are already logged in.\n";
	}
}

void Library::logout(const User& u)
{
	///потребителя напуска системата
	std::cout << "Logging out...\n";
	delete[] u.getUsername();
	delete[] u.getPassword();
}


void Library::booksAll(const User& u) const
{
	///за всяка книга извежда последователно : заглавие, автор, жанр, пердонален номер
	std::cout << "Titel: " << Book::getTitel() << std::endl;
	std::cout << "Author: " << Book::getAuthor() << std::endl;
	std::cout << "Genre: " << Book::getGenre() << std::endl;
	std::cout << "ID: " << Book::getID() << std::endl;
}

void Library::booksInfo(long isbn_value, const User& u) const
{
	///извежда подробна информация за книга с даден персонален номер
	if (Book::getID() == isbn_value)
	{
		Book::printBook();
	}
}

bool Library::booksFind(char* option, char* option_string, const User& u)
{
	///търси книга по опция; ако е намерена такава книга, извежда информация за книгата
	if (option == "titel")
	{
		if (Book::getTitel() == option_string)
		{
			Book::printBook();
			return true;
		}
		else
		{
			std::cout << "There isn't a book with that titel.\n";
			return false;
		}
	}
	else if (option == "author")
	{
		if (Book::getAuthor() == option_string)
		{
			Book::printBook();
			return true;
		}
		else
		{
			std::cout << "There isn't a book from this author.\n";
			return false;
		}
	}
	else if (option == "tag")
	{
		if (Book::getKeyWords() == option_string)
		{
			Book::printBook();
			return true;
		}
		else
		{
			std::cout << "There isn't a book with this tag.\n";
			return false;
		}
	}
}

void Library::booksSort(char* option, char* secondary_option, const User& u)
{
	///сортира книгите по опция и критерий(възходящо, низходящо)
	int n = sizeof(Book);
	if (option == "titel")
	{
		if (secondary_option == "asc")
		{
			for (int i = 0; i < n; ++i)
			{

			}
		}
		else if (secondary_option == "desc")
		{

		}
	}
	else if (option == "author")
	{
		if (secondary_option == "asc")
		{
			for (int i = 0; i < n; ++i)
			{

			}
		}
		else if (secondary_option == "desc")
		{

		}
	}
	else if (option == "year")
	{
		if (secondary_option == "asc")
		{
			for (int i = 0; i < n; ++i)
			{

			}
		}
		else if (secondary_option == "desc")
		{

		}
	}
	else if (option == "rating")
	{
		if (secondary_option == "asc")
		{
			for (int i = 0; i < n; ++i)
			{

			}
		}
		else if (secondary_option == "desc")
		{

		}
	}
}


void Library::booksAdd(char* new_titel, char* new_author, const User& u, std::ofstream& out)
{
	///добавя книга в библиотеката
	if (u.getAccessLevel() == true)
	{
		Book newBook(nullptr, nullptr, nullptr, nullptr, 1900, nullptr, 0.0, 589759833);
		newBook.setTitel(new_titel);
		newBook.setAuthor(new_author);
		//out.open();
		//out << newBook.getTitel() << "\t" << newBook.getAuthor() << "\n";
		//out.close();
	}
}

void Library::booksRemove(char* titel, const User& u, std::ofstream& out)
{
	///премахва книга от библиотеката
	if (u.getAccessLevel() == true)
	{
		if (Book::getTitel() == titel)
		{
			//out.open();
			delete[] Book::getTitel();
			//out.close();
		}
	}
}


void Library::usersAdd(char* user, char* password, const User& u, std::ofstream& out)
{
	///добавя даден потребител във файл
	if (u.getAccessLevel() == true)
	{
		User newUser(nullptr, nullptr, false);
		newUser.setUsername(user);
		newUser.setPassword(password);
		//out.open();
		//out << newUser.getUsername() << "\t" << newUser.getPassword() << "\n";
		//out.close();
	}
}

void Library::usersRemove(char* user, const User& u, std::ofstream& out)
{
	///премахва даден потребител от файл
	if (u.getAccessLevel() == true)
	{
		if (User::getUsername() == user)
		{
			//out.open();
			delete[] u.getUsername();
			delete[] u.getPassword();
			//out.close();
		}
	}
}
