#include"zhan.h"
void* init_seqstack() {
	struct sstack* sum = calloc(1, sizeof(struct sstack));
	if (!sum) {
		return NULL;
	}
	return sum;
}
void push_seqstack(ss sum, void* s) {
	if (!sum) {
		return;
	}
	struct sstack* p = sum;
	p->data[p->size] = s;
	p->size++;
}
void pop_seqstack(ss sum) {
	if (!sum) {
		return;
	}
	struct sstack* p = sum;
	p->data[p->size - 1] = NULL;
	p->size--;
}
void* top_seqstack(ss sum) {
	if (!sum) {
		return NULL;
	}
	struct sstack* p = sum;
	void* s = p->data[p->size - 1];
	p->data[p->size - 1] = NULL;
	p->size--;
	return s;
}
int size_seqstack(ss sum) {
	if (!sum) {
		return 0;
	}
	struct sstack* p = sum;
	return p->size;
}
int isempty_seqstack(ss sum) {
	if (!sum) {
		return -1;
	}
	struct sstack* p = sum;
	if (!p->size) {
		return 1;
	}
	return 0;
}
void destroy_seqstack(ss sum) {
	if (!sum) {
		return;
	}
	free(sum);
	sum = NULL;

}