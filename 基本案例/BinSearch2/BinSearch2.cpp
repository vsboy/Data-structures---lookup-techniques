
int BinSearch2(int r[], int low, int high, int k)
{
	if (low>high) 
		return 0;  //�ݹ�ı߽�����
    else 
	{
		int mid=(low+high)/2;
        if (k<r[mid]) 
			return BinSearch2(r, low, mid-1, k);   //���������������
        else 
			if (k>r[mid]) 
				return BinSearch2(r, mid+1, high, k);    //�������Ұ������� 
            else 
				return mid;
	}
}
