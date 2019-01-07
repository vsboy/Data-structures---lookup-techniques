//SeqSearchMain.cpp
#include<iostream>          //引入输入输出流
using namespace std;

int SeqSearch1(int r[], int n, int k)
{    
	r[0]=k ;          //设置哨兵
    int i=n,count=0;
	while (r[i]!=k)   //若r[i]与k相等，则返回当前i的值;否则继续比较前一个记录;
	{
		i--;
	    count++;   
	}
	                                        
	cout<<"\n"<<"比较的次数为"<<count<<endl;
	return i;		
}

void main( )
{
    int s[10]={0,1,2,3,4,5,11,7,8,9};    //初始化数组
    int location=0,locate=0;
	cout<<"顺序表中的数据有:\n";
	for(int i=0;i<10;i++)
	{ 
        cout<<s[i]<<" ";                //输出数组元素
	}
	
	cout<<"\n"<<"查找11时:"<<endl;
	location=SeqSearch1(s,10,11);
	cout<<"数组中的下标为"<<location<<endl; //查找成功，i为待查记录在数组中的下标 
	
	cout<<"\n"<<"查找12时:\n";
	locate=SeqSearch1(s,10,12);             //查找不成功，i的值为0，相当于查找失败的标志
	cout<<"数组中的下标为"<<locate<<endl;
}