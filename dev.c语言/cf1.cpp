//#include<stdio.h>
//int main()
//{
//	int a, b, c,k;
//	scanf("%d", &k);
//	while (k--) {
//		scanf("%d %d %d", &a, &b, &c);
//		if (b + c == a||b==a+c||c==a+b) {
//			printf("YES\n");
//		}
//		else {
//			printf("NO\n");
//		}
//	}
//	return 0;
//
//#include<stdio.h>
//void mh(int a[101],int sz){
//	for(int i=0;i<sz;i++){
//		for(int j=i;j<sz;j++){
//			if(a[i]>a[j]){
//				int tmp=a[i];
//				a[i]=a[j];
//				a[j]=tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int a[101];
//	int n,k;
//	scanf("%d",&k);
//	while(k--){
//		scanf("%d",&n);
//		for(int i=0;i<n;i++){
//			scanf("%d",&a[i]);
//		}
//		if(n==1)
//		{
//			printf("YES\n");
//			continue;
//		}
//		mh(a,n);
//		int f;
//		for(int i=0;i<n;i++){
//			f=0;
//			if(a[i]>=a[i+1]){
//			f=1;
//			break;}
//		}
//		if(f==0)
//		printf("YES\n");
//		else if(f==1)
//		printf("NO\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int checkh(char a[8][8],int row,int col){
//	for(int i=0;i<row;i++){
//		int count=0;
//		for(int j=0;j<col;j++){
//			if(a[i][j]=='R'){
//				count++;
//			}
//			else
//			break;
//			}
//			if(count==8)
//			return 1;
//		}
//		return 0;
//	}
//int main()
//{
//	int k;
//	scanf("%d",&k);
//	char a[8][8];
//	while(k--){
//		for(int i=0;i<8;i++){
//			for(int j=0;j<8;j++){
//				scanf(" %c",&a[i][j]);
//			}
//		}
//		int ret=checkh(a,8,8);
//		if(ret==1)
//		printf("R\n");
//		else
//		printf("B\n");
//	}
//	return 0;
//}
#include<stdio.h>
int hz(int a,int b){
	int t;
	while(t=a%b){
		a=b;
		b=t;
	}
	return b;
}
int main()
{
	int k,n;
	int a[1001];
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ret[1001]={0};
		for(int i=n-1;i>=i/2;i--){
			for(int j=i;j>0;j--){
				if(hz(a[i],a[j])==1){
					ret[i]=i+j+2;
					break;
				}
			}	
		}
		int p=0;
		for(int i=n-1;i>0;i--){
			if(ret[p]<ret[i])
			p=i;
		}
		if(ret[p]==0)
		printf("-1\n");
		else
		printf("%d\n",ret[p]);
	}
	return 0;
}
