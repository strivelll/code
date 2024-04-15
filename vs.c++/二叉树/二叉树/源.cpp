#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
class BinaryTree {
public:
	BinaryTree(int value) {
		this->value = value;
		leftchiler = NULL;
		rightchiler = NULL;
	}
	BinaryTree* leftchiler;
	BinaryTree* rightchiler;
	int value;
};
//递归遍历：
void OrderRecur(BinaryTree*head){
	if (head == NULL) {
		return;
	}
	//先序
	/*cout << head->value << " ";
	cout << endl;*/
	OrderRecur(head->leftchiler);
	//中序
	/*cout << head->value << " ";
	cout << endl;*/
	OrderRecur(head->rightchiler);
	//后序
	cout << head->value << " ";
	cout << endl;
}
void PreOrderUnrecur(BinaryTree* head) {
	stack<BinaryTree*> Nodestack;
	Nodestack.push(head);
	while (!Nodestack.empty()) {
		BinaryTree* t = Nodestack.top();
		cout << t->value << endl;
		Nodestack.pop();
		if (t->rightchiler != NULL) {
			Nodestack.push(t->rightchiler);
		}
		if (t->leftchiler != NULL) {
			Nodestack.push(t->leftchiler);
		}
	}
}
void posOrdeUnrecur(BinaryTree* head) {
	stack<BinaryTree*> Nodestack1;
	stack<BinaryTree*> Nodestack2;
	Nodestack1.push(head);
	while (!Nodestack1.empty()) {
		BinaryTree* t = Nodestack1.top();
		Nodestack2.push(t);
		Nodestack1.pop();
		if (t->leftchiler != NULL) {
			Nodestack1.push(t->leftchiler);
		}
		if (t->rightchiler != NULL) {
			Nodestack1.push(t->rightchiler);
		}
	}
	while (!Nodestack2.empty()) {
		cout << Nodestack2.top()->value << endl;
		Nodestack2.pop();
	}
}
void inOrderUnrecur(BinaryTree* head) {
	stack<BinaryTree*> Nodestack;
	while (head!=NULL||!Nodestack.empty()) {
		if (head!= NULL) {
			Nodestack.push(head);
			head = head->leftchiler;
		}
		else {
			head= Nodestack.top();
			Nodestack.pop();
			cout << head->value << endl;
			head = head->rightchiler;
		}
	}
}
void anceng(BinaryTree* head) {
	queue <BinaryTree*> Nodestack;
	Nodestack.push(head);
	while (!Nodestack.empty()) {
		BinaryTree* t = Nodestack.front();
		cout << t->value << endl;
		Nodestack.pop();
		if (t->leftchiler != NULL) {
			Nodestack.push(t->leftchiler);
		}
		if (t->rightchiler != NULL) {
			Nodestack.push(t->rightchiler);
		}
	}
}
int GetMaxWidth(BinaryTree* head) {
	queue <BinaryTree*> Nodequque;
	Nodequque.push(head);
	BinaryTree* curlevelend = head;
	BinaryTree* nextlevelend = NULL;
	int count = 0;
	int max = -1;
	while (!Nodequque.empty()) {
		BinaryTree* t = Nodequque.front();
		Nodequque.pop();
		count++;
		if (t->leftchiler != NULL) {
			Nodequque.push(t->leftchiler);
			nextlevelend = t->leftchiler;
		}
		if (t->rightchiler != NULL) {
			Nodequque.push(t->rightchiler);
			nextlevelend = t->rightchiler;
		}
		if (curlevelend == t) {
			max = max > count ? max : count;
			count = 0;
			curlevelend = nextlevelend;
			nextlevelend = NULL;
		}
	}
	return max;
}
int main()
{
	BinaryTree* head=new BinaryTree(5);
	head->leftchiler = new BinaryTree(3);
	head->rightchiler = new BinaryTree(8);
	head->leftchiler->leftchiler = new BinaryTree(2);
	head->leftchiler->rightchiler = new BinaryTree(4);
	head->leftchiler->leftchiler->leftchiler = new BinaryTree(1);
	head->rightchiler->leftchiler = new BinaryTree(7);
	head->rightchiler->leftchiler->leftchiler = new BinaryTree(6);
	head->rightchiler->rightchiler = new BinaryTree(10);
	head->rightchiler->rightchiler->leftchiler = new BinaryTree(9);
	head->rightchiler->rightchiler->rightchiler = new BinaryTree(11);

	//递归遍历：
	//OrderRecur(head);
	//非递归遍历：
	//先序：
	//PreOrderUnrecur(head);
	//后序：
	//posOrdeUnrecur(head);
	//中序：
	//inOrderUnrecur(head);
	//按层遍历：
	//anceng(head);
	//获得最大宽度：
	cout << GetMaxWidth(head) << endl;;
	return 0;
}