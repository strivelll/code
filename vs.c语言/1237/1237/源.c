#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int s[5000001];
int t[5000001] = { 0 };
int main()
{
	for (int i = 2; i < 5000001; i++) {
		s[i] = 1;
	}
	for (int i = 2; i < 2500001; i++) {
		if (s[i]) {
			for (int j = 2; i * j < 5000001; j++) {
				s[i * j] = 0;
			}
		}
	}
	for (int i = 2; i < 5000001; i++) {
		t[i] += t[i - 1];
		if (s[i] && s[i + 2]) {
			t[i + 2]++;
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", t[b]-t[a+1]);//����ΪʲôҪa+1,���ڼ���a��һ������֮��,��ô��һ�������Ǳ���ɢ��,��Ӧ�ü���[a,b]֮���������,�������a����һ��
		//�����һ����������,�������a 3 4 5 b,a��3�����,3��5Ӧ����Ҫ������[a,b]��������,���ڸ�a+1������Ӱ�����ǵļ���,����a��Ҫ��һ.
	}
	return 0;
}
//̫����
//int s[5000001];
//int main()
//{
//	for (int i = 2; i < 5000001; i++) {
//		s[i] = 1;
//	}
//	for (int i = 2; i < 2500001; i++) {
//		if (s[i]) {
//			for (int j = 2; i * j < 5000001; j++) {
//				s[i * j] = 0;
//			}
//		}
//	}
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int a, b;
//		int count = 0;
//		scanf("%d %d", &a, &b);
//		if (b > 5)
//			count++;
//		int r=a%6;
//		if(r!=5)
//			a+=5-r;
//		for (int i =a; i <= b; i+=6) {
//			if (s[i] && i + 2 <= b&&s[i+2]) {
//				count++;
//			}
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}