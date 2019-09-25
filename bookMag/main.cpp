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
		cout<<endl<<"***************��������������ר��****************************"<<endl;
		cout<<"1:�û���½"<<endl<<"2:�û�ע��"<<endl<<"0���˳�"<<endl<<"��ѡ����Ҫ���еĲ�����"<<endl;
		cin>>choice;
		switch(choice){
			case '1':
				cout<<endl<<"����������߱��";
				cin>>rid;
				r=ReaderDB.search(rid);
				if(r==NULL){
					cout<<"�����ڸý����ߣ�����ʧ��"<<endl; 
				} 
			else
				choice='0';
				break;
			case '2':
				cout<<endl<<"�������������������������"<<endl;
				cin>>tempname;
				ReaderDB.addreader(tempname);
				break;
			case '0':
				cout<<"��ӭ����ʹ��"<<endl;
				return;
				default:
					cout<<"������������������"<<endl; 
		} 
	}
	choice='1';
	while(choice!='0'){
		cout<<endl<<"********************���߽���ר��*******************************"<<endl;
		cout<<"1:��������"<<endl<<"2:�������Ϲ黹"<<endl<<"0:�˳�"<<endl<<"��ѡ����Ҫ���еĲ�����"<<endl;
		cin>>choice;
		switch(choice){
			case '1':
			cout<<"�������������ϱ��";
			cin>>bid;
			b=BookDB.search(bid);
			if(b==NULL){
				cout<<"�����ڸ��������ϣ�����ʧ��"<<endl;
				break;
			} 
			if(b->borrowbook()==0){
				cout<<"��������"<<b->getname()<<"�ѽ��"<<endl;
				break;
			}
			r->borrowbook(b->getid());
			cout<<endl<<"���ĳɹ�"<<endl;
			break;
		case '2':
			cout<<"��������Ҫ�黹�����ϱ�ţ�";
			cin>>bid;
			b=BookDB.search(bid);
			if(b==NULL){
				cout<<"�����ڸñ�ŵ�����"<<endl;
				break;
			}		
			b->returnbook();
			r->returnbook(b->getid());
			cout<<endl<<"�黹���ϳɹ�"<<endl;
			break;
		case '0':
			cout<<"��ӭ����ʹ��"<<endl;
			break;
		default:
			cout<<"������������������"<<endl; 
		} 
	}
}
void managelogin(){
	R_Data ReaderDB;
	B_Data BookDB;
	char choice='1';
	string pass;
	cout<<endl<<"���������Ա���룺";
	cin>>pass;
	if(pass!="1234"){
		cout<<"����������󣬵�½ʧ��"<<endl;
		return;
	}
	while(choice!='0'){
		cout<<endl<<"********************�������Ϲ���Ա*******************************"<<endl;
		cout<<"1:�������Ϲ���"<<endl<<"2:���߹���"<<endl<<"0:�˳�"<<endl<<"��ѡ����Ҫ���еĲ�����"<<endl;
		cin>>choice;
		switch(choice){
			case '1':
				BookDB.bookdata();
				break;
			case '2':
				ReaderDB.readerdata();
				break;
			case '0':
			 	cout<<"��ӭ����ʹ��"<<endl;
				 break;
			default:
				cout<<"������������������"<<endl; 
		} 
	}
}
int main(){
	char choice='1';
	while(choice!='0'){
		cout<<endl<<"********************�������Ϲ���ϵͳ*******************************"<<endl;
		cout<<"1:�û�ר��"<<endl<<"2:����Աר��"<<endl<<"0:�˳�ϵͳ"<<endl<<"��ѡ����Ҫ���еĲ�����"<<endl;
		cin>>choice;
		switch(choice){
			case '1':
				userlogin();
				break;
			case '2':
				managelogin();
				break;
			case '0':
			 	cout<<"��ӭ����ʹ��"<<endl;
				 break;
			default:
				cout<<"������������������"<<endl; 
		} 
	}
}
