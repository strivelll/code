//#include<stdio.h>
//int main()
//{
//	int k,p=0,q=0;
//	scanf("%d",&k);
//	while(k--)
//	{
//		int sa,sb;
//		int s[26]={0};
//		int a[26]={0};
//		int n,m;
//		scanf("%d %d",&n,&m);
//		char s1[101];
//		char s2[101];
//		scanf(" %s",&s1);
//		scanf(" %s",&s2);
//		for(int i=0;i<n;i++)
//		{
//			s[s1[i]-97]++;
//			a[s2[i]-97]++;
//		}
//		for(int i=0;i<26;i++)
//		{
//			if(s[i]>s[p])
//			{
//				p=i;
//			}
//			if(a[i]>a[q])
//			{
//				q=i;
//			}
//		}
//		sa=s[p];
//		sb=a[q];
//		if(sa==n&&m%2==1)
//		{
//			sa=n-1;
//		}
//		else if(m>(n-sa))
//		{
//			if(m-n+sa%2==1)
//			{
//				sa=n-1;
//			}
//			else{
//				sa=n;
//			}
//		}
//		else
//		{
//			sa+=m
//		}
//		if(sb==n&&m%2==1)
//		{
//			sb=n-1;
//		}
//		else if(m>(n-sb))
//		{
//			if(m-n+sb%2==1)
//			{
//				sb=n-1;
//			}
//			else{
//				sb=n;
//			}
//		}
//		else
//		{
//			sb+=m
//		}
//		if(sa==sb)
//		{
//			printf("Draw\n");
//		}
//		else if(sa>sb)
//		{
//			printf("Alice\n"); 
//		}
//		else if(sa<sb)
//		{
//			printf("Bob\n"); 
//		}
//	}
//	return 0;
//} 
#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace::std;
int main()
{
	int k;
	scanf("%d", &k);
	while (k--)
	{
		int n, p;
		scanf(" %d %d", &n, &p);
		char s1[101];
		char s2[101];
		int a[30]={0}, b[30]={0};
		int  countalicemax = 0, countbobmax = 0;
	
		scanf("%s", s1);
		scanf("%s", s2);
		
	
		for (int i = 0; i < n; i++) {
			a[s1[i] - 'a']++;
			if (a[s1[i] - 'a'] > countalicemax) {
				countalicemax = a[s1[i] - 'a'];
			}
			
			b[s2[i] - 'a']++;
			if (b[s2[i] - 'a'] > countbobmax) {
				countbobmax = b[s2[i] - 'a'];
			}
 
		}
		int scorealice = 0, scorebob = 0;
		if (countalicemax == n) {
			if (p == 1) {
				scorealice = n - 1;
			}
			else
				scorealice = n;
		}
		
		
		else   if (p >= n - countalicemax) 
			{
			scorealice = n;
			}
		else {
			scorealice = p + countalicemax;
		}
			if (countbobmax == n) {
				if (p == 1) {
					scorebob = n - 1;
				}
				else {
					scorebob = n;
				}
			}
			else if (p >= n - countbobmax)
			{
				scorebob = n;
			}
			else scorebob = p + countbobmax;
 
		
			 if (scorealice > scorebob)
			{
				printf("Alice\n");
			}
			else if (scorealice < scorebob) {
				printf("Bob\n");
			}
			else
			 {
				 printf("Draw\n");
			 } 
	}
 
}
