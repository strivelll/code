#include<stdio.h>
void menu()
{
	printf("*********************\n");
	printf("**1.add    2.jiang **\n");
	printf("**3.mul    4.dev   **\n");
	printf("**     0.exit      **\n");
	printf("*********************\n");
}
int add(int x, int y)
{
	return x + y;
}
int jiang(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int dev(int x, int y)
{
	return x / y;
}
//方法三：函数回调
void hd(int (*p)(int, int))
{
	int x = 0, y = 0;
	printf("请输入两个操作数\n");
	scanf_s("%d %d", &x, &y);
	printf("%d\n", p(x, y));
}
int main()
{
	int input = 0;
	int x = 0, y = 0;
	do
	{
		menu();
		printf("请选择<:\n");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			hd(add);
			break;
		case 2:
			hd(jiang);
			break;
		case 3:
			hd(mul);
			break;
		case 4:
			hd(dev);
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("输入错误\n");
		}
	} while (input);
	return 0;
}
//方法二：函数指针数组
//int main()
//{
//	int input = 0;
//	int x = 0, y = 0;
//	do {
//		menu();
//		printf("请选择<:\n");
//		scanf_s("%d", &input);
//		if (input > 0 && input < 5) {
//			printf("请输入两个操作数<:\n");
//			scanf_s("%d %d", &x, &y);
//			int (*p[5])(int, int) = { 0,add,jiang,mul,dev };
//			printf("%d\n", p[input](x, y));
//		}
//		else if (input == 0) {
//			printf("退出程序\n");
//		}
//		else
//			printf("输入错误\n");
//		
//	} while (input);
//	return 0;
//}

//方法一：太多重复的，乱
//int main()
//{
//	int input = 0;
//	int x = 0, y = 0;
//	do
//	{
//		menu();
//		printf("请选择<:\n");
//		scanf_s("%d", &input);
//		switch (input) {
//		case 1:
//			printf("请输入两个操作数<:\n");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", add(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数<:\n");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", jiang(x, y));
//			break;
//		case 3:
//			printf("请输入两个操作数<:\n");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个操作数<:\n");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", dev(x, y));
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("输入错误\n");
//		}
//	} while (input);
//	return 0;
//}