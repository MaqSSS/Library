#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include"Book.h"
#include"User.h"

class Library : public Book, public User
{
public:
	void login();
	void logout(const User&);

	void booksAll(const User&) const;
	void booksInfo(long, const User&) const; /// == books view
	bool booksFind(char*, char*, const User&);
	void booksSort(char*, char*, const User&); ///char* -> option , char* -> asc | desc

	void booksAdd(char*, char*, const User&, std::ofstream&);
	void booksRemove(char*, const User&, std::ofstream&);

	void usersAdd(char*, char*, const User&, std::ofstream&);
	void usersRemove(char*, const User&, std::ofstream&);
};
#endif // !LIBRARY_H