//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[100];
//	int b[26]={0};
//	int count=0;
//	gets(a);
//	int n=strlen(a);
//	for(int i=0;i<n;i++){
//		int t=a[i]-97;
//		if(b[t]==0){
//			count++;
//			b[t]++;
//		}
//	}
//	if(count%2==0){
//		printf("even\n");
//	}
//	else
//	printf("odd\n"); 
//	return 0;
//} 
#include<stdio.h>
int main()
{
	int n,m,f;
	int a[100],b[100];
	int s=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++){
		f=1;
		for(int j=0;j<m;j++){
			if(i==b[j]-1){
				f=0;
			}
		}
		if(f)
		s+=a[i];
	}
	int p=b[0]-1;
	for(int i=0;i<m;i++){
		if(a[p]<a[b[i]-1])
		p=b[i]-1;
	}
	for(int i=0;i<m;i++){
		if(s<a[p]){
			s+=a[p];
		}
		else
		s*=2;
	}
	printf("%d\n",s);
	return 0;
}
