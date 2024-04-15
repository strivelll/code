#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//primÀ„∑®£∫
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>

//int c[100][100] = { 0 };
//int ans[100] = { 0 };
//int s[100] = { 0 };
//int Min(int arr[], int len) {
//	int min = 3001;
//	int t = 0;
//	for (int i = 0; i < len; i++) {
//		if (min > arr[i] && !s[i]) {
//			min = arr[i];
//			t = i;
//		}
//	}
//	return t;
//}
//int main()
//{
//	int n, m;
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; j < 100; j++) {
//			c[i][j] = 3001;
//		}
//	}
//	c[0][0] = 0;
//	int cost = 0;
//	scanf("%d %d", &n, &m);
//	while (m--) {
//		int a, b, x;
//		scanf("%d %d %d", &a, &b, &x);
//		c[a - 1][b - 1] = x;
//		c[b - 1][a - 1] = x;
//	}
//	for (int j = 0; j < n; j++) {
//		if (!s[j])
//			ans[j] = c[0][j];
//	}
//	int z = n;
//	while (z--) {
//		int t = Min(ans, n);
//		s[t] = 1;
//		int y = ans[t];
//		cost += y;
//		for (int k = 0; k < n; k++) {
//			if (!s[k]) {
//				ans[k] = ans[k] > c[t][k] ? c[t][k] : ans[k];
//			}
//		}
//
//	}
//	printf("%d\n",cost);
//	return 0;
//}
//kruskalÀ„∑®£∫
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

class node {
public:
	node(int u,int v,int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
	bool operator < (const node& n) const {
		return this->w < n.w;
	}
public:
	int u;
	int v;
	int w;
};
int main() {
	int n, e;
	vector<node> a;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int b, c;
		int d;
		cin >> b >> c >> d;
		a.push_back(node(b, c, d));
	}
	sort(a.begin(), a.end(),less<node>());
	int j = 0;
	int cost = 0;
	int parentnode[100] = {0};
	for (int i = 1; i <= n; i++) {
		parentnode[i] = i;
	}
	while (j < e) {
		if (parentnode[a[j].u] != parentnode[a[j].v]) {
			cost += a[j].w;
			int t = parentnode[a[j].u] > parentnode[a[j].v] ? parentnode[a[j].v] : parentnode[a[j].u];
			int s = max(parentnode[a[j].u], parentnode[a[j].v]);
			for (int i = 1; i <= n; i++) {
				if (parentnode[i] ==s ) {
					parentnode[i] = t;
				}
			}
		}
		j++;
	}
	cout << cost << endl;
	return 0;
}