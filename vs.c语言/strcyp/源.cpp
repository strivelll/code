//#include<stdio.h>
//#include<assert.h>
//void my_strcyp(char* s1, const char* s2)
//{
//	assert(s2 != NULL);
//	while (*s1++ =* s2++)
//	{
//		;
//	}
//}
//int main()
//{
//	char s1[10]={0};
//	char s2[] = "abcdef";
//	my_strcyp(s1, s2);
//	printf("%s\n", s1);
//	return 0;
//}
#include<stdio.h>
#include<assert.h>
int my_strlen(const char* arr)
{
	int count = 0;
	assert(arr != NULL);
	while (*arr!= '\0')
	{
		count++;
		arr++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdefg";
	int count=my_strlen(arr);
	printf("%d\n", count);
	return 0;
}