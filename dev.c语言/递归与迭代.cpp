//��Ŀһ�����ַ����ĳ���
//#include<stdio.h>
//int my_strlen(char* str)
//{
//	if(*str!='\0')
//	{
//		return 1+my_strlen(str+1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char ch[]="hellow";
//	int len=my_strlen(ch);
//	printf("%d",len);
//	return 0;
//} 
//��Ŀ��������N�� 
//#include<stdio.h>
//ѭ������ 
//int jiechen(int n)
//{
//	int m=1;
//	for(int i=1;i<=n;i++)
//	{
//		m=m*i;
//	}
//	return m;
//}
//�ݹ鷽�� 
//int jiechen(int n)
//{
//	int m=1;
//	if(n>=2)
//	{
//		m=n*jiechen(n-1);
//	}
//	return m;
//} 
//int main()
//{
//	int n,m;
//	scanf("%d",&n);
//	m=jiechen(n);
//	printf("%d",m);
//	return 0;
//} 
//��Ŀ��쳲���������
//#include<stdio.h>
//�ݹ鷽������������Ч�ʵͣ� 
//int fab(int n)
//{
//	int m=1;
//	if(n>2)
//	{
//		m=fab(n-1)+fab(n-2);
//	}
//	return m;
//}
//ѭ������������Ч�� 
//int fib(int n)
//{
//	int a=1;
//	int b=1;
//	int c=1;
//	while(n>2)
//	{
//		c=a+b;
//		a=b;
//		b=c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n,m;
//	scanf("%d",&n);
//	m=fab(n);
//	m=fib(n);
//	printf("%d",m);
//	return 0;
//}
//��Ŀ�ģ� ��ŵ������ 

//��Ŀ�壻������̨������ 



































