#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

//int main() {
//	int n=0;
//	int c = 0;
//	int t = 0;
//	char ans[101] = { "" };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int a[7] = { 0 };
//		int top=0;
//		int b[8] = { 1,2,3,4,5,6,7,8 };
//		for (int j = 0; j < 7; j++) {
//			scanf("%d", &a[j]);
//		}
//		int k = 0, l = 0;
//		int f = 0;
//		while (k<6) {
//			if (a[k] >= b[l]) {
//				top = l;
//				l++;
//			}
//			else {
//				while (a[k] < b[l]&&top>=0) {
//					if (top >= 0) {
//						if (b[top]!=0&&b[top] != a[k]&&k<7) {
//							f = 1;
//							ans[c++] = 'N';
//							break;
//						}
//						b[top--] = 0;
//					}
//					if(k<6)
//						k++;
//				}
//				if (f) {
//					break;
//				}
//			}
//		}
//		if (f == 0) {
//			ans[c++] = 'Y';
//		}
//	}
//	for (int i = 0; i < c; i++) {
//		printf("%c", ans[i]);
//	}
//	return 0;
//}
//编辑距离
//int min(int x, int y) {
//	if (x > y) {
//		return y;
//	}
//	return x;
//}
//int main() {
//	char a[2010] = { 0 };
//	char b[2010] = { 0 };
//	scanf("%s", &a);
//	scanf("%s", &b);
//	int** dp = (int**)malloc(sizeof(int*) * 2010);
//	for (int i = 0; i < 2010; i++) {
//		dp[i] = (int*)malloc(sizeof(int) * 2010);
//	}
//	for (int i = 0; i <= strlen(a); i++) dp[i][0] = i;
//	for (int i = 0; i <= strlen(b); i++) dp[0][i] = i;
//	for (int i = 1; i <= strlen(a); i++) {
//		for (int j = 1; j <= strlen(b); j++) {
//			if (a[i-1] == b[j-1]) {
//				dp[i][j] = dp[i - 1][j - 1];
//			}
//			else {
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
//		}
//	}
//	printf("%d", dp[strlen(a)][strlen(b)]);
//
//	return 0;
//}
//int main() {
//	int a[5][5] = { 0 };
//	int b[5] = {0};
//	int c[5] = { 0 };
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (int i = 0; i < 5; i++) {
//		int max = 0;
//		for (int j = 0; j < 5; j++) {
//			if (a[i][j] > max) {
//				max = a[i][j];
//			}
//		}
//		b[i] = max;
//	}
//	for (int i = 0; i < 5; i++) {
//		int min = pow(2,31)-1;
//		for (int j = 0; j < 5; j++) {
//			if (a[j][i] < min) {
//				min = a[j][i];
//			}
//		}
//		c[i] = min;
//	}
//	int flag = 1;
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (a[i][j] == b[i] && a[i][j] == c[j]) {
//				flag = 0;
//				printf("%d %d %d", i, j, b[i]);
//				break;
//			}
//		}
//	}
//	if (flag) {
//		printf("not found");
//	}
//	return 0;
//}
//数的划分
int main() {
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	int dp[310][10] = {0};
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i >= j) {
				dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	printf("%d", dp[n][k]);
	return 0;
}
//5
//int main() {
//	int n=0;
//	int a[500] = { 0 };
//	scanf("%d", &n);
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//		if (a[i] % 2 != 0) {
//			count++;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (a[i] > a[j]) {
//				int t = a[i];
//				a[i] = a[j];
//				a[j] = t;
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] % 2 != 0) {
//			ans++;
//			if (ans != count)
//				printf("%d,", a[i]);
//			else
//				printf("%d", a[i]);
//		}
//	}
//	return 0;
//}
//8
//int main() {
//	char a[1000] = { "0" };
//	gets(a);
//	for (int i = sizeof(a)-1; i >=0 ; i--) {
//		printf("%c",a[i]);
//	}
//	return 0;
//}
//6
//int main() {
//	int n = 0, m = 0;
//	scanf("%d %d", &n, &m);
//	int p = 0;
//	for (int i = 2; i <= n; i++) {
//		p = (p + m) % i;
//	}
//	printf("%d", p+1);
//	return 0;
//}
//9
//void mysort(int* q, int l, int r,int* t) {
//	if (l >= r) {
//		return;
//	}
//	int mid = (l + r) / 2;
//	mysort(q, l, mid,t);
//	mysort(q, mid+1,r,t);
//	int i = l, j = mid + 1, k = l;
//	while (i <= mid && j <= r) {
//		if (q[i] < q[j]) {
//			t[k++] = q[i++];
//		}
//		else {
//			t[k++] = q[j++];
//		}
//	}
//	while (i <= mid) {
//		t[k++] = q[i++];
//	}
//	while (j <= r) {
//		t[k++] = q[j++];
//	}
//	for (int i = l; i <= r; i++)
//	{
//		q[i] = t[i];
//	}
//}
//int main() {
//	int n=0, m=0;
//	int a[500] = { 0 };
//	int b[500] = { 0 };
//	int ans[500] = { 0 };
//	
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//	}
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++) {
//		scanf("%d", &b[i]);
//	}
//	int max = 0;
//	if (n > m) {
//		max = n;
//	}
//	else {
//		max = m;
//	}
//	int* t1 = (int*)malloc(sizeof(int) * max);
//	mysort(a, 0, n - 1,t1);
//	mysort(b, 0, m - 1,t1);
//	int l = 0, j = 0, k = 0;
//	int t[500] = { 0 };
//	int t3[500] = { 0 };
//	int s = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] != a[i + 1]) {
//			t[s++] = a[i];
//		}
//	}
//	int x = 0;
//	for (int i = 0; i < m ; i++) {
//		if (b[i] != b[i + 1]) {
//			t3[x++] = b[i];
//		}
//	}
//	while (l < s && j < x) {
//		if (t[l] < t3[j]) {
//			ans[k++] = t[l++];
//		}
//		else if (t[l] == t3[j]) {
//			l++;
//		}
//		else {
//			ans[k++] = t3[j++];
//		}
//	}
//	while (l < s) {
//			ans[k++] = t[l++];
//	}
//	while (j < x) {
//			ans[k++] = t3[j++];
//	}
//	
//	for (int i = 0; i <k; i++) {
//		printf("%d ", ans[i]);
//	}
//}
//10.
//int main(){
//	int a, n;
//	long long m=0,t=0;
//	scanf("%d %d", &a, &n);
//	if (a > n) {
//		int t = n;
//		n = a;
//		a = t;
//	}
//	for (int i = 0; i < n; i++) {
//		t *= 10;
//		t += a;
//		m += t;
//	}
//	printf("%lld\n", m);
//	return 0;
//} 
/*
奖金
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n, m;
int h[10010], e[20010], ne[20010], idx;
int q[10010];
int d[10010];
int dist[10010];
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
                q[++tt] = j;
        }
    }

    if (tt == n - 1) return 1;
    else return 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        add(b, a);
        d[a] ++;
    }
    if (topsort() == 0) printf("Poor Xed");
    else
    {
        for (int i = 1; i <= n; i++) dist[i] = 100;
        for (int i = 0; i < n; i++)
        {
            int j = q[i];
            for (int k = h[j]; ~k; k = ne[k])
                dist[e[k]] = max(dist[e[k]], dist[j] + 1);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) res += dist[i];
        printf("%d\n", res);
    }
    return 0;
}
联络员
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n, m;
struct Edge
{
    int a;
    int b;
    int w;
}e[10010];
int p[2010];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0, k = 0;
    for (int i = 0; i < m; i++)
    {
        int t, a, b, w;
        scanf("%d %d %d %d", &t, &a, &b, &w);
        if (t == 1)
        {
            res += w;
            p[find(a)] = find(b);
        }
        else {
            e[k].a = a;
            e[k].b = b;
            e[k].w = w;
            k++;
        };
    }

    int swap;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                swap = e[j].a;
                e[j].a = e[j + 1].a;
                e[j + 1].a = swap;
                swap = e[j].b;
                e[j].b = e[j + 1].b;
                e[j + 1].b = swap;
                swap = e[j].w;
                e[j].w = e[j + 1].w;
                e[j + 1].w = swap;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if (a != b)
        {
            p[a] = b;
            res += w;
        }
    }printf("%d\n", res);
    return 0;
}
迷宫
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char a[105][105];
int n;
int vis[105][105];
int ha, la;
int hb, lb;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int flag;
void dfs(int x, int y)
{
    int i, nx, ny;
    if (flag == 1)
    {
        return;
    }
    if (x == hb && y == lb)
    {
        flag = 1;
        return;
    }
    for (i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (flag == 0 && nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == '.' && !vis[nx][ny])
        {
            vis[nx][ny] = 1;
            dfs(nx, ny);

        }
    }
    return;
}
int main()
{
    int i, j, l, k;
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < n; i++)
            scanf("%s", &a[i]);

        scanf("%d %d %d %d", &ha, &la, &hb, &lb);
        if (a[ha][la] == '#' || a[hb][lb] == '#')
        {
            printf("NO\n");
            flag = 0;
            continue;
        }
        dfs(ha, la);
        if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        flag = 0;
    }
    return 0;
}
医院设置
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a[101], g[101][101];
int main()
{
    int n, l, r, min, total;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = 1000000;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i][i] = 0;
        scanf("%d%d%d", &a[i], &l, &r);
        if (l > 0)g[i][l] = g[l][i] = 1;
        if (r > 0)g[i][r] = g[r][i] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != k)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i != j && k != j && g[i][k] + g[k][j] < g[i][j])
                        g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    min = 0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        total = 0;
        for (int j = 1; j <= n; j++)
            total += g[i][j] * a[j];
        if (total < min)min = total;
    }
    printf("%d", min);
    return 0;
}
扑克牌魔术
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[1005] = { 0 };

int main() {
    int n, jsq = 0, count=1;
    scanf("%d", &n);
    while (count != n) {
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0) jsq++;
            if (jsq == 2) {
                arr[i] = count;
                count++;
                jsq = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) printf("%d ", count);
        else printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
 }
 神奇的化合物
 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[10005] = { 0 };

void quick_sort(int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = arr[(l + r) / 2];
    while (i < j) {
        i++;
        while (arr[i] < x) {
            i++;
        }
        j--;
        while (arr[j] > x) {
            j--;
        }
        int swap;
        if (i < j) {
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &arr[i]);
    }
    int u, v, w, count = 0;
    for (int i = 1; i <= n; i = i + 2) {
        quick_sort(i, n);
        u = arr[i];
        v = arr[i+1];
        if (u != 0 && v != 0) {
            w = u + v;
            n++;
            arr[n] = w;
            count = count + w;
        }
    }
    printf("%d\n", count);
    return 0;
}
高考志愿排序
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);  //输入
    int k[10005][3];
    for (int i = 0; i < a; i++) {
        scanf("%d%d%d", &k[i][0], &k[i][1], &k[i][2]);
    }
    int sum[10005];
    for (int i = 0; i < a; i++) {
        sum[i] = k[i][0] + k[i][1] + k[i][2];
    }
    int aa[10005];
    for (int i = 0; i < a; i++) {
        aa[i] = 0;
    }
    int cent = 1;
    for (int i = 0; i < a; i++) {
        cent = 1;
        for (int j = 0; j < a; j++) {
            if (sum[i] < sum[j]) {
                cent++;
            }
            else if (sum[i] == sum[j]) {
                if (k[i][0] < k[j][0]) {
                    cent++;
                }
                else if ((k[i][0] == k[j][0]) && (k[i][1] < k[j][1])) {
                    cent++;
                }
                else if ((k[i][0] == k[j][0]) && (k[i][1] == k[j][1]) && (k[i][2] < k[j][2])) {
                    cent++;
                }
                else if ((k[i][0] == k[j][0]) && (k[i][1] == k[j][1]) && (k[i][2] = k[j][2]) && (i > j)) {
                    cent++;
                }
            }
        }
        aa[i] = cent;
    }
    int bb = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            if (aa[j] == bb) {
                printf("%d ", j + 1);
                bb++;
                break;
            }
        }
    }
    return 0;
}
二叉排序
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* insertNode(struct TreeNode* root, int data);
void preorder(struct TreeNode* root);
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insertNode(root, nums[i]);
    }
    preorder(root);
    printf("\n");
    free(nums);
    return 0;
}
文件读写
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main()
{
    char ch[10005];
    gets(ch);
    printf("这是测试文件第一行\n");
    printf("这是测试文件第二行\n");
    printf("这是测试文件第三行\n");
    return 0;
}
*/