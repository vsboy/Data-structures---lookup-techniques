//LinkSearch.cpp
#include "LinkSearch.h"
#include <iostream>
using namespace std;

/*
 * ǰ������������������
 * ��    �룺˳�����Ϣ��������ʽa[],��������n
 * ��    �ܣ�������a[]��Ԫ�ؽ�Ϊ����Ϊn�ĵ�����
 * ��    ������
 * ��������������һ��������
 */

LinkSearch::LinkList(int a[],int n)
{
	first=new Node;                   //����ͷ���
	Node *r,*s;
    r=first;                          //βָ���ʼ��
    for (int i=0; i<n; i++)
	{ 
		s=new Node; s->data=a[i];    //Ϊÿ������Ԫ�ؽ���һ�����
		r->next=s; r=s;              //���뵽�ն˽��֮��
	}
    r->next=NULL;    //����������ϣ����ն˽���ָ�����ÿ�
 }

/*
 * ǰ�����������������
 * ��    �룺��
 * ��    �ܣ����������
 * ��    �����������Ԫ��
 * ������������������
 */

void LinkSearch::PrintList( )
{
	Node *p;
	p=first->next;
	cout<<"�������е�Ԫ��Ϊ:"<<endl;
	while (p)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}	
}

/*
 * �������˳�����
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
	 
		cout<<"\n"<<"�ȽϵĴ���Ϊ:"<<count<<endl;
		return j;
	}   
   else{ 
      
		cout<<"�ȽϵĴ���Ϊ:"<<count<<endl;
		return 0;
   }
}
/*
 * ȡͷ�ڵ�
 */
Node* LinkSearch::GetFirst()
{
	return first;
}