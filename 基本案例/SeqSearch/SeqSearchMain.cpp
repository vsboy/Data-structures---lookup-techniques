//SeqSearchMain.cpp
#include<iostream>          //�������������
using namespace std;

int SeqSearch1(int r[], int n, int k)
{    
	r[0]=k ;          //�����ڱ�
    int i=n,count=0;
	while (r[i]!=k)   //��r[i]��k��ȣ��򷵻ص�ǰi��ֵ;��������Ƚ�ǰһ����¼;
	{
		i--;
	    count++;   
	}
	                                        
	cout<<"\n"<<"�ȽϵĴ���Ϊ"<<count<<endl;
	return i;		
}

void main( )
{
    int s[10]={0,1,2,3,4,5,11,7,8,9};    //��ʼ������
    int location=0,locate=0;
	cout<<"˳����е�������:\n";
	for(int i=0;i<10;i++)
	{ 
        cout<<s[i]<<" ";                //�������Ԫ��
	}
	
	cout<<"\n"<<"����11ʱ:"<<endl;
	location=SeqSearch1(s,10,11);
	cout<<"�����е��±�Ϊ"<<location<<endl; //���ҳɹ���iΪ�����¼�������е��±� 
	
	cout<<"\n"<<"����12ʱ:\n";
	locate=SeqSearch1(s,10,12);             //���Ҳ��ɹ���i��ֵΪ0���൱�ڲ���ʧ�ܵı�־
	cout<<"�����е��±�Ϊ"<<locate<<endl;
}