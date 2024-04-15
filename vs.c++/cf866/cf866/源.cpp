#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        map<int, int> a;
//        vector<int> b;
//        for (int i = 0; i < nums.size(); i++) {
//            a.insert(make_pair(nums[i], i));
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (a.find(target - nums[i]) != a.end()) {
//                b.push_back(a[target - nums[i]]);
//                b.push_back(i);
//                break;
//            }
//        }
//        return b;
//    }
//};
//int main() {
//    int n, s;
//    map<int, int>ms;
//    map<int, int>mb;
//    cin >> n >> s;
//    for (int i = 0; i < n; i++) {
//        char a;
//        int b, c;
//        cin >> a >> b >> c;
//        if (a == 'S') {
//            ms[b] += c;
//        }
//        else {
//            mb[b] += c;
//        }
//    }
//    vector<pair<int, int>>S(ms.begin(), ms.end());
//    vector<pair<int, int>>B(mb.begin(), mb.end());
//    sort(S.begin(), S.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
//        return p1.first > p2.first; });
//    sort(B.begin(), B.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
//        return p1.first > p2.first; });
//    if ( (int)S.size()- s <= 0) {
//        for (int i = 0; i < S.size(); i++) {
//            cout << 'S' << ' ' << S[i].first << ' ' << S[i].second << endl;
//        }
//    }
//    else {
//        for (int i = S.size() - s; i < S.size(); i++) {
//            cout << 'S' << ' ' << S[i].first << ' ' << S[i].second << endl;
//        }
//    }
//    for (int i = 0; i < B.size() && i < s; i++) {
//        cout << 'B' << ' ' << B[i].first << ' ' << B[i].second << endl;
//    }
//    return 0;
//}
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int b, c;
        cin >> b >> c;
        a[b] = c;
    }
    int count = 1;
    if (n>1) {
        count = 2;
    }
    for (auto it = ++a.begin(); it != --a.end(); it++) {
        if ((it->first) - (it->second) > (--it)->first || (++it)->first + (it->second) < (++it)->first) {
            count++;
        }
        --it;
    }
    cout << count;
    return 0;
}