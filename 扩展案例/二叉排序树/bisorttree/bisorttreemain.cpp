//���������������������ļ���Ϊbisorttreemain.cpp
#include<iostream>
#include"bisorttree.h"
using namespace std;

void main( )
{
	int count = 0;
	BiNode* searchnode;
    BiNode* p = NULL;
	int r[10] = {63, 55, 90, 42, 58, 70, 10, 45, 67, 83};
	cout<<"�����������Ľ����ֵ"<<endl;
	for(int i=0;i<10;++i)   cout<<r[i]<<" ";
	cout<<endl;
	BiSortTree bst = BiSortTree(r,10);          //��ʼ��һ�ö���������
    BiNode* root = bst.Getroot( );              //��ȡ������
	cout<<"��������ֵΪ70�Ľ��"<<endl;
    searchnode=bst.SearchBST(root, 70,count);   //���ҽ������ֵΪ70�Ľ��
	cout<<"ɾ������ֵΪ70�����ӽ��67"<<endl;
    bst.DeleteBST(p, searchnode );              //ɾ����ֵ���ֵΪ67�Ľ��
	cout<<"��������ֵΪ67�Ľ��"<<endl;
    bst.SearchBST(root, 67,count);              //���ҽ������ֵΪ67�Ľ��
}
