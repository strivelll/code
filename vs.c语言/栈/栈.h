#pragma once
#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
struct sstack {
	void* data[MAX];
	int size;
};
typedef void* ss;
void* init_seqstack();
void push_seqstack(ss sum, void* s);
void pop_seqstack(ss sum);
void* top_seqstack(ss sum);
int size_seqstack(ss sum);
int isempty_seqstack(ss sum);
void destroy_seqstack(ss sum);