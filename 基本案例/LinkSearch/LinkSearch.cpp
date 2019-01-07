//LinkSearch.cpp
#include "LinkSearch.h"
#include <iostream>
using namespace std;

/*
 * 前置条件：单链表不存在
 * 输    入：顺序表信息的数组形式a[],单链表长度n
 * 功    能：将数组a[]中元素建为长度为n的单链表
 * 输    出：无
 * 后置条件：构建一个单链表
 */

LinkSearch::LinkList(int a[],int n)
{
	first=new Node;                   //生成头结点
	Node *r,*s;
    r=first;                          //尾指针初始化
    for (int i=0; i<n; i++)
	{ 
		s=new Node; s->data=a[i];    //为每个数组元素建立一个结点
		r->next=s; r=s;              //插入到终端结点之后
	}
    r->next=NULL;    //单链表建立完毕，将终端结点的指针域置空
 }

/*
 * 前置条件：单链表存在
 * 输    入：无
 * 功    能：单链表遍历
 * 输    出：输出所有元素
 * 后置条件：单链表不变
 */

void LinkSearch::PrintList( )
{
	Node *p;
	p=first->next;
	cout<<"单链表中的元素为:"<<endl;
	while (p)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}	
}

/*
 * 单链表的顺序查找
 */
int LinkSearch::SeqSearch2(Node *first, int k)
{  
	Node *p;
	int count=0;
	p=first->next; 
	int j=1;
    while ( p->data != k)
	{
		p=p->next;
		j++;count++;
	}
	if (p->data==k){
	 
		cout<<"\n"<<"比较的次数为:"<<count<<endl;
		return j;
	}   
   else{ 
      
		cout<<"比较的次数为:"<<count<<endl;
		return 0;
   }
}
/*
 * 取头节点
 */
Node* LinkSearch::GetFirst()
{
	return first;
}