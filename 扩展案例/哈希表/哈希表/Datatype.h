typedef int Keytype;
struct Datatype
{
        Keytype key;//构造函数
        Datatype(){}
        Datatype(Keytype item):key(item){}
        //逻辑比较运算符
       int operator<=(const Datatype& item)
	   {return key<=item.key;}
       int operator<(const Datatype& item)
	   {return key<item.key;}
       int operator==(const Datatype& item)
	   {return key==item.key;}
       int operator>=(const Datatype& item)
	   {return key>=item.key;}
      int operator>(const Datatype& item)
	  {return key>item.key;}
      int operator!=(const Datatype& item)
	  {return key!=item.key;}
};
