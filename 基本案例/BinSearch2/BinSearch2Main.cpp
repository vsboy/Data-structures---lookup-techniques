//BinSearch2Main.cpp
#include <iostream>         //�������������
using namespace std;

int BinSearch2(int r[], int low, int high, int k,int count)
{
	if (low>high){ 
		
		cout<<"�ȽϵĴ���Ϊ:"<<++count<<endl;
		return 0;   //�ݹ�ı߽�����
	}	
    else 
	{   
		int mid=(low+high)/2;
        
		if (k<r[mid])
		    
			return BinSearch2(r, low, mid-1, k,++count);     //���������������
         
		if (k>r[mid])
			
			return BinSearch2(r, mid+1, high, k,++count);    //�������Ұ������� 
		  
		if (k==r[mid]){	
		   
			cout<<"�ȽϵĴ���Ϊ:"<<++count<<endl;
			return mid;
		}   
	}
}

void main()
{
	int count=0;
	int s[]={0,7,14,18,21,23,29,31,35,38,42,46,49,52};
	
	cout<<"������е�Ԫ��Ϊ:\n";
	for(int i=1;i<14;i++)
	{
	   cout<<s[i]<<" ";
	}
		
	cout<<"\n"<<"��18ִ�в��Ҳ���,���Ϊ:\n";    //���ҳɹ�
	cout<<BinSearch2(s,1,13,18,count)<<endl;
	
	cout<<"\n"<<"��45ִ�в��Ҳ���,���Ϊ:\n";      //����ʧ��
	cout<<BinSearch2(s,0,12,45,count)<<endl;
}
