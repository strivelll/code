//#include<stdio.h>
//int main()
//{
//	int n,k;
//	int a[10];
//	scanf("%d %d",&n,&k);
//	for(int i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	for(int i=0;i<n;i++){
//		for(int j=i;j<n;j++){
//			if(a[i]<a[j]){
//				int t=a[j];
//				a[j]=a[i];
//				a[i]=t;
//				
//			}
//		}
//	}
//	printf("%d\n",a[k-1]);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n,k=0;
//	
//	char a[3001];
//	scanf("%d",&n);
//	scanf("%s",&a);
//	for(int i=0;i<n;i++){
//		if(a[i]=='R'){
//			int f=1;
//			for(int j=i+1;j<n;j++){
//				if(a[j]=='L'){
//					if((i-j+1)%2==0)
//					k+=(abs(i-j)+1);
//					else
//					k+=abs(i-j);
//					i=j+1;
//					f=0;
//					break;
//				}
//			}
//				if(f)
//				k+=n-i;
//		}
//		else if(a[i]=='L'){
//			int f=1;
//			for(int j=i-1;j>0;j--){
//				if(a[j]=='L'){
//					k+=(i-j);
//					f=0;
//					break;
//				}
//			}
//			if(f)
//			k+=i+1;
//		}
//	}printf("%d\n",n-k);
//	return 0;
//}
//分析可知，每一段的“.”都只会被其最近的字母影响到，
//由此可以遍历整个数组，对每一个点分析距离其最近的字母情况
#include <iostream>

using namespace std;

char a[3010];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i ++ ) {

        int r = 0, l = 0;
        if (a[i] == '.'){
            int j = 0;
            for (j = i + 1; j < n; j ++ ) {
                if (a[j] != '.') {
                    if (a[j] == 'L') r++;
                    break;
                    }
            }

            int k = 0;
            for (k = i - 1; k >= 0; k --) {
                if (a[k] != '.') {
                    if (a[k] == 'R') l++;
                    break;
                }
            }

            if (l == r && l == 0) ans++;
            if (l == r && l == 1 && (j - k) % 2 == 0) ans ++, i = j; 

        }

    }

    cout << ans << endl;

    return 0;
}
