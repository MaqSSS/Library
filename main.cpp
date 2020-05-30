#include<iostream>
#include"Book.h"
#include"User.h"
#include"Library.cpp"

void test()
{
	Book b;
    b.setAuthor("Ivan Vazov");
	b.setTitel("Pod igoto");
	b.setGenre("istoricheski roman");
	b.setPlot("balgarskiya narod pod robstvo");
	b.setYearOfPublishing(1894);
	b.setKeyWords("robstvo");
	b.setID(37567324);
	b.printBook();

	User me("suStudent", "feuiw57rh4uievjy44", true);
	me.printUser();

	Library lib;
	lib.login();
	lib.booksAll(me);
	lib.booksFind("titel", "Discretni structuri", me);
	lib.booksInfo(37567324, me);
}

int main()
{
	User defautUser("admin", "i<3c++", true);

	test();

	return 0;
}
