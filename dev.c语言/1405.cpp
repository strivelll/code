#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
	int n;
	int flat=0;
	double a[20][10];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			for(int t=0;t<n;t++)
			{
				if((1/a[i][0]+1/a[j][1]+1/a[t][2])<1)
				{
					flat=1;
					printf("Yes");
					break;
				}
			}
			if(flat==1)
			{
				break;
			}
		}
		if(flat==1)
		{
			break;
		}
	}
	if(flat==0)
	{
		printf("No");
	}
	}
}

//#include<stdio.h>
//int main()
//{
//	int k;
//	scanf("%d",&k);
//	while(k--)
//	{
//		int n;
//		int flag=0;//���flagΪ0 
//		scanf("%d",&n);
//		double a[15][3];
//		for(int i=0;i<n;i++)
//		{
//			scanf("%lf %lf %lf",&a[i][0],&a[i][1],&a[i][2]);//�������� 
//		}
//		for(int i=0;i<n;i++)
//			{
//				for(int j=0;j<n;j++)
//		 		   {
//						 for(int t=0;t<n;t++)
//					{
//						if((1/a[i][0]+1/a[j][1]+1/a[t][2])<1)
//						{
//				 		    flag=1;
//							printf("Yes\n");
//							break;
//								}
//							}
//							if(flag==1)
//							{
//								break;
//							}
//		 		   }
//							if(flag==1)
//							{
//								break;
//							}//flagΪ1ʱ����������ѭ�� 
//							}		
//				if(flag==0)
//				{
//					printf("No\n"); 
//				}
//	}
//}

