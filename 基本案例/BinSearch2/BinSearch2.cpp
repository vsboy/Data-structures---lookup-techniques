
int BinSearch2(int r[], int low, int high, int k)
{
	if (low>high) 
		return 0;  //递归的边界条件
    else 
	{
		int mid=(low+high)/2;
        if (k<r[mid]) 
			return BinSearch2(r, low, mid-1, k);   //查找在左半区进行
        else 
			if (k>r[mid]) 
				return BinSearch2(r, mid+1, high, k);    //查找在右半区进行 
            else 
				return mid;
	}
}
