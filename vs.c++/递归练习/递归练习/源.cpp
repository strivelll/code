#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<iostream>
//using namespace std;
//
//class ListNode {
//public:
//    int val;
//    ListNode* next;
//};
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* ans;
//        while (list1 != NULL && list2 != NULL) {
//            if (list1->val < list2->val) {
//                ans->next = list1;
//                list1 = list1->next;
//            }
//            else {
//                ans->next = list2;
//                list2 = list2->next;
//            }
//        }
//        while (list1 != NULL) {
//            ans->next = list1;
//            list1 = list1->next;
//        }
//        while (list2 != NULL) {
//            ans->next = list2;
//            list2 = list2->next;
//        }
//        return ans;
//    }
//};
//int main() {
//
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> a;
//    for (int i = 0; i < n; i++) {
//        int b;
//        cin >> b;
//        a.push_back(b);
//    }
//    sort(a.begin(), a.end());
//    int d = INT_MAX;
//    for (int i = 0; i < a.size()-1; i++) {
//        if (a[i + 1] - a[i] < d) {
//            d = a[i + 1] - a[i];
//        }
//    }
//    int ans = (a[a.size() - 1] - a[0]) / d + 1;
//    cout << ans;
//    return 0;
//}
#include <iostream>
#include<vector>
using namespace std;
//bool iscan(int n) {
//    if (n / 1000 == 2 || n / 1000 == 4 || n / 100 % 10 == 2 || n / 100 % 10 == 4 || n / 10 % 10 == 2 || n / 10 % 10 == 4 || n % 10 == 2 || n % 10 == 4) {
//        return false;
//    }
//    return true;
//}
//int main()
//{
//    int count = 0;
//    for (int i = 1; i < 2020; i++) {
//        if (!iscan(i))
//            continue;
//        for (int j = 1; j < 2020; j++) {
//            if (!iscan(j))
//                continue;
//            for (int k = 1; k < 2020; k++) {
//                if (!iscan(k))
//                    continue;
//                if (i + j + k == 2019&&i!=j&&i!=k&&j!=k) {
//                    count++;
//                }
//            }
//        }
//    }
//    cout << count;
//    return 0;
//}
//using namespace std;
//int b[8] = { 0 };
//void func(int n) {
//    int x = abs(n);
//    int i = 0;
//    while (x) {
//        b[i++] = x % 2;
//        x /= 2;
//    }
//    for (; i < 8; i++) {
//        b[i] = 0;
//    }
//    if (n < 0) {
//
//        for (int j = 0; j < 8; j++) {
//
//            if (b[j] == 1) {
//
//                for (int k = j + 1; k < 8; k++) {
//
//                    b[k] = b[k] == 1 ? 0 : 1;
//
//                }
//                break;
//            }
//
//            
//        }
//    }
//    
//}
//
//
//int main()
//{
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 32; j++) {
//            int n;
//            cin >> n;
//            func(n);
//            for (int k = 7; k >= 0; k--) {
//                if (b[k] == 1) {
//                    cout << b[k];
//                }
//                else
//                    cout <<" ";
//            }
//            if (j % 2 == 1) {
//                cout << endl;
//            }
//        }
//    }
//    return 0;
//}
// int a[1000000] = { 0 };
//int main()
//{
//    a[0] = 1;
//    a[1] = 1;
//    for (int i = 2; i < 1000000; i++) {
//        if (a[i] == 0) {
//            for (int j = 2; j * i < 1000000; j++) {
//                a[i * j] = 1;
//            }
//        }
//    }
//    int count = 0;
//    for (long long i = 2; i < 1000000; i++) {
//        if (a[i] == 0) {
//            count++;
//        }
//        if (count == 2019) {
//            cout << i;
//        }
//    }
//    return 0;
//}
//class Solution {
//public:
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int cur) {
//        if (sr > image.size() - 1 || sc > image[0].size() - 1) {
//            return;
//        }
//        if (image[sr][sc] == newColor || image[sr][sc] != cur) {
//            return;
//        }
//        image[sr][sc] = newColor;
//        for (int i = 0; i < 4; i++) {
//            fill(image, sr + dx[i], sc + dy[i], newColor,cur);
//        }
//        return;
//    }
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//        int cur = image[sr][sc];
//        fill(image, sr, sc, newColor, cur);
//
//        return image;
//    }
//};
//int main() {
//    Solution s;
//    vector<vector<int>> image = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
//    int  sr = 1, sc = 1, newColor = 2;
//    s.floodFill(image,sr,sc,newColor);
//    return 0;
//}
#include<queue>
//class node {
//public:
//    node(int x, int y, string ans) {
//        this->ans = ans;
//        this->x = x;
//        this->y = y;
//    }
//public:
//    int x;
//    int y;
//    string ans;
//};
//string a[32];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//char s[4] = { 'R','L','D','U' };
//bool check(int x, int y) {
//    if (x < 0 || x>=30 || y<0 || y>=50 || a[x][y] == '1') {
//        return false;
//    }
//    return true;
//}
//int main()
//{
//    for (int i = 0; i < 30; i++) {
//            cin >> a[i];
//    }
//    queue<node> p;
//    a[0][0] = '1';
//    p.push(node{ 0,0,""});
//    while (!p.empty()) {
//        node t = p.front();
//        p.pop();
//        if (t.x == 29 && t.y == 49) {
//            cout << t.ans;
//            break;
//        }
//        for (int i = 0; i < 4; i++) {
//            if (check(t.x + dx[i], t.y + dy[i])) {
//                a[t.x + dx[i]][t.y + dy[i]] = '1';
//                node z(t.x + dx[i], t.y + dy[i], t.ans + s[i]);
//                p.push(z);
//            }
//        }
//    }
//    return 0;
//}
// #include <bits/stdc++.h>
//#define INF 0x3f3f3f3f
//using namespace std;
//typedef long long LL;
//const char d[4] = { 'D','L','R','U' };
//const int dr[4] = { 1,0,0,-1 };
//const int dc[4] = { 0,-1,1,0 };
//string mapp[32];
//int sum = 0;
//
//struct node {
//    int x, y;
//    string ans;
//    node(int x = 0, int y = 0, string ans = "") :x(x), y(y), ans(ans) {
//    }
//};
//
//queue<node> q;
//
//void bfs() {
//    node u(0, 0, "");
//    mapp[0][0] = '1';
//    q.push(u);
//    while (!q.empty()) {
//        node u = q.front();
//        q.pop();
//        if (u.x == 29 && u.y == 49) {
//            //cout<<sum<<endl;
//            cout << u.ans;
//            break;
//        }
//        for (int i = 0; i < 4; i++) {
//            int newx = u.x + dr[i], newy = u.y + dc[i];
//            if (newx < 0 || newx >= 30 || newy < 0 || newy >= 50 || mapp[newx][newy] == '1') continue;
//            mapp[newx][newy] = '1';//±ê¼Ç
//            node v(newx, newy, u.ans + d[i]);
//            q.push(v);
//        }
//    }
//}
//
//int main() {
//    for (int i = 0; i < 30; i++)
//        cin >> mapp[i];
//    bfs();
//    return 0;
//}
//DDDDRRURRRRRRRDRRRDDDLDDRDDDDDDDDDDDDRDRDRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDRDRRRRDRDRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR
//DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR

using namespace std;
int main() {
    int n;
    cin >> n;
    int t = n;
    int x = 0;
    long long ans = 1;
    string y;
    for (int i = 0; i < n; i++) {
        cin >> y;
        if (y == "0") {
            ans = 0;
            break;
        }
        int k = y.length() - 1;
        while (y[k] == '0') {
            x++;
            k--;
        }
        long long sum = 0;
        for (int j = 0; j <=k; j++) {
            sum = sum * 10 + y[j] - '0';
        }
        ans *= sum;
    }
    cout << ans;
    for (int i = 0; i < x; i++) {
        cout << 0;
    }
    return 0;
}