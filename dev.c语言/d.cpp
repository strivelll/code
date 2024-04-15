#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char arr1[]="welcome go bit!!!!!";
	char arr2[]="###################";
	int left=0;
	int right=sizeof(arr1)/sizeof(arr1[0])-2;
	while(left<=right)
{
	arr2[left]=arr1[left];
	arr2[right]=arr1[right];
	left++;
	right--;
	Sleep(500);
	printf("%s\n",arr2);
}
	
	return 0;
}
