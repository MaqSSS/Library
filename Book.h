#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>

class Book
{
public:
	Book();
	Book(char*, char*, char*, char*, int, char*, double, long);
	Book(const Book&);
	~Book();

	Book& operator=(const Book&);

	void setAuthor(char*);
	void setTitel(char*);
	void setGenre(char*);
	void setPlot(char*);
	void setYearOfPublishing(int);
	void setKeyWords(char*);
	void setRating(double);
	void setID(long);

	char* getAuthor() const;
	char* getTitel() const;
	char* getGenre() const;
	char* getPlot() const;
	int getYearOfPublishing() const;
	char* getKeyWords() const;
	double getRating() const;
	long getID() const;

	void printBook() const;

private:
	char* author;
	char* titel;
	char* genre;
	char* plot; ///кратко описание на книгата
	int yearOfPublishing;
	char* keyWords;
	double rating; ///рейтинг на книгата
	long ID; ///уникален номер на книгата за библиотеката

	void copyBook(const Book&);
	void eraseBook();
};
#endif // !BOOK_H
