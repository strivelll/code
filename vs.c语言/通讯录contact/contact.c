#pragma warning(disable:6031)
//���ļ����ڶ�ʹ�õ��Զ��庯������
#include"contact.h"
//�˵���
void menu() {
	printf("*********************************\n");
	printf("***1.add              2.del   ***\n");
	printf("***3.modify           4.search***\n");
	printf("***5.show             6.sort  ***\n");
	printf("***********  0.exit  ************\n");
	printf("*********************************\n");
}
//����������ڲ��Һ�����ɾ������������static����ʹ�������ֻ�������Դ�ļ�ʹ�ã���������Դ�ļ��в����ã������������Դ�ļ�
static int findbyname(const struct contact* s, char name[NAME]) {
	for (int i = 0; i < s->size ; i++) {
		if (0 == strcmp(s->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}
//�ڴ����ӣ�ԭʼ�ڴ�Ϊ3������3�ͼ�2���ռ䣬�ٳ������ټ�2���Դ�����
void pdcontact(struct contact *ps) {
	if (ps->size == ps->contain) {
		ps->contain += 2;
		struct sb* pr = (struct sb*)realloc(ps->data, ps->contain * sizeof(struct sb));
		if (pr != NULL) {
			ps->data = pr;
			printf("���ݳɹ�\n");
		}
		else
			printf("����ʧ��\n");
	}
}
//�ж��Ƿ���ϵ���Ѿ��ظ�����
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
//�Ѵ����Ľṹ���ʼ����
int csh(struct contact* ps) {
	struct sb* pr = (struct sb*)calloc(MAX, sizeof(struct sb));
	if (pr != NULL) {
		ps->data = pr;
	}
	//���ļ�����ȡ�ϴ���������ݣ�
	FILE* ptr = fopen("test.txt", "rb");
	if (ptr == NULL) {
		//�����ʧ�ܣ�����ԭ�򣬲�������
		perror("open file error");
		return 1;
	}
	ps->size = 0;
	ps->contain = MAX;
	//��ȡ
	while (fread(&(ps->data[ps->size]), sizeof(struct sb), 1, ptr)) {
		ps->size++;
		//�ж��Ƿ���Ҫ���ݡ�
		pdcontact(ps);
	}
	//�ر��ļ�
	fclose(ptr);
	ptr = NULL;
}
//�����ϵ�ˣ�
void addcontact(struct contact* ps) {
	//��̬�ڴ����ӣ�������ɿռ���˷�
	pdcontact(ps);
	printf("��������ϵ����Ϣ:>\n");
	printf("����:>");
	scanf("%s",&ps->data[ps->size].name);
	printf("����:> ");
	scanf("%d", &ps->data[ps->size].age);
	printf("�Ա�:> ");
	scanf("%s", &ps->data[ps->size].sex);
	printf("�绰����:> ");
	scanf("%lld", &ps->data[ps->size].tele);
	printf("��ַ:> ");
	scanf("%s", &ps->data[ps->size].addr);
	//�ж��û���������ϵ���Ƿ��ظ���
	int ret=cfcontact(ps,ps->size);
	if (ret) {
		//����ظ��ˣ��Ѹո���������ݳ�ʼ��������ps->size���ü�1.
		memset(&(ps->data[ps->size]), 0, sizeof(struct sb));
		printf("����ϵ���Դ���,���ʧ��:>\n");
	}
	//û�ظ������
	else {
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
//ɾ����ϵ�ˣ�
void delcontact(struct contact* ps) {
	if (ps->size == 0) {
		printf("��ͨѶ¼Ŀǰ����ϵ��:>\n");
		return;
	}
	char name[NAME];
	printf("������Ҫɾ��������:>\n");
	scanf("%s", &name);
	int ret = findbyname(ps, name);
	if (ret == -1)printf("�ó�Ա������\n");
	else {
		for (int i = ret; i < ps->size - 1; i++) {
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�:>\n");
	}
}
//�޸����е���ϵ�����ݣ�
void modifycontact(struct contact* ps) {
	if (ps->size == 0) {
		printf("��ͨѶ¼Ŀǰ����ϵ��:>\n");
		return;
	}
	char name[NAME];
	printf("�������㽫�޸ĵ�����:>\n");
	scanf("%s", &name);
	int ret=findbyname(ps, name);
	if (ret == -1)printf("�ó�Ա������\n");
	else {
		printf("������������ϵ����Ϣ:>\n");
		printf("����    :>");
		scanf("%s", &ps->data[ret].name);
		printf("����    :> ");
		scanf("%d", &ps->data[ret].age);
		printf("�Ա�    :> ");
		scanf("%s", &ps->data[ret].sex);
		printf("�绰����:> ");
		scanf("%lld", &ps->data[ret].tele);
		printf("��ַ    :> ");
		scanf("%s", &ps->data[ret].addr);
		printf("�޸ĳɹ�:>\n");
	}
}
//������ϵ�ˣ�
void searchcontact(const struct contact* ps) {
	if (ps->size == 0) {
		printf("��ͨѶ¼Ŀǰ����ϵ��:>\n");
		return;
	}
	char name[NAME];
	printf("������������ҵ���ϵ������:>\n");
	scanf("%s", &name);
	int ret=findbyname(ps,name);
	if (ret == -1) {
		printf("�ó�Ա������\n");
	}
	else {
		printf("%-20s\t%-20s\t%-20s\t%-20s \t%-20s\t\n", "����", "����", "�Ա�", "�绰����", "��ַ");
		printf("%-20s\t%-20d\t%-20s\t%-20lld\t%-20s\t\n", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
	}
}
//��ӡ�Ѿ���ӵ�ͨѶ¼
void showcontact(const struct contact* ps) {
	if (ps->size == 0) {
		printf("��ͨѶ¼Ŀǰ����ϵ��:>\n");
		return;
	}
	printf("%-20s\t%-20s\t%-20s\t%-20s \t%-20s\t\n", "����", "����", "�Ա�", "�绰����", "��ַ");
	for (int i = 0; i < ps->size; i++) {
		printf("%-20s\t%-20d\t%-20s\t%-20lld\t%-20s\t\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex,ps->data[i].tele, ps->data[i].addr);
	}
}
//ѡ����������
void sortcontact(struct contact* ps) {
	if (ps->size == 0) {
		printf("��ͨѶ¼Ŀǰ����ϵ��:>\n");
		return;
	}
	for (int i = 0; i < ps->size; i++) {
		for (int j = i+1; j < ps->size; j++) {
			//���ﲻ��ֻ������,����һ����ʱ�ṹ������������data����һ������
			if (ps->data[i].age > ps->data[j].age) {
				struct sb t = ps->data[i];
				ps->data[i] = ps->data[j];
				ps->data[j] = t;
			}
		}
	}
	//���´�ӡ������ͨѶ¼
	showcontact(ps);
}
void sfnc(struct contact* ps) {
	free(ps->data);
	//free���ͷŵ��ڴ浫��ps->data��ָ����Ȼ�ᱣ����Ϊ�˷�ֹ�Ƿ����ʣ���ps->data��ɿ�ָ��
	ps->data = NULL;
}
int savecontact(struct contact* ps) {
	//����һ���������ļ�
	FILE* ptr = fopen("test.txt", "wb");
	//�����ж��Ƿ񴴽��ɹ�
	if (ptr == NULL) {
		//���ʧ���ˣ�˵��ʧ��ԭ��
		perror("save error");
		return 1;
	}
	//����
	for (int i = 0; i < ps->size; i++) {
		fwrite(&(ps->data[i]), sizeof(struct sb), 1, ptr);
	}
	printf("����ɹ�\n");
	//�ر��ļ�
	fclose(ptr);
	ptr = NULL;
}