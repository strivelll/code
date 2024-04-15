#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int r = nums.size() - 1;
        int l = 1;
        while (l < r) {
            int mid = r + l >> 1;
            int s = 0;
            for (auto x : nums) {
                s += x >= l && x <= mid;
            }
            if (s > mid - l + 1) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};
