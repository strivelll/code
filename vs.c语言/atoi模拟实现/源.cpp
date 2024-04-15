#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
int my_atoi(char* s) {
	int len = strlen(s);
	int ret = 0;
	for (int i = 0; i < len; i++) {
		if (s[i]-'0' <= 9) {
			if(s[i]-'0'>0)
			ret = (ret * 10 + (s[i] - '0'));
		}
		
		else
			break;
	}
	if (s[0] == '-')
		ret =ret*-1;
	return ret;
}
int main()
{
	char a[100] = { 0 };
	scanf("%s", &a);
	int ret = my_atoi(a);
	printf("%d\n", ret);
	return 0;
}