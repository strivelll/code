#include<string.h>
#include<stdio.h>
char* my_strstr(const char* p1, const char* p2) {
	char* s1;
	char* s2;
	char* cur = (char*)p1;
	while (*cur) {
		s1 =(char*) cur;
		s2 = (char*)p2;
		while (*s1&&* s2&&* s1 == *s2) {
			s1++;
			s2++;
		}
		if (!*s2) {
			return cur;
		}
		if (!*s1) {
			return NULL;
		}
		cur++;
	}
	return NULL;

}
int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "defasf";
	//char* ret = (char*)strstr(p1, p2);
	char* ret =my_strstr(p1, p2);
	printf("%s\n",ret);
	return 0;
}