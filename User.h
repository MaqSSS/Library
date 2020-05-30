#pragma once
#ifndef USER_H
#define USER_H

class User
{
public:
	User();
	User(char*, char*, bool);
	User(const User&);
	~User();

	User& operator=(const User&);

	void setUsername(char*);
	void setPassword(char*);
	void setAccessLevel(bool);

	char* getUsername() const;
	char* getPassword() const;
	bool getAccessLevel() const;

	void printUser() const;

private:
	char* username;
	char* password;
	bool accessLevel; ///true -> the user is administrator
	                  ///false -> the user os NOT administrator

	void copyUser(const User&);
	void eraseUser();
};
#endif // !USER_H