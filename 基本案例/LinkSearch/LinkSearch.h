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
    LinkList(int a[ ], int n);    //建立有n个元素的单链表
    void PrintList( );            //遍历单链表，按序号依次输出各元素
	int SeqSearch2(Node *first, int k);//查找单链表中是否存在元素k
	Node *GetFirst( );
 private:
   Node *first;              //单链表的头指针
};

#endif
