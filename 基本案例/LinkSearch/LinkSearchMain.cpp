//LinkSearchMain.cpp
#include "LinkSearch.cpp"
#include <iostream>
using namespace std;

void main( )
{
	int r[9]={10,15,24,6,12,35,40,98,55};   //初始化数组
    LinkSearch b;
	b.LinkList(r,9);        //输出单链表中的元素
	b.PrintList();
	cout<<"\n"<<"查找40:"<<endl; //查找
	int location=b.SeqSearch2(b.GetFirst(),40);
	cout<<"所在位置为:"<<location<<endl;
}

