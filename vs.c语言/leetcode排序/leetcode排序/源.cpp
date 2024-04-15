#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>

void merge(int* nums1,int m, int* nums2,int n) {
    int help[6];
    int k = 0, i = 0, j = 0;
    for (; i < n && j < m;) {
        help[k++] = nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
    }
    for (i = 0; i < n + m; i++) {
        nums1[i] = help[i];
        printf("%d ", nums1[i]);
    }
}
int main()
{
    int nums1[6],nums2[3];
    int n,m;
    for (int i = 0; i < 6; i++) {
        scanf("%d",&nums1[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d", &nums2[i]);
    }
    scanf("%d %d", &n, &m);
    merge(nums1, m, nums2, n);
	return 0;
}