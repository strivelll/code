#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> z,z1,z2;
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(') {
//                z.push(s[i]);
//            }
//            else if (s[i] == ')') {
//                if (!z.empty())
//                    z.pop();
//                else
//                    return false;
//            }
//            
//            if (s[i] == '[') {
//                z1.push(s[i]);
//            }
//            else if (s[i] == ']') {
//                if (!z1.empty())
//                    z1.pop();
//                else
//                    return false;
//            }
//            if (s[i] == '{') {
//                z2.push(s[i]);
//            }
//            else if (s[i] == '}') {
//                if (!z2.empty())
//                    z2.pop();
//                else
//                    return false;
//            }
//        }
//        return true;
//    }
//};
//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        int count = 0;
//        s.reserve();
//        for (int i = s.length() - 1; i >= 0; i--) {
//            if (s[i] == ' ' && count != 0) {
//                break;
//            }
//            if(s[i]!=' ')
//               count++;
//        }
//        return count;
//    }
//
//};
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> z;
//        int count = s.length() / 2;
//        if (s.length() % 2 != 0) {
//            return false;
//        }
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
//                z.push(s[i]);
//            }
//            else {
//                if (s[i] == ')') {
//                    if (!z.empty()) {
//                        if (z.top() != '(')
//                            return false;
//                        else {
//                            z.pop();
//                            count--;
//                        }
//                    }
//                    else
//                        return false;
//                }
//                if (s[i] == '}') {
//                    if (!z.empty()) {
//                        if (z.top() != '{')
//                            return false;
//                        else {
//                            z.pop();
//                            count--;
//                        }
//                    }
//                    else
//                        return false;
//                }
//                if (s[i] == ']') {
//                    if (!z.empty()) {
//                        if (z.top() != '[')
//                            return false;
//                        else {
//                            z.pop();
//                            count--;
//                        }
//                    }
//                    else
//                        return false;
//                }
//            }
//        }
//        if (count) {
//            return false;
//        }
//        return true;
//    }
//};
//class Solution {
//public:
//    bool isValid(string s) {
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(') {
//                if (s[i + 1] == ')') {
//                    i++;
//                    continue;
//                }
//                else
//                    return false;
//            }
//            else if (s[i] == '[') {
//                if (s[i + 1] == ']') {
//                    i++;
//                    continue;
//                }
//                else
//                    return false;
//            }
//            else if (s[i] == '{') {
//                if (s[i + 1] == '}') {
//                    i++;
//                    continue;
//                }
//                else
//                    return false;
//            }
//        }
//        return true;
//    }
//};
class Solution {
public:
    string addBinary(string a, string b) {
        int ca = 0;
        string ans;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = ca;
            sum +=( i >= 0 ? a[i] - '0' : 0);

            sum +=( j >= 0 ? b[j] - '0' : 0);
            char str[10];
            sprintf(str, "%d", sum % 2);
            ans += str;
            ca = sum / 2;
        }
        if (ca == 1) {
            ans += "1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    //Solution s;
    string ss("dasjlasfjfkd");
    reverse(ss.begin(), ss.end());
    int a = 10;
    int b = 20;
    cout << min(a, b) << endl;
    cout <<ss<< endl;
    __gcd(a, b);
	return 0;
}