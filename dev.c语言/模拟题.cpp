#include<stdio.h>
//题目1//
//int main()
//{
//	int a=2022,b[100]={0};
//	for(int i=0;;i++)
//	{
//		b[i]=a%2;
//		printf("%d",b[i]);
//		a=a/2;
//		if(a==0)
//		{
//			break;
//		}
//	}
//} 
//题目山谷；
//int cq(char a[30][60],int x,int y)
//{
//	if(a[x][y]<a[x-1][y]&&a[x][y]<a[x+1][y]&&a[x][y]<a[x][y-1]&&a[x][y]<a[x-1][y-1]
//	&&a[x][y]<a[x+1][y-1]&&a[x][y]<a[x-1][y+1]&&a[x][y]<a[x+1][y+1]&&a[x][y]<a[x][y+1])
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char a[30][60];
//	int b,count=0;
//	scanf(" %s",&a);
//	for(int i=1;i<30;i++)
//	{
//		for(int j=1;j<60;i++)
//		{
//			b=cq(a,i,j);
//		}
//		if(b==1)
//		{
//			count++;
//		}
//	} printf("%d\n",count);
//	return 0;
//} 
//int main()
//{
//	float a;
//	float s=0;
//	for(float i=1;i>0;i++)
//	{
//		a=i;
//		s+=(1.0/a);
//		if(s>12)
//		{
//			printf("%f\n",a);
//			break;
//		}
//	}
//	return 0;
//} 
//#define n 365
//int main()
//{
//	int count=0;
//	int s[100][100]={0};
//	int h[100][100];
//	for(int i=0;i<100;i++)
//	{
//		for(int j=0;j<100;j++)
//		{
//			h[i][j]=1+i+j*2;
//			printf("%d ",h[i][j]);
//		}
//		
//		printf("\n");
//	}
//	
//	for(int i=0;i<100;i++)
//	{
//		for(int j=0;j<=i;j++)
//		{
//			count+=h[i][j];
//			if(count==2022)
//			{
//				printf("%d",i*j);
//			}
//		}
//	}
//	return 0;}
//}题目核酸 
//int main()
//{
//	int s,t,a;
//	scanf("%d %d",&s,&t);
//	if(s>t)
//	{
//		a=t+7-s;
//	}
//	else if(s<t)
//	{
//		a=t-s+1;
//	}
//	printf("%d\n",a);
//	return 0;
//}
//题目换元
//#include<string.h>
//int main()
//{
//	char a[100];
//	int b;
//	scanf("%s",&a);
//	b=strlen(a);
//	for(int i=0;i<b;i++)
//	{
//		if(a[i]=='a')
//		{
//			a[i]='A';
//		}
//		if(a[i]=='e')
//		{
//			a[i]='E';
//		}
//		if(a[i]=='i')
//		{
//			a[i]='I';
//		}
//		if(a[i]=='o')
//		{
//			a[i]='O';
//		}
//		if(a[i]=='u')
//		{
//			a[i]='U';
//		}
//	}
//	printf("%s\n",a); 
//	return 0;
//} 
//题目充电器
//int main()
//{
//	int sum[100]={0};
//	int count=0;
//	int n,h,s,m,a[100],b[100],c[100],u[100],I[100];
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf(" %d:%d:%d",&a[i],&b[i],&c[i]);
//		scanf(" %d %d",&u[i],&I[i]);
//		if(i>=1){
//			h=a[i]-a[i-1];
//			m=b[i]-b[i-1];
//			s=c[i]-c[i-1];
//			sum[i-1]=(h*3600+m*60+s)*u[i-1]*I[i-1];
//		}
//	}
//	for(int i=0;i<n-1;i++)
//	{
//		count+=sum[i];
//	}
//	printf("%d\n",count);
//	
//	return 0;
//} 
//题目字母矩阵
//int main()
//{
//	int n,m;
//	int count=0;
//	char a[100][100]
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			scanf(" %c",&a[i][j]);
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			if(a[i][j]==a[i-1][j]&&(a[i][j]==a[i][j-1]||a[i][j]==a[i][j+1]))
//			{
//				count++;
//			}
//			if(a[i][j]==a[i+1][j]&&(a[i][j]==a[i][j-1]||a[i][j]==a[i][j+1]))
//			{
//				count++;
//			}
//			if(a[i][j]==a[i][j-1]&&(a[i][j]==a[i-1][j]||a[i+1][j]==a[i][j+1]))
//			{
//				count++;
//			}
//		}
//	}
//	return 0;
//} //
//#include<string.h>
//int main()
//{
//	int a;
//	char s[1000000]
//	scanf("%s",&s);
//	
//	return 0;
//}
//题目：跑步 
#define n 365
int main()
{
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			if(j==1||j==11||j==21||j==31||)
		}
	}
	return 0;
} 
