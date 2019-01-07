//BinSearch2Main.cpp
#include <iostream>         //引入输入输出流
using namespace std;

int BinSearch2(int r[], int low, int high, int k,int count)
{
	if (low>high){ 
		
		cout<<"比较的次数为:"<<++count<<endl;
		return 0;   //递归的边界条件
	}	
    else 
	{   
		int mid=(low+high)/2;
        
		if (k<r[mid])
		    
			return BinSearch2(r, low, mid-1, k,++count);     //查找在左半区进行
         
		if (k>r[mid])
			
			return BinSearch2(r, mid+1, high, k,++count);    //查找在右半区进行 
		  
		if (k==r[mid]){	
		   
			cout<<"比较的次数为:"<<++count<<endl;
			return mid;
		}   
	}
}

void main()
{
	int count=0;
	int s[]={0,7,14,18,21,23,29,31,35,38,42,46,49,52};
	
	cout<<"有序表中的元素为:\n";
	for(int i=1;i<14;i++)
	{
	   cout<<s[i]<<" ";
	}
		
	cout<<"\n"<<"对18执行查找操作,结果为:\n";    //查找成功
	cout<<BinSearch2(s,1,13,18,count)<<endl;
	
	cout<<"\n"<<"对45执行查找操作,结果为:\n";      //查找失败
	cout<<BinSearch2(s,0,12,45,count)<<endl;
}
