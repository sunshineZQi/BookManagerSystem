#include"datebase.h"
#include<string.h>
Reader::Reader(){    //Reader的类，属性包括id，tag 
	id=0;
	tag=0;
	for(int i=0;i<MAXBORROWED;i++)
		borbook[i]=0;
	}
	char *Reader::getname()
	{
		return name;
	}
	int Reader::gettag()
	{
		return tag;
	}
	int Reader::getid()
	{
		return id;
	}
	void Reader::setname(char na[])
	{
		strcpy(name,na);
	}
	void Reader::delbook()
	{
		for(int i=0;i<MAXBORROWED;i++){
			if(borbook[i]!=0){
				cout<<"读者"<<name<<"删除失败，请先归还借阅图书"<<endl;
				return;
			}
		}
		tag=1;
		cout<<"读者删除成功"<<endl;
	}
	void Reader::addreader(int n,char *na)
	{
		tag=0;
		id=n;
		strcpy(name,na);
		for(int i=0;i<MAXBORROWED;i++)
			borbook[i]=0;
		cout<<endl<<"读者添加成功，读者编号为:"<<id<<endl;
		cout<<"请牢记改编号，这是你在本系统中登录号码"<<endl;
	}
	void Reader::borrowbook(int bookid)
	{
		for(int i=0;i<MAXBORROWED;i++){
			if(borbook[i]==0){
				borbook[i]=bookid;
				cout<<endl<<"读者借阅成功"<<endl;
				return;
			}
		}
	}
	int Reader::returnbook(int bookid)
	{
		for(int i=0;i<MAXBORROWED;i++){
			if(borbook[i]==bookid){
				borbook[i]=0;
				cout<<endl<<"读者还书成功"<<endl;
				return 1;
			}
		}
	return 0;
	}
	void Reader::show()
	{
		cout<<"读者借阅编号为：";
		for(int i=0;i<MAXBORROWED;i++){
			if(borbook[i]!=0)
				cout<<"["<<borbook[i]<<"]";
		}
		cout<<endl; 
	}
	R_Data::R_Data()
	{
		Reader s;
		top=0;
		fstream file("reader.txt",ios::in);
		while(1){
			file.read((char *)&s,sizeof(s));
			if(!file)break;
			top++;
			read[top]=s;
		}
		maxid=read[top].getid();
		file.close();
	}
	int R_Data::addreader(char *na)
	{
		top++;
		maxid++;
			read[top].addreader(maxid,na);
			return 1;
	}
	Reader* R_Data::search(int readerid)//?????*位置
	{
		for(int i=1;i<=top;i++)
			if(read[i].getid()==readerid && read[i].gettag()==0)
				return &(read[i]);
			return NULL;
	 } 
	void R_Data::show(){
		if(top==0){
			cout<<endl<<"没有读者记录"<<endl;
			return;
		}
		for(int i=1;i<=top;i++){
			read[i].show();
		}
	}
	void R_Data::usershow(int readerid){
		cout<<"reader is:"<<endl;
	}
	void R_Data::readerdata(){
		char choice=1;
		char name[20];
		char rname[20];
		int readerid;
		Reader *r;
		while(choice!='0'){
			cout<<endl<<"**********************读者管理系统****************************"<<endl;
			cout<<"1:添加读者信息"<<endl<<"2:修改读者信息"<<endl<<"3:删除读者信息"<<endl<<"4：查找读者信息"
			<<endl<<"5:显示所有读者"<<endl<<"0:退出读者管理"<<endl<<"请选择你要进行的操作：";
			cin>>choice;
			switch(choice){
				case '1':
					cout<<"输入读者姓名：";
					cin>>rname;
					addreader(rname);
					break;
				case '2':
					cout<<"输入读者编号：";
					cin>>readerid;
					r=search(readerid);
					if(r=NULL){
						cout<<"不存在编号为"<<readerid<<"的读者"<<endl;
						break;
					}
					cout<<"输入新的读者名：";
					cin>>rname;
					break;
				case '3':
					cout<<"输入读者编号：";
					cin>>readerid;
					r=search(readerid);
					if(r=NULL){
						cout<<"不存在编号为"<<readerid<<"的读者"<<endl;
						break;
					}
					r->delbook();
					break;
				case '4':
					cout<<"读入读者编号：";
					cin>>readerid;
					r=search(readerid);
					if(r=NULL){
						cout<<"该读者不存在"<<endl;
						break;
					} 
					r->show();
					break;
				case '5':
					show();
					break;
				case '0':
					break;
				default:
					cout<<"输入有误，请重新输入!"<<endl;
			} 
		}
	}
	R_Data::~R_Data(){
		int onself;
		fstream file("reader.txt",ios::out);
		for(int i=1;i<=top;i++)
			if(read[i].gettag()==0)
				file.write((char *)&(read[i]),sizeof(read[i]));
			file.close();
	}
	Book::Book(){
		int onself;
		id=0;
		tag=1;
		onself=1;
	}
	char *Book::getname(){
		return name;
	}
	int Book::getid(){
		return id;
	}
	int Book::gettag(){
		return tag;
	}
	void Book::setname(char na[]){
		strcpy(name,na);
	}
	void Book::delbook(){
		int onself;
		onself=1;
		tag=1;
	}
	void Book::addbook(int n,char *na){
		int onself;
		tag=0;
		id=n;
		strcpy(name,na);
		onself=1;
		cout<<endl<<"图书添加成功，图书编号为："<<id<<endl;
		cout<<"请牢记该编号，这是该图书在本系统中使用号码"<<endl; 
	}
	int Book::borrowbook(){
		if(onshelf==1){
			onshelf=0;
			return 1;
		}
		return 0;
	}
	void Book::returnbook(){
		onshelf=1;
	}
	void Book::show(){
		cout<<id<<":"<<name<<endl;
	}
	B_Data::B_Data(){
		Book b;
		top=0;
		fstream file("book.txt",ios::in);
		while(1){
			file.read((char*)&b,sizeof(b));
			if(!file)break;
			top++;
			book[top]=b;
		}
		maxid=book[top].getid();
		file.close();
	}
	int B_Data::addbook(char *na){
		top++;
		maxid++;
		book[top].addbook(maxid,na);
		return 1;
	}
	Book *B_Data::search(int bookid){
	for(int i=1;i<=top;i++)
		if(book[i].getid()==bookid && book[i].gettag()==0)
		return &(book[i]);
		return NULL;
	} 
	void B_Data::bookdata(){
		char choice='1';
		char bname[40];
		int bookid;
		Book *b;
		while(choice!='0'){
			cout<<"******************************文物资料管理*****************************************"<<endl;
			cout<<"1:增加文物资料信息"<<endl<<"2:修改文物资料信息"<<endl<<"3:删文物资料信息"<<endl<<"4:查找文物资料信息"<<endl<<"5:显示所有文物资料"<<endl<<"0:退出文物资料管理"<<endl<<"请选择你要执行的操作："<<endl;
			cin>>choice;
			switch(choice){
				case '1':
					cout<<"输入文物资料名称：";
					cin>>bname;
					addbook(bname);
					break;
				case '2':
					cout<<"输入文物资料编号：";
					cin>>bookid;
					b=search(bookid);
					if(b==NULL){
						cout<<"不存在该编号的文物资料"<<endl;
						break; 
					} 
					cout<<"请输入新的文物资料名称";
					cin>>bname;
					b->setname(bname);
					break;
				case '3':
					cout<<"输入文物资料的编号：";
					cin>>bookid;
					b=search(bookid);
					if(b==NULL){
						cout<<"不存在该编号的文物资料"<<endl;
						break; 
					} 
					b->delbook();
					break;
				case '4':
					cout<<"输入文物资料的编号：";
					cin>>bookid;
					b=search(bookid);
					if(b==NULL){
						cout<<"不存在该编号的文物资料"<<endl;
						break; 	
					} 
					b->show();
					break;
				case '5':
					show();
					break;
				case '0':
					break;
				default:
					cout<<"输入有误，请重新输入"<<endl;
			}			
		}
	}
	void B_Data::show(){
		if(top==0){
			cout<<endl<<"没有文物资料的记录"<<endl;
			return;
		}
		for(int i=0;i<=top;i++)
			if(book[i].gettag()==0)
			book[i].show();
	}
	B_Data::~B_Data(){
		fstream file("book.txt",ios::out);
		for(int i=1;i<=top;i++)
			if(book[i].gettag()==0)
				file.write((char*)&(book[i]),sizeof(book[i]));
			file.close();			
}

