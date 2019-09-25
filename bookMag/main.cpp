#include <iostream>
#include"datebase.h"
void userlogin(){
	R_Data ReaderDB;
	Reader *r;
	B_Data BookDB;
	Book *b;
	char tempname[20];
	char choice='1';
	int bid,rid;
	while(choice!='0'){
		cout<<endl<<"***************借阅文物资料者专区****************************"<<endl;
		cout<<"1:用户登陆"<<endl<<"2:用户注册"<<endl<<"0：退出"<<endl<<"请选择你要进行的操作："<<endl;
		cin>>choice;
		switch(choice){
			case '1':
				cout<<endl<<"请输入借阅者编号";
				cin>>rid;
				r=ReaderDB.search(rid);
				if(r==NULL){
					cout<<"不存在该借阅者，输入失败"<<endl; 
				} 
			else
				choice='0';
				break;
			case '2':
				cout<<endl<<"请输入借阅文物资料者姓名："<<endl;
				cin>>tempname;
				ReaderDB.addreader(tempname);
				break;
			case '0':
				cout<<"欢迎您的使用"<<endl;
				return;
				default:
					cout<<"输入有误，请重新输入"<<endl; 
		} 
	}
	choice='1';
	while(choice!='0'){
		cout<<endl<<"********************读者借阅专区*******************************"<<endl;
		cout<<"1:文物资料"<<endl<<"2:文物资料归还"<<endl<<"0:退出"<<endl<<"请选择你要进行的操作："<<endl;
		cin>>choice;
		switch(choice){
			case '1':
			cout<<"请输入文物资料编号";
			cin>>bid;
			b=BookDB.search(bid);
			if(b==NULL){
				cout<<"不存在该文物资料，输入失败"<<endl;
				break;
			} 
			if(b->borrowbook()==0){
				cout<<"文物资料"<<b->getname()<<"已借出"<<endl;
				break;
			}
			r->borrowbook(b->getid());
			cout<<endl<<"借阅成功"<<endl;
			break;
		case '2':
			cout<<"请输入想要归还的资料编号：";
			cin>>bid;
			b=BookDB.search(bid);
			if(b==NULL){
				cout<<"不存在该编号的资料"<<endl;
				break;
			}		
			b->returnbook();
			r->returnbook(b->getid());
			cout<<endl<<"归还资料成功"<<endl;
			break;
		case '0':
			cout<<"欢迎您的使用"<<endl;
			break;
		default:
			cout<<"输入有误，请重新输入"<<endl; 
		} 
	}
}
void managelogin(){
	R_Data ReaderDB;
	B_Data BookDB;
	char choice='1';
	string pass;
	cout<<endl<<"请输入管理员密码：";
	cin>>pass;
	if(pass!="1234"){
		cout<<"密码输入错误，登陆失败"<<endl;
		return;
	}
	while(choice!='0'){
		cout<<endl<<"********************文物资料管理员*******************************"<<endl;
		cout<<"1:文物资料管理"<<endl<<"2:读者管理"<<endl<<"0:退出"<<endl<<"请选择你要进行的操作："<<endl;
		cin>>choice;
		switch(choice){
			case '1':
				BookDB.bookdata();
				break;
			case '2':
				ReaderDB.readerdata();
				break;
			case '0':
			 	cout<<"欢迎您的使用"<<endl;
				 break;
			default:
				cout<<"输入有误，请重新输入"<<endl; 
		} 
	}
}
int main(){
	char choice='1';
	while(choice!='0'){
		cout<<endl<<"********************文物资料管理系统*******************************"<<endl;
		cout<<"1:用户专区"<<endl<<"2:管理员专区"<<endl<<"0:退出系统"<<endl<<"请选择你要进行的操作："<<endl;
		cin>>choice;
		switch(choice){
			case '1':
				userlogin();
				break;
			case '2':
				managelogin();
				break;
			case '0':
			 	cout<<"欢迎您的使用"<<endl;
				 break;
			default:
				cout<<"输入有误，请重新输入"<<endl; 
		} 
	}
}
