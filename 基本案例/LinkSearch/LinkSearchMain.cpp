//LinkSearchMain.cpp
#include "LinkSearch.cpp"
#include <iostream>
using namespace std;

void main( )
{
	int r[9]={10,15,24,6,12,35,40,98,55};   //��ʼ������
    LinkSearch b;
	b.LinkList(r,9);        //����������е�Ԫ��
	b.PrintList();
	cout<<"\n"<<"����40:"<<endl; //����
	int location=b.SeqSearch2(b.GetFirst(),40);
	cout<<"����λ��Ϊ:"<<location<<endl;
}

