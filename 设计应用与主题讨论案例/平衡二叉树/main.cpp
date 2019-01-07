#include<iostream>
#include<iomanip>
#include<cmath>
#include"BSTree.h"
using namespace std;
void main()
{
	int a[]={26,17,38,19,11,15,14,10,12,24};
	int s;
	int count=0;
	BSTree<int> mytree(a,10);
	int h=mytree.dep();
	int n;
	n=pow(2,h*1.0)-1;
	BTreeNode<int> *b[50];
	cout<<"输入的序列："<<endl;
	for(int i=0;i<10;i++)
		cout<<setw(3)<<a[i];
	cout<<endl;
	cout<<"创建的二叉平衡树"<<endl;
	mytree.layvisit(b,n);
	mytree.Vprnt(b,n,h);
	cout<<" 请输入要查找的数据"<<endl;
	cin>>s;
	if(mytree.search(s,count))
		cout<<"查找成功,共进行了"<<count<<"次查找"<<endl;
	else
		cout<<"查找不成功"<<endl;


}