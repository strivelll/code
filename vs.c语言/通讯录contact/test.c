#include"contact.h"
//ö�٣����Ӵ���Ŀɶ���
enum u {
	EXIT,//0
	ADD,//1
	DEL,//2
	MODIFY,//3
	SEARCH,//4
	SHOW,//5
	SORT//6
};
//����ͨѶ¼��ʵ�ֹ���
int main() {
	int input = 0;
	struct contact con;
	//��ʼ�����������ϴ�����ʱ��������ݣ��̳й����������ж��Ƿ�ֹ�ļ��������⣬��������ֱ��ֹͣ
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
		//ʹ��ö�ٴ������֣����ӿɶ��ԣ�
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
			//��ͨѶ¼����ʱ�Զ�������������ݣ�if����ֹ����ʧ�ܡ�
			if (savecontact(&con))
				continue;
			//�ͷ��ڴ棬����й¶��
			sfnc(&con);
			printf("���˳�����\n");
			break;
		default:
			printf("ѡ�����:>\n");
			break;
		}
	} while (input);
	return 0;
}