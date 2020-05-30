#include<iostream>
#include<cstring>
#include"User.h"

///������� �������
void User::copyUser(const User& other)
{
	delete[] this->username;
	strcpy(this->username, other.username);
	delete[] this->password;
	strcpy(this->password, other.password);
	this->accessLevel = other.accessLevel;
}

void User::eraseUser()
{
	delete[] this->username;
}

///������������
User::User() : username(nullptr), password(nullptr), accessLevel(false) {}

User::User(char* name, char* password, bool access)
{
	///����������� � ���������
	delete[] this->username;
	strcpy(this->username, name);
	delete[] this->password;
	strcpy(this->password, password);
	this->accessLevel = access;
}

User::User(const User& other)
{
	///���������� �� ��������
	copyUser(other);
}

User::~User()
{
	///����������
	eraseUser();
}

User& User::operator=(const User& other)
{
	///�������� �� �����������
	if (this != &other)
	{
		eraseUser();
		copyUser(other);
	}
	return *this;
}

///���������
void User::setUsername(char* name)
{
	if (this->username != name)
	{
		delete[] this->username;
		strcpy(this->username, name);
	}
}

void User::setPassword(char* password)
{
	if (this->password != password)
	{
		delete[] this->password;
		strcpy(this->password, password);
	}
}

void User::setAccessLevel(bool access)
{
	this->accessLevel = access;
}

///��������
char* User::getUsername() const
{
	return this->username;
}

char* User::getPassword() const
{
	return this->password;
}

bool User::getAccessLevel() const
{
	return this->accessLevel;
}

///����������� �� ����������
void User::printUser() const
{
	std::cout << "*********************\n";
	std::cout << "USERNAME: " << this->getUsername() << std::endl;
	std::cout << "PASSWORD: " << this->getPassword() << std::endl;
	std::cout << "Administrator?  " << this->getAccessLevel() << std::endl;
	std::cout << "**********************\n";
}