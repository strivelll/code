//#include<stdio.h>
//int main()
//{
//	int n=2048;
//	int b,a=64;
//	while(n)
//	{
//		b=n%2;
//		printf("%d",b);
//		n/=2;
//	}
//	return 0;
//} 
// //2048
//int main()
//{
//	int n = 1949;
//	int count = 91;
//	for (int i = 1950; i <2022; i++)
//	{
//		if (i% 4 == 0&&i%100!=0)
//		{
//			count += 366;
//		}
//		else
//			count += 365;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//26388
//#include<math.h>
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	int sum = 0;
//	int i = 0;
//	for (i = 20; i > 0; i++)
//	{
//		c = i; b = 0; sum = 0;
//		while (i)
//		{
//			a = i % 10;
//			sum += pow(16, b) * a;
//			b++;
//			i /= 10;
//		}
//		i = c;
//		if (sum % c == 0)
//		{
//			printf("%d\n", c);
//			break;
//		}
//	}
//	return 0;
//}1038
//}10
//int max(int x, int y)
//{
//	if (x > y)
//	return x;
//	return y;
//}
//int sl(int arr[30][60],int x,int y)
//{
//	int s=0;
//	s = arr[x][y] + max(arr[x + 1][y], arr[x][y + 1]);
//	if (max(arr[x + 1][y], arr[x][y + 1]) == arr[x + 1][y])
//	{
//		x++;
//		s+=sl(arr, x, y);
//	}
//	else
//	{
//		y++;
//		s += sl(arr, x, y);
//	}
//	return s;
//}
//int main()
//{
//	int x = 0, y = 0;
//	int arr[30][60]={0};
//	int i = 0,j=0;
//	int sum=0;
//	for (i = 0; i < 30; i++)
//	{
//		for (j = 0; j < 60; j++)
//		{
//			scanf_s("%d", &arr[i][j]);
//		}
//	}
//	sum = sl(arr,x,y);
//	printf("%d\n", sum);
//	return 0;
//}
//int main()
//{
//	int n = 2022;
//	int c = 0,sum=2,count=1,f=0;
//	for (int i = 3; i > 0; i++)
//	{
//		c = 0;
//		f = 0;
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0&&i!=2)
//			{
//				f = 1;
//				break;
//			}
//			
//		}
//		if (f == 0)
//		{
//			count++;
//			sum += c;
//		}
//		if (sum == 2022)
//		{
//			printf("%d\n", count);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int t, c, s;
//	float a, b;
//	scanf_s("%d%d%d", &t, &c, &s);
//	a = s - c;
//	b =(float)c / t;
//	printf("%g\n",a/b);
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//struct dc 
//{
//	char a[100];
//}b[100];
//int main()
//{
//	int n;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%s", &b[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			if (strcmp(b[i], b[j]) == 0)
//			{
//				b[j] = { };
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s\n", b[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[200];
//	scanf_s("%s", a);
//	int n = strlen(a);
//	int left = 0;
//	int right = n- 1;
//	while (left <= right)
//	{
//		if (a[left] != a[right])
//		{
//			a[right + 1] = a[left];
//			right--;
//			left++;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char a[100000] = { 'a','b','c','d','e' };
//	int n;
//	char f;
//	scanf_s("%d", n);
//	while (n--) {
//		f = a[0];
//		for (int i = 0; i < 5 + n; i++)
//		{
//			if (i <= 4 - n)
//				a[i] = a[i + 1];
//			else
//			{
//				a[i] = f;
//			}
//		}
//	}
//	printf("%c\n", f);
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char a[1001];
    int b[26] = { 0 };
    int p;
    int n = sizeof(a) / sizeof(a[0]);
    scanf_s("%s",a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (a[i] == j + 97) {
                b[j]++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (b[i] > b[j]) {
                p = i;
            }
            else
                p = j;
        }
    }
    printf("%c\n%d\n", 97 + p, b[p]);
    return 0;
}