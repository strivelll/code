#pragma warning(disable:6031)
//该文件用于对使用的自定义函数定义
#include"contact.h"
//菜单：
void menu() {
	printf("*********************************\n");
	printf("***1.add              2.del   ***\n");
	printf("***3.modify           4.search***\n");
	printf("***5.show             6.sort  ***\n");
	printf("***********  0.exit  ************\n");
	printf("*********************************\n");
}
//这个函数用于查找函数和删除函数，加是static可以使这个函数只能在这个源文件使用，在其他的源文件中不能用，以免干扰其他源文件
static int findbyname(const struct contact* s, char name[NAME]) {
	for (int i = 0; i < s->size ; i++) {
		if (0 == strcmp(s->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}
//内存增加，原始内存为3，超过3就加2个空间，再超过则再加2，以此类推
void pdcontact(struct contact *ps) {
	if (ps->size == ps->contain) {
		ps->contain += 2;
		struct sb* pr = (struct sb*)realloc(ps->data, ps->contain * sizeof(struct sb));
		if (pr != NULL) {
			ps->data = pr;
			printf("增容成功\n");
		}
		else
			printf("增容失败\n");
	}
}
//判断是否联系人已经重复有了
int cfcontact(struct contact* ps,int count) {
	for (int i = 0; i < count; i++) {
		if (strcmp(ps->data[i].addr , ps->data[count].addr)==0 && ps->data[i].age == ps->data[count].age
			&& strcmp(ps->data[i].name, ps->data[count].name) == 0 && strcmp(ps->data[i].sex, ps->data[count].sex) == 0 &&
			ps->data[i].tele == ps->data[count].tele) {
			return 1;
		}
	}
	return 0;
}
//把创建的结构体初始化：
int csh(struct contact* ps) {
	struct sb* pr = (struct sb*)calloc(MAX, sizeof(struct sb));
	if (pr != NULL) {
		ps->data = pr;
	}
	//打开文件，读取上次输入的内容，
	FILE* ptr = fopen("test.txt", "rb");
	if (ptr == NULL) {
		//如果打开失败，告诉原因，并结束。
		perror("open file error");
		return 1;
	}
	ps->size = 0;
	ps->contain = MAX;
	//读取
	while (fread(&(ps->data[ps->size]), sizeof(struct sb), 1, ptr)) {
		ps->size++;
		//判断是否需要增容。
		pdcontact(ps);
	}
	//关闭文件
	fclose(ptr);
	ptr = NULL;
}
//添加联系人：
void addcontact(struct contact* ps) {
	//动态内存增加，以免造成空间的浪费
	pdcontact(ps);
	printf("请输入联系人信息:>\n");
	printf("姓名:>");
	scanf("%s",&ps->data[ps->size].name);
	printf("年龄:> ");
	scanf("%d", &ps->data[ps->size].age);
	printf("性别:> ");
	scanf("%s", &ps->data[ps->size].sex);
	printf("电话号码:> ");
	scanf("%lld", &ps->data[ps->size].tele);
	printf("地址:> ");
	scanf("%s", &ps->data[ps->size].addr);
	//判断用户新增的联系人是否重复。
	int ret=cfcontact(ps,ps->size);
	if (ret) {
		//如果重复了，把刚刚输入的数据初始化，并且ps->size不用加1.
		memset(&(ps->data[ps->size]), 0, sizeof(struct sb));
		printf("该联系人以存在,添加失败:>\n");
	}
	//没重复则继续
	else {
		ps->size++;
		printf("添加成功\n");
	}
}
//删除联系人：
void delcontact(struct contact* ps) {
	if (ps->size == 0) {
		printf("该通讯录目前无联系人:>\n");
		return;
	}
	char name[NAME];
	printf("请输入要删除的姓名:>\n");
	scanf("%s", &name);
	int ret = findbyname(ps, name);
	if (ret == -1)printf("该成员不存在\n");
	else {
		for (int i = ret; i < ps->size - 1; i++) {
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
		printf("删除成功:>\n");
	}
}
//修改其中的联系人数据：
void modifycontact(struct contact* ps) {
	if (ps->size == 0) {
		printf("该通讯录目前无联系人:>\n");
		return;
	}
	char name[NAME];
	printf("请输入你将修改的姓名:>\n");
	scanf("%s", &name);
	int ret=findbyname(ps, name);
	if (ret == -1)printf("该成员不存在\n");
	else {
		printf("请重新输入联系人信息:>\n");
		printf("姓名    :>");
		scanf("%s", &ps->data[ret].name);
		printf("年龄    :> ");
		scanf("%d", &ps->data[ret].age);
		printf("性别    :> ");
		scanf("%s", &ps->data[ret].sex);
		printf("电话号码:> ");
		scanf("%lld", &ps->data[ret].tele);
		printf("地址    :> ");
		scanf("%s", &ps->data[ret].addr);
		printf("修改成功:>\n");
	}
}
//查找联系人：
void searchcontact(const struct contact* ps) {
	if (ps->size == 0) {
		printf("该通讯录目前无联系人:>\n");
		return;
	}
	char name[NAME];
	printf("请输入你想查找的联系人姓名:>\n");
	scanf("%s", &name);
	int ret=findbyname(ps,name);
	if (ret == -1) {
		printf("该成员不存在\n");
	}
	else {
		printf("%-20s\t%-20s\t%-20s\t%-20s \t%-20s\t\n", "姓名", "年龄", "性别", "电话号码", "地址");
		printf("%-20s\t%-20d\t%-20s\t%-20lld\t%-20s\t\n", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
	}
}
//打印已经添加的通讯录
void showcontact(const struct contact* ps) {
	if (ps->size == 0) {
		printf("该通讯录目前无联系人:>\n");
		return;
	}
	printf("%-20s\t%-20s\t%-20s\t%-20s \t%-20s\t\n", "姓名", "年龄", "性别", "电话号码", "地址");
	for (int i = 0; i < ps->size; i++) {
		printf("%-20s\t%-20d\t%-20s\t%-20lld\t%-20s\t\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex,ps->data[i].tele, ps->data[i].addr);
	}
}
//选择年龄升序
void sortcontact(struct contact* ps) {
	if (ps->size == 0) {
		printf("该通讯录目前无联系人:>\n");
		return;
	}
	for (int i = 0; i < ps->size; i++) {
		for (int j = i+1; j < ps->size; j++) {
			//这里不能只改年龄,建立一个临时结构体变量（必须和data类型一样），
			if (ps->data[i].age > ps->data[j].age) {
				struct sb t = ps->data[i];
				ps->data[i] = ps->data[j];
				ps->data[j] = t;
			}
		}
	}
	//重新打印排序后的通讯录
	showcontact(ps);
}
void sfnc(struct contact* ps) {
	free(ps->data);
	//free会释放掉内存但是ps->data的指针依然会保留，为了防止非法访问，将ps->data变成空指针
	ps->data = NULL;
}
int savecontact(struct contact* ps) {
	//创建一个二进制文件
	FILE* ptr = fopen("test.txt", "wb");
	//进行判断是否创建成功
	if (ptr == NULL) {
		//如果失败了，说明失败原因
		perror("save error");
		return 1;
	}
	//保存
	for (int i = 0; i < ps->size; i++) {
		fwrite(&(ps->data[i]), sizeof(struct sb), 1, ptr);
	}
	printf("保存成功\n");
	//关闭文件
	fclose(ptr);
	ptr = NULL;
}