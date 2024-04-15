#include<stdio.h>
void printf1(int (*p)[5],int x,int y)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
		printf("\n");
	}
}
int main()
{
	int a[3][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
	printf1(a,3,5);
	return 0;
} //int (*a[10])[5]:该数组由十个指针组成，每个指针指向五个整型元素。 
