#ifndef DATABASE_H_
#define DATABASE_H_
#include "Param.h"
class Reader{
	public:
		Reader();
		int gettag();
		int getid();
		int returnbook(int bookid);
		int borbook[MAXBORROWED];
		char *getname();//?
		void setname(char na[]);
		void delbook();
		void addreader(int n,char *na);
		void borrowbook(int bookid);
		void show();
	private:
		int tag;
		int id;
		char name[10]; 
};
class R_Data{
	public:
		R_Data();
		~R_Data();
		int addreader(char *na);
		void show();
		void usershow(int readerid);
		void readerdata();
		Reader *search(int readerid);
	private:
		int top;
		int maxid;
		Reader read[MAXREADER];
};
class Book{
	public:  
		Book();
		int getid();
		int gettag();
		int borrowbook();
		char *getname();
		void setname(char na[]);
		void delbook();
		void addbook(int n,char *na);
		void returnbook();
		void show();
	private:
		int id;
		int tag;
		int onshelf;
		char name[20];
};
class B_Data{
	public:
		B_Data();
		~B_Data();
		int addbook(char *na);
		void bookdata();
		void show();
		Book *search(int bookid);
	private:
		int top;
		int maxid;
		Book book[MAXBOOKS];
};
#endif
