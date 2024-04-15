//#include<stdio.h>
//int main()
//{
//	int k,m;
//	scanf("%d",&k);
//	while(k--)
//	{
//		int t=0;
//		int l=0;
//		int c=0;
//		scanf("%d",&m);
//		int rs=m;
//		if(rs==1)
//		{
//			printf("0 0\n");
//			t=1;
//		}
//		while(rs>1)
//		{
//			if(rs%2==1)
//			{
//				c+=(rs-1)/2;
//				rs=(rs+1)/2;
//				l++;
//			}
//			if(rs%2==0)
//			{
//				c+=rs/2;
//				rs=rs/2;
//				l++;
//			}
//		}
//		if(t!=1)
//		{
//			printf("%d %d\n",l,c);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main(){
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		int n;
//		scanf("%d",&n);
//		int match=0,round=0;
//		while(n>1){
//			match+=n/2;
//			round++;
//			n=(n+1)/2;
//		}
//		printf("%d %d\n",round,match);
//	}
//}
#include<stdio.h>
int main()
{
	int k,t,n;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		int c=0;
		int l=0;
		while(n>1)
		{
			for(t=2;t*2<=n;t*=2);
			n=n-t/2;
			c+=t/2;
			l++;
		}
		printf("%d %d\n",l,c); 
	}
	return 0;
} 
