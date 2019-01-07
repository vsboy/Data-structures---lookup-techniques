
int BinSearch1(int r[ ], int n, int k)
{
	int low=0, high=n;      //设置初始查找区间
	while (low<=high)                   
	{ 
		int mid=(low+high)/2; //取中间点, 比较k与r[mid]，           
		if (k<r[mid])	
			high=mid-1;       
		else 
			if (k>r[mid]) 
				low=mid+1; 
			else 
				return mid;    //查找成功
	}	
  return 0;                    //查找失败
}
