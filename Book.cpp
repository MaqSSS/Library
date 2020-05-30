#include<iostream>
#include<cstring>
#include"Book.h"

///помощни функции
void Book::copyBook(const Book& b)
{
	delete[] this->author;
	strcpy(this->author, b.author);
	delete[] this->titel;
	strcpy(this->titel, b.titel);
	delete[] this->genre;
	strcpy(this->genre, b.genre);
	delete[] this->plot;
	strcpy(this->plot, b.plot);
	this->yearOfPublishing = b.yearOfPublishing;
	delete[] this->keyWords;
	strcpy(this->keyWords, b.keyWords);
	this->rating = b.rating;
	///уникалния номер не се копира, защото е различен за всяка книга
}

void Book::eraseBook()
{
	delete[] this->titel;
}

///конструктори
Book::Book() : author(nullptr), titel(nullptr), genre(nullptr), plot(nullptr), yearOfPublishing(1000), keyWords(nullptr), rating(0.0), ID(00000) {}

Book::Book(char* author, char* titel, char* genre, char* plot, int year, char* key_words, double rating, long id)
{
	///конструктор с параметри
	delete[] this->author;
	strcpy(this->author, author);
	delete[] this->titel;
	strcpy(this->titel, titel);
	delete[] this->genre;
	strcpy(this->genre, genre);
	delete[] this->plot;
	strcpy(this->plot, plot);
	this->yearOfPublishing = year;
	delete[] this->keyWords;
	strcpy(this->keyWords, key_words);
	this->rating = rating;
	this->ID = id;
}

Book::Book(const Book& other)
{
	///конструктор за копиране
	copyBook(other);
}

Book::~Book()
{
	///деструктор
	eraseBook();
}

Book& Book::operator=(const Book& b)
{
	///оператор за присвояване
	if (this != &b)
	{
		eraseBook();
		copyBook(b);
	}
	return *this;
}

///селектори
void Book::setAuthor(char* author)
{
	if (this->author != author)
	{
		delete[] this->author;
		strcpy(this->author, author);
	}
}

void Book::setTitel(char* titel)
{
	if (this->titel != titel)
	{
		delete[] this->titel;
		strcpy(this->titel, titel);
	}
}

void Book::setGenre(char* genre)
{
	if (this->genre != genre)
	{
		delete[] this->genre;
		strcpy(this->genre, genre);
	}
}

void Book::setPlot(char* plot)
{
	if (this->plot != plot)
	{
		delete[] this->plot;
		strcpy(this->plot, plot);
	}
}

void Book::setYearOfPublishing(int year)
{
	this->yearOfPublishing = year;
}

void Book::setKeyWords(char* key_words)
{
	if (this->keyWords != key_words)
	{
		delete[] this->keyWords;
		strcpy(this->keyWords, key_words);
	}
}

void Book::setRating(double rating)
{
	this->rating = rating;
}

void Book::setID(long id)
{
	this->ID = id;
}

///мутатори
char* Book::getAuthor() const
{
	return this->author;
}

char* Book::getTitel() const
{
	return this->titel;
}

char* Book::getGenre() const
{
	return this->genre;
}

char* Book::getPlot() const
{
	return this->plot;
}

int Book::getYearOfPublishing() const
{
	return this->yearOfPublishing;
}

char* Book::getKeyWords() const
{
	return this->keyWords;
}

double Book::getRating() const
{
	this->rating;
}

long Book::getID() const
{
	return this->ID;
}

///отпечатване на книга
void Book::printBook() const
{
	std::cout << "******************************\n";
	std::cout << "Author: " << this->getAuthor() << std::endl;
	std::cout << "Titel: " << this->getTitel() << std::endl;
	std::cout << "Genre: " << this->getGenre() << std::endl;
	std::cout << "Plot: " << this->getPlot() << std::endl;
	std::cout << "Year of publishing: " << this->getYearOfPublishing() << std::endl;
	std::cout << "Key Words: " << this->getKeyWords() << std::endl;
	std::cout << "Rating: " << this->getRating() << " / 10\n";
	std::cout << "Book ID: " << this->getID() << std::endl;
	std::cout << "*******************************\n";
}