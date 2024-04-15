#include"zhan.h"
struct tree {
	char x;
	struct tree* lefttree;
	struct tree* righttree;
	int m;
};
int main()
{
	ss s1=init_seqstack();
	struct tree A = { 'A',NULL,NULL ,0};
	struct tree B = { 'B',NULL,NULL ,0};
	struct tree C = { 'C',NULL,NULL ,0};
	struct tree D = { 'D',NULL,NULL ,0};
	struct tree E = { 'E',NULL,NULL ,0};
	struct tree F = { 'F',NULL,NULL ,0};
	struct tree G = { 'G',NULL,NULL ,0};
	struct tree H = { 'H',NULL,NULL ,0};
	A.lefttree = &B;
	A.righttree = &F;

	B.righttree = &C;

	C.lefttree = &D;
	C.righttree = &E;

	F.righttree = &G;

	G.lefttree = &H;
	push_seqstack(s1, &A);
	while (size_seqstack(s1) > 0) {
		struct tree* M = NULL;
		M= (struct tree*)top_seqstack(s1);
		if (M->m != 0) {
			printf("%c\n", M->x);
			continue;
		}
		M->m = 1;
		if (M->righttree) {
			push_seqstack(s1, M->righttree);
		}
		if (M->lefttree) {
			push_seqstack(s1, M->lefttree);
		}
		push_seqstack(s1, M);

	}
	return 0;
}