#include"contact.h"
//枚举：增加代码的可读性
enum u {
	EXIT,//0
	ADD,//1
	DEL,//2
	MODIFY,//3
	SEARCH,//4
	SHOW,//5
	SORT//6
};
//整个通讯录的实现过程
int main() {
	int input = 0;
	struct contact con;
	//初始化函数：把上次运行时输入的数据，继承过来，进行判断是防止文件打开有问题，有问题则直接停止
	if (csh(&con)) {
		return 0;
	}
	do
	{
		system("pause");
		system("cls");
		menu();
		scanf("%d", &input);
		switch(input) {
		//使用枚举代替数字，增加可读性：
		case ADD://1
			addcontact(&con);
			break;
		case DEL://2
			delcontact(&con);
			break;
		case MODIFY://3
			modifycontact(&con);
			break;
		case SEARCH://4
			searchcontact(&con);
			break;
		case SHOW://5
			showcontact(&con);
			break;
		case SORT://6
			sortcontact(&con);
			break;
		case EXIT://0
			//在通讯录结束时自动保存输入的数据，if语句防止保存失败。
			if (savecontact(&con))
				continue;
			//释放内存，以免泄露。
			sfnc(&con);
			printf("以退出程序\n");
			break;
		default:
			printf("选择错误:>\n");
			break;
		}
	} while (input);
	return 0;
}