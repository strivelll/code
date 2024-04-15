//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[101]={0};
//	scanf_s("%s",a,100);
//	printf("%s", a);
//	int b = strlen(a);
//	if (a[b] == '?')
//	{
//		if (a[b - 1] == 'A' || a[b - 1] == 'E' || a[b - 1] == 'I' || a[b - 1] == 'O' || a[b - 1] == 'U' || a[b - 1] == 'a'
//			|| a[b - 1] == 'e' || a[b - 1] == 'i' || a[b - 1] == 'o' || a[b - 1] == 'u' || a[b - 1] == 'y' || a[b - 1] == 'Y')
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n, x, b = -1, c;
	int a[10];
	scanf_s("%d", &n);
	c = n;
	while (c)
	{
		c /= 10;
		b++;
	}
	while (n)
	{
		for (int i = 0; i < b+1; i++)
		{
			a[i] = n % 10;
			n /= 10;
			printf("%d ", a[i]);
		}
	}
	for (int i = 1; i < b; i++)
	{
		if (a[i] > 4)
		{
			a[i] = 7;
		}
		if (a[i] > 7)
		{
			a[i] = 4;
			a[0] = 4;
		}
	}
	for (int i = 0; i < b; i++)
		printf("%d", a[i]);
	return 0;
}