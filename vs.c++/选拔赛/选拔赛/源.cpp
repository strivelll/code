#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<iostream>
//using namespace std;
//int main() {
//    int arr[6], k;
//    int brr[6];
//    for (int i = 0; i < 6; i++) {
//        cin >> arr[i];
//        brr[i] = arr[i];
//    }
//    cin >> k;
//    int c = 6;
//    while (k--) {
//        for (int i = 0; i < 6; i++) {
//            if (arr[i] != c&&c!=brr[i]) {
//                arr[i] = c;
//            }
//            else {
//                arr[i] = c - 1;
//            }
//        }
//        c--;
//    }
//    for (int i = 0; i < 6; i++) {
//        cout << arr[i] << " ";
//    }
//    return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//    string s1,s2;
//    string a;
//    string b;
//    cin >> a;
//    cin >> b;
//    for (int i = 1; i < a.length(); i++) {
//        if (a[i] % 2 == a[i - 1] % 2) {
//            s1 += max(a[i], a[i - 1]);
//        }
//    }
//    cout << s1 << endl;
//    for (int i = 1; i < b.length(); i++) {
//        if (b[i] % 2 == b[i - 1] % 2) {
//            s2 += max(b[i], b[i - 1]);
//        }
//    }
//    cout << s2 << endl;
//    return 0;
//}
//#include<iostream>
//#include<set>
//using namespace std;
//int main() {
//	int n, m, q;
//	cin >> n >> m >> q;
//	int count = n;
//	int count1 = m;
//	set<int> s1,s2;
//	for (int i = 0; i < q; i++) {
//		int t,c;
//		cin >> t >> c;
//		if (t == 0&&s1.find(c)==s1.end()) {
//			s1.insert(c);
//			count--;
//		}
//		else if (t == 1 && s2.find(c) == s2.end()) {
//			s2.insert(c); count1--;
//		}
//	}
//	cout << count1 * count << endl;;
//	return 0;
//}
//#include<iostream>
//#include<stack>
//using namespace std;
//int main() {
//    int n, m, q;
//    stack<int> a;
//    cin >> n >> m >> q;
//    int arr[1010] = {0}, ans[20] = { 0 };
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    int j = 0,i=0;
//    while (j<=n) {
//        i = 0;
//        if (!a.empty()) {
//            if (i == 0 || a.top() <= ans[i-1]) {
//                ans[i++] = a.top();
//                cout << ans[i - 1] << " ";
//                a.pop();
//            }
//        }
//        while (a.size() < m && j < n && i < q) {
//            if (!a.empty()) {
//                if (a.top() <= ans[i-1]) {
//                    ans[i++] = a.top();
//                    cout << ans[i - 1] << " ";
//                    a.pop();
//                }
//            }
//            if (i == 0|| arr[j] < arr[i]) {
//                ans[i++] = arr[j++];
//                cout << ans[i - 1] << " ";
//            }
//            else {
//                a.push(arr[j++]);
//            }
//        }
//        cout << endl;
//        j++;
//        memset(ans, 0, 20);
//    }
//}
#include<iostream>
#include<stack>
using namespace std;
int main() {
    int n, m, q;
    stack<int> a;
    cin >> n >> m >> q;
    int arr[1010] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int j = 0, i = 0;
    while (j < n) {
        int ans[20] = { 0 };
        i = 0;
        if (!a.empty()) {
            if (i == 0 || a.top() <= ans[i - 1]) {
                ans[i++] = a.top();
                cout << ans[i - 1] << " ";
                a.pop();
            }
        }
        while ((int)a.size() < m && j < n && i < q) {
            if (!a.empty()) {
                if (i>0&&a.top() <= ans[i - 1]) {
                    ans[i++] = a.top();
                    cout << ans[i - 1] << " ";
                    a.pop();
                }
            }
            if (i==0||arr[j] <= arr[i-1]) {
                ans[i++] = arr[j++];
                cout << ans[i - 1] << " ";
            }
            else {
                a.push(arr[j++]);
            }
        }
        cout << endl;
    }
}