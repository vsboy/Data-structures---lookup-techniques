//LinkSearch.h
#ifndef LinkSEARCH_H
#define LinkSEARCH_H

struct Node
{
  int data;
  Node *next; 
};

class LinkSearch
{
 public:
    LinkList(int a[ ], int n);    //������n��Ԫ�صĵ�����
    void PrintList( );            //������������������������Ԫ��
	int SeqSearch2(Node *first, int k);//���ҵ��������Ƿ����Ԫ��k
	Node *GetFirst( );
 private:
   Node *first;              //�������ͷָ��
};

#endif
