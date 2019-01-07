//BinSearchMain.cpp
#include <iostream>        //引入输入输出流
using namespace std;

int BinSearch1(int r[ ], int n, int k)
{
	int low=0, high=n,count=0;      //设置初始查找区间
	while (low<=high)                   
	{ 
		int mid=(low+high)/2;       //取中间点, 比较k与r[mid]，           
		
		if (k<r[mid]){	
		
			high=mid-1;
		}   
	    
		if (k>r[mid]){
		
			low=mid+1;
		}
		
	    if(k==r[mid]){
		
			count++;
			cout<<"比较次数为:"<<count<<endl; //查找成功
		    return mid;
		}
		
		count++;
	}
	
	cout<<"比较次数为:"<<count<<endl;
    return 0;//查找失败	
}

void main()
{

	int s[14]={0,7,14,18,21,23,29,31,35,38,42,46,49,52};
	
    cout<<"有序表中的元素为:"<<endl;
	for(int i=1;i<14;i++)
	{
	   cout<<s[i]<<" ";
	}
	cout<<"\n"<<"查找14,结果为:"<<endl;
	cout<<"所在位置为:"<<BinSearch1(s,13,14)<<endl;
	
	cout<<"\n"<<"查找22,结果为:"<<endl;
	cout<<"所在位置为:"<<BinSearch1(s,13,22)<<endl;

}
