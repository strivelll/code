#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//int transsore(int x) {
//    if (x >= 1 && x <= 12)
//        x = 32;
//    else if (x >= 13 && x <= 24)
//        x = 16;
//    else if (x >= 25 && x <= 48)
//        x = 8;
//    else if (x >= 49 && x <= 96)
//        x = 4;
//    else if (x >= 97 && x <= 192)
//        x = 2;
//    else if (x >= 193)
//        x = 1;
//    return x;
//}
//int main()
//{
//	int n;
//	int r;
//	int i = 0;
//    long long ans[500][2];
//    vector<int> b;
//    long long aa;
//	while (scanf("%d %lld %d", &n, &aa, &r)!=EOF){
//        ans[i][0] = aa;
//        b.push_back(transsore(r));
//        if (i == 36)break;
//	}
//    sort(b.begin(), b.end(),greater<int>());
//    double t = b[0];
//    for (int j = 0; j < i; j++) {
//        double sore = log(b[j] / t) * 10 + 100.5;
//        b[j] = (int)sore;
//    }
//    for (int j = 0; j < i; j++) {
//        int k = j;
//        while (j+1<i&&b[j] == b[j + 1]) {
//            j++;
//        }
//        int judge = 1;
//        while (judge)
//        {
//            judge = 0;
//            for (int w=0;w<j;w++)
//            {
//                if (a[w] > a[w + 1])
//                {
//                    swap(a[w], a[w + 1]);
//                    judge = 1;
//                }
//            }
//        }
//    }
//    for (int j = 0; j < i; j++) {
//        cout<<a[j]<<" "<<b[j] << endl;
//    }
//	return 0;
//}
class Solution {
public:
    string capitalizeTitle(string title) {
        int k = 0;
        for (int i = 0; i < title.length(); i++) {
            k = 0;
            int j = i;
            while (j < title.length() && title[j] != ' ') {
                j++;
                k++;
            }
            if (k > 2) {
                if (title[i] > 'a')
                    title[i] -= 32;
                for (int x = i + 1; x < j; x++) {
                    if (title[x] < 'a') {
                        title[x] += 32;
                    }
                }
                i = j;
            }
            else {
                for (int x = i; x < j; x++) {
                    if (title[x] < 'a') {
                        title[x] += 32;
                    }
                }
                i = j;
            }
        }
        return title;
    }
};
int main() {
    Solution s;
    cout<<s.capitalizeTitle("IkjmZAFaBZGTDhWRk nkFnQKKQboxML axXokKMsSxz");
	return 0;
}