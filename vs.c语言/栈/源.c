#include"Õ».h"
struct S {
	char name[20];
	int age;
};
int main()
{
	ss sum = init_seqstack();
	struct S s1 = { "aaa",12 };
	struct S s2 = { "bbb",13 };
	struct S s3 = { "ccc",14 };
	struct S s4 = { "ddd",15 };
	struct S s5 = { "eee",16 };
	struct S s6 = { "fff",17 };
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	push_seqstack(sum, &a);
	push_seqstack(sum, &b);
	push_seqstack(sum, &c);
	push_seqstack(sum, &d);
	push_seqstack(sum, &e);
	push_seqstack(sum,&f);
	printf("count=%d\n", size_seqstack(sum));
	while (size_seqstack(sum) != 0) {
		/*struct S* s9 = top_seqstack(sum);
		printf("ÐÕÃû:%s ÄêÁä:%d\n", s9->name, s9->age);*/
		int* a1 = top_seqstack(sum);
		printf("%d\n", *a1);
	}
	printf("count=%d\n", size_seqstack(sum));
	return 0;
}