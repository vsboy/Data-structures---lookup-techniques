//BinSearchMain.cpp
#include <iostream>        //�������������
using namespace std;

int BinSearch1(int r[ ], int n, int k)
{
	int low=0, high=n,count=0;      //���ó�ʼ��������
	while (low<=high)                   
	{ 
		int mid=(low+high)/2;       //ȡ�м��, �Ƚ�k��r[mid]��           
		
		if (k<r[mid]){	
		
			high=mid-1;
		}   
	    
		if (k>r[mid]){
		
			low=mid+1;
		}
		
	    if(k==r[mid]){
		
			count++;
			cout<<"�Ƚϴ���Ϊ:"<<count<<endl; //���ҳɹ�
		    return mid;
		}
		
		count++;
	}
	
	cout<<"�Ƚϴ���Ϊ:"<<count<<endl;
    return 0;//����ʧ��	
}

void main()
{

	int s[14]={0,7,14,18,21,23,29,31,35,38,42,46,49,52};
	
    cout<<"������е�Ԫ��Ϊ:"<<endl;
	for(int i=1;i<14;i++)
	{
	   cout<<s[i]<<" ";
	}
	cout<<"\n"<<"����14,���Ϊ:"<<endl;
	cout<<"����λ��Ϊ:"<<BinSearch1(s,13,14)<<endl;
	
	cout<<"\n"<<"����22,���Ϊ:"<<endl;
	cout<<"����λ��Ϊ:"<<BinSearch1(s,13,22)<<endl;

}
