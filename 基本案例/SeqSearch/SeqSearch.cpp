 
int SeqSearch1(int r[], int n, int k){    
      r[0]=k ;          //�����ڱ�
      int i=n;
	  while (r[i]!=k)   //��r[i]��k��ȣ��򷵻ص�ǰi��ֵ;��������Ƚ�ǰһ����¼;
	     i--; 
	  return i;
}
