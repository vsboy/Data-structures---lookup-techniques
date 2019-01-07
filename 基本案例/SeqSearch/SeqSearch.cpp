 
int SeqSearch1(int r[], int n, int k){    
      r[0]=k ;          //设置哨兵
      int i=n;
	  while (r[i]!=k)   //若r[i]与k相等，则返回当前i的值;否则继续比较前一个记录;
	     i--; 
	  return i;
}
