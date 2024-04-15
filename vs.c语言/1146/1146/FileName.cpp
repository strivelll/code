#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int k = 0;
	scanf("%d", &k);
	int n1=0, m1 = 0,n2=0,m2=0;
	while (k--) {
		int a[100][100] = { 0 };
		int b[100][100] = { 0 };
		int ans[100][100] = { 0 };
		scanf("%d %d", &n1, &m1);
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m1; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%d %d", &n2, &m2);
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				scanf("%d", &b[i][j]);
			}
		}
		for (int i = 0; i < n1; i++) {
			
			for (int k = 0; k < m2; k++) {
				int sum = 0;
				for (int j = 0; j < m1; j++) {
					sum += a[i][j] * b[j][k];
				}
				ans[i][k]=sum;
			}
		}
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m2; j++) {
				if (j != m2 - 1) {
					printf("%d ", ans[i][j]);
				}
				else {
					printf("%d", ans[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
} 
