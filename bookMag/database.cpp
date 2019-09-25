#include"datebase.h"
#include<string.h>
Reader::Reader(){    //Reader���࣬���԰���id��tag 
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
				cout<<"����"<<name<<"ɾ��ʧ�ܣ����ȹ黹����ͼ��"<<endl;
				return;
			}
		}
		tag=1;
		cout<<"����ɾ���ɹ�"<<endl;
	}
	void Reader::addreader(int n,char *na)
	{
		tag=0;
		id=n;
		strcpy(name,na);
		for(int i=0;i<MAXBORROWED;i++)
			borbook[i]=0;
		cout<<endl<<"������ӳɹ������߱��Ϊ:"<<id<<endl;
		cout<<"���μǸı�ţ��������ڱ�ϵͳ�е�¼����"<<endl;
	}
	void Reader::borrowbook(int bookid)
	{
		for(int i=0;i<MAXBORROWED;i++){
			if(borbook[i]==0){
				borbook[i]=bookid;
				cout<<endl<<"���߽��ĳɹ�"<<endl;
				return;
			}
		}
	}
	int Reader::returnbook(int bookid)
	{
		for(int i=0;i<MAXBORROWED;i++){
			if(borbook[i]==bookid){
				borbook[i]=0;
				cout<<endl<<"���߻���ɹ�"<<endl;
				return 1;
			}
		}
	return 0;
	}
	void Reader::show()
	{
		cout<<"���߽��ı��Ϊ��";
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
	Reader* R_Data::search(int readerid)//?????*λ��
	{
		for(int i=1;i<=top;i++)
			if(read[i].getid()==readerid && read[i].gettag()==0)
				return &(read[i]);
			return NULL;
	 } 
	void R_Data::show(){
		if(top==0){
			cout<<endl<<"û�ж��߼�¼"<<endl;
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
			cout<<endl<<"**********************���߹���ϵͳ****************************"<<endl;
			cout<<"1:��Ӷ�����Ϣ"<<endl<<"2:�޸Ķ�����Ϣ"<<endl<<"3:ɾ��������Ϣ"<<endl<<"4�����Ҷ�����Ϣ"
			<<endl<<"5:��ʾ���ж���"<<endl<<"0:�˳����߹���"<<endl<<"��ѡ����Ҫ���еĲ�����";
			cin>>choice;
			switch(choice){
				case '1':
					cout<<"�������������";
					cin>>rname;
					addreader(rname);
					break;
				case '2':
					cout<<"������߱�ţ�";
					cin>>readerid;
					r=search(readerid);
					if(r=NULL){
						cout<<"�����ڱ��Ϊ"<<readerid<<"�Ķ���"<<endl;
						break;
					}
					cout<<"�����µĶ�������";
					cin>>rname;
					break;
				case '3':
					cout<<"������߱�ţ�";
					cin>>readerid;
					r=search(readerid);
					if(r=NULL){
						cout<<"�����ڱ��Ϊ"<<readerid<<"�Ķ���"<<endl;
						break;
					}
					r->delbook();
					break;
				case '4':
					cout<<"������߱�ţ�";
					cin>>readerid;
					r=search(readerid);
					if(r=NULL){
						cout<<"�ö��߲�����"<<endl;
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
					cout<<"������������������!"<<endl;
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
		cout<<endl<<"ͼ����ӳɹ���ͼ����Ϊ��"<<id<<endl;
		cout<<"���μǸñ�ţ����Ǹ�ͼ���ڱ�ϵͳ��ʹ�ú���"<<endl; 
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
			cout<<"******************************�������Ϲ���*****************************************"<<endl;
			cout<<"1:��������������Ϣ"<<endl<<"2:�޸�����������Ϣ"<<endl<<"3:ɾ����������Ϣ"<<endl<<"4:��������������Ϣ"<<endl<<"5:��ʾ������������"<<endl<<"0:�˳��������Ϲ���"<<endl<<"��ѡ����Ҫִ�еĲ�����"<<endl;
			cin>>choice;
			switch(choice){
				case '1':
					cout<<"���������������ƣ�";
					cin>>bname;
					addbook(bname);
					break;
				case '2':
					cout<<"�����������ϱ�ţ�";
					cin>>bookid;
					b=search(bookid);
					if(b==NULL){
						cout<<"�����ڸñ�ŵ���������"<<endl;
						break; 
					} 
					cout<<"�������µ�������������";
					cin>>bname;
					b->setname(bname);
					break;
				case '3':
					cout<<"�����������ϵı�ţ�";
					cin>>bookid;
					b=search(bookid);
					if(b==NULL){
						cout<<"�����ڸñ�ŵ���������"<<endl;
						break; 
					} 
					b->delbook();
					break;
				case '4':
					cout<<"�����������ϵı�ţ�";
					cin>>bookid;
					b=search(bookid);
					if(b==NULL){
						cout<<"�����ڸñ�ŵ���������"<<endl;
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
					cout<<"������������������"<<endl;
			}			
		}
	}
	void B_Data::show(){
		if(top==0){
			cout<<endl<<"û���������ϵļ�¼"<<endl;
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

