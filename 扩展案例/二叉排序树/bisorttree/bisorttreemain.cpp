//二叉排序树的主函数，文件名为bisorttreemain.cpp
#include<iostream>
#include"bisorttree.h"
using namespace std;

void main( )
{
	int count = 0;
	BiNode* searchnode;
    BiNode* p = NULL;
	int r[10] = {63, 55, 90, 42, 58, 70, 10, 45, 67, 83};
	cout<<"二叉排序树的结点数值"<<endl;
	for(int i=0;i<10;++i)   cout<<r[i]<<" ";
	cout<<endl;
	BiSortTree bst = BiSortTree(r,10);          //初始化一棵二叉排序树
    BiNode* root = bst.Getroot( );              //获取其根结点
	cout<<"查找数据值为70的结点"<<endl;
    searchnode=bst.SearchBST(root, 70,count);   //查找结点数据值为70的结点
	cout<<"删除数据值为70的左孩子结点67"<<endl;
    bst.DeleteBST(p, searchnode );              //删除数值域的值为67的结点
	cout<<"查找数据值为67的结点"<<endl;
    bst.SearchBST(root, 67,count);              //查找结点数据值为67的结点
}
