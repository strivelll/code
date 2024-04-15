#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree {
	char x;
	struct tree* lefttree;
	struct tree* righttree;
};
void bianlitree(struct tree* root) {
	if (root == NULL) {
		return;
	}
	//根
	printf("%c\n", root->x);
	//左
	bianlitree(root->lefttree);
	//右
	bianlitree(root->righttree);
}
int calculleafnum(struct tree* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->lefttree == NULL && root->righttree == NULL) {
		return 1;
	}
	return calculleafnum(root->lefttree) + calculleafnum(root->righttree);
}
int calcultreehight(struct tree* root) {
	if (root == NULL) {
		return 0;
	}
	return (calcultreehight(root->lefttree) > calcultreehight(root->righttree) ? calcultreehight(root->lefttree) + 1 : calcultreehight(root->righttree) + 1);
}
struct tree* copytree(struct tree* root) {
	if (root == NULL) {
		return NULL;
	}
	struct tree* new = (struct tree*)malloc(sizeof(struct tree));
	if (!new) {
		return NULL;
	}
	new->lefttree = copytree(root->lefttree);
	new->righttree = copytree(root->righttree);
	new->x = root->x;
	return new;
}
void freetree(struct tree* newtree) {
	if (newtree == NULL) {
		return;
	}
	free(newtree->lefttree);
	free(newtree->righttree);
	free(newtree);


}
int main()
{
	struct tree A = { 'A',NULL,NULL };
	struct tree B = { 'B',NULL,NULL };
	struct tree C = { 'C',NULL,NULL };
	struct tree D = { 'D',NULL,NULL };
	struct tree E = { 'E',NULL,NULL };
	struct tree F = { 'F',NULL,NULL };
	struct tree G = { 'G',NULL,NULL };
	struct tree H = { 'H',NULL,NULL };
	A.lefttree = &B;
	A.righttree = &F;

	B.righttree = &C;

	C.lefttree = &D;
	C.righttree = &E;

	F.righttree = &G;

	G.lefttree = &H;
	//递归遍历二叉树:
	//bianlitree(&A);
	//计算叶子数:
	 printf("叶子数:%d\n",calculleafnum(&A));
	 //计算树的深度:
	 printf("深度:%d\n", calcultreehight(&A));
	 struct tree* newtree =copytree(&A);
	 bianlitree(newtree);
	 //释放动态内存
	 freetree(newtree);
	 

	return 0;
}