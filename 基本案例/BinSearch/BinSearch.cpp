
int BinSearch1(int r[ ], int n, int k)
{
	int low=0, high=n;      //���ó�ʼ��������
	while (low<=high)                   
	{ 
		int mid=(low+high)/2; //ȡ�м��, �Ƚ�k��r[mid]��           
		if (k<r[mid])	
			high=mid-1;       
		else 
			if (k>r[mid]) 
				low=mid+1; 
			else 
				return mid;    //���ҳɹ�
	}	
  return 0;                    //����ʧ��
}
