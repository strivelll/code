#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<iostream>
//#include<deque>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int>ans;
//        deque<int> que;
//        int r = k - 1, l = 0;
//        for (int i = l; i <= r; i++) {
//            while (!que.empty() && nums[i] > nums[que.back()]) {
//                que.pop_back();
//            }
//            que.push_back(i);
//        }
//        ans.push_back(nums[que.front()]);
//        l++;
//        r++;
//        while (r < n) {
//            if (!que.empty() && que.front() == l - 1) {
//                que.pop_front();
//            }
//            while (!que.empty() && nums[r] > nums[que.back()]) {
//                que.pop_back();
//            }
//            que.push_back(r);
//            ans.push_back(nums[que.front()]);
//            l++;
//            r++;
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int>ans;
//        deque<int> que;
//        int r = k - 1, l = 0;
//        for (int i = l; i <= r; i++) {
//            while (!que.empty() && nums[i] > nums[que.back()]) {
//                que.pop_back();
//            }
//            que.push_back(i);
//        }
//        ans.push_back(nums[que.front()]);
//        for(int i=k;i<n;i++){
//            if (!que.empty() && que.front() <=i-k) {
//                que.pop_front();
//            }
//            while (!que.empty() && nums[i] > nums[que.back()]) {
//                que.pop_back();
//            }
//            que.push_back(i);
//            ans.push_back(nums[que.front()]);
//        }
//        return ans;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> a = { 1,3,-1,-3,5,3,6,7 };
//    vector<int> b = s.maxSlidingWindow(a, 3);
//    for (int i = 0; i < b.size(); i++) {
//        cout << b[i] << " ";
//    }
//
//    return 0;
//}
