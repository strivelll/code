#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int t = nums.size() / 2;
//        
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int min = i;
//            for (int j = i; j < nums.size(); j++) {
//                if (nums[min] > nums[j]) {
//                    min = j;
//                }
//            }
//            if (min != i) {
//                int x = nums[min];
//                nums[min] = nums[i];
//                nums[i] = x;
//            }
//        }
//        int c = nums[0];
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] != c) {
//                if (count > t) {
//                    return c;
//                }
//                c = nums[i];
//                count = 1;
//            }
//            else
//                count++;
//        }
//        if (count > t) {
//            return c;
//        }
//        return 0 ;
//    }
//};
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        int n1[1000] = { 0 };
//        int n2[1000] = { 0 };
//        vector<int> ans;
//        for (int i = 0; i < nums1.size(); i++) {
//            n1[nums1[i]]++;
//        }
//        for (int i = 0; i < nums2.size(); i++) {
//            n2[nums2[i]]++;
//        }
//        for (int i = 0; i < 1000; i++) {
//            if (n1[i] !=0&& n2[i]!=0) {
//                ans.push_back(i);
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        int n1[1001] = { 0 };
//        int n2[1001] = { 0 };
//        vector<int> ans;
//        for (int i = 0; i < nums1.size(); i++) {
//            n1[nums1[i]]++;
//        }
//        for (int i = 0; i < nums2.size(); i++) {
//            n2[nums2[i]]++;
//        }
//        for (int i = 0; i < 1001; i++) {
//            if (n1[i] != 0 && n2[i] != 0) {
//                for (int j = 0; j < (n1[i] < n2[i] ? n1[i] : n2[i]); j++) {
//                    ans.push_back(i);
//                }
//            }
//        }
//        return ans;
//    }
//};

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1,i;
        for (i = nums.size() - 1; i > nums.size() -3; i--) {
            ans *= nums[i];
        }
        ans *= nums[i];
        return ans;
    }
};
int main()
{
    Solution w;
    vector<int>nums1,nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums2.push_back(1000);
    nums2.push_back(1000);
    /*nums1.push_back(3);
    nums1.push_back(2);
    nums1.push_back(3);*/
    int ans=w.maximumProduct(nums1);
        cout << ans << endl;
	return 0;
}