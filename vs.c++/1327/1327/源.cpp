#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
using namespace std;

//int main()
//{
//    int n;
//    cin >> n;
//    while (n--)
//    {
//        int wide;
//        cin >> wide;
//        char chess[16][16];
//        for (int i = 0; i < wide; i++)
//        {
//            for (int j = 0; j < wide; j++) {
//                cin >> chess[i][j];
//            }
//        }
//        int bcount = 0, wcount = 0,Black = 0, Whire = 0;
//        for (int i = 0; i < wide; i++)
//        {
//            bcount = 0, wcount = 0;
//            for (int j = 0; j <= wide; j++)
//            {
//                if (chess[i][j] != 'W')
//                {
//                    if (wcount >= 3)
//                    {
//                        Whire++;
//                    }
//                    wcount = 0;
//                }
//                else if (chess[i][j] == 'W')
//                {
//                    wcount++;
//                }
//                if (chess[i][j] != 'B')
//                {
//                    if (bcount >= 3)
//                    {
//                        Black++;
//                    }
//                    bcount = 0;
//                }
//                else if (chess[i][j] == 'B')
//                {
//                    bcount++;
//                }
//            }
//        }
//        for (int i = 0; i < wide; i++)
//        {
//            bcount = 0, wcount = 0;
//            for (int j = 0; j <= wide; j++)
//            {
//                if (chess[j][i] != 'W')
//                {
//                    if (wcount >= 3)
//                    {
//                        Whire++;
//                    }
//                    wcount = 0;
//                }
//                else if (chess[j][i] == 'W')
//                {
//                    wcount++;
//                }
//                if (chess[j][i] != 'B')
//                {
//                    if (bcount >= 3)
//                    {
//                        Black++;
//                    }
//                    bcount = 0;
//                }
//                else if (chess[j][i] == 'B')
//                {
//                    bcount++;
//                }
//            }
//        }
//        for (int i = 2; i < wide; i++)
//        {
//            bcount = 0, wcount = 0;
//            int count = 1 + i;
//            for (int j = 0; j <= count; j++)
//            {
//                if (chess[i - j][j] != 'W')
//                {
//                    if (wcount >= 3)
//                    {
//                        Whire++;
//                    }
//                    wcount = 0;
//                }
//                else if (chess[i - j][j] == 'W')
//                {
//                    wcount++;
//                }
//                if (chess[i - j][j] != 'B')
//                {
//                    if (bcount >= 3)
//                    {
//                        Black++;
//                    }
//                    bcount = 0;
//                }
//                else if (chess[i - j][j] == 'B')
//                {
//                    bcount++;
//                }
//            }
//        }
//        for (int i = 1; i < wide - 2; i++)
//        {
//            bcount = 0, wcount = 0;
//            int count = wide - i;
//            for (int j = 0; j <= count; j++)
//            {
//                if (chess[j + i][(wide - 1) - j] != 'W')
//                {
//                    if (wcount >= 3)
//                    {
//                        Whire++;
//                    }
//                    wcount = 0;
//                }
//                else if (chess[j + i][(wide - 1) - j] == 'W')
//                {
//                    wcount++;
//                }
//                if (chess[j + i][(wide - 1) - j] != 'B')
//                {
//                    if (bcount >= 3)
//                    {
//                        Black++;
//                    }
//                    bcount = 0;
//                }
//                else if (chess[j + i][(wide - 1) - j] == 'B')
//                {
//                    bcount++;
//                }
//            }
//        }
//        for (int i = 0; i < wide - 2; i++)
//        {
//            bcount = 0, wcount = 0;
//            int count = wide - i;
//            for (int j = 0; j <= count; j++)
//            {
//                if (chess[j + i][j] != 'W')
//                {
//                    if (wcount >= 3)
//                    {
//                        Whire++;
//                    }
//                    wcount = 0;
//                }
//                else if (chess[j + i][j] == 'W')
//                {
//                    wcount++;
//                }
//                if (chess[j + i][j] != 'B')
//                {
//                    if (bcount >= 3)
//                    {
//                        Black++;
//                    }
//                    bcount = 0;
//                }
//                else if (chess[j + i][j] == 'B')
//                {
//                    bcount++;
//                }
//            }
//        }
//        for (int i = 2; i < wide - 1; i++)
//        {
//            bcount = 0, wcount = 0;
//            int count = 1 + i;
//            for (int j = 0; j <= count; j++)
//            {
//                if (chess[i - j][(wide - 1) - j] != 'W')
//                {
//                    if (wcount >= 3)
//                    {
//                        Whire++;
//                    }
//                    wcount = 0;
//                }
//                else if (chess[i - j][(wide - 1) - j] == 'W')
//                {
//                    wcount++;
//                }
//                if (chess[i - j][(wide - 1) - j] != 'B')
//                {
//                    if (bcount >= 3)
//                    {
//                        Black++;
//                    }
//                    bcount = 0;
//                }
//                else if (chess[i - j][(wide - 1) - j] == 'B')
//                {
//                    bcount++;
//                }
//            }
//        }
//        cout << Black << " " << Whire << endl;
//    }
//}
int main()
{
	char n=' ';
	char a[51][51];
	while (n!='#') {
		cin >> n;
		for (int i = 0; i <= n-'A'; i++) {
			for (int j = 0; j <= n - 'A'; j++) {
				a[i][j] = i > j ? i+65 : j+65;
				a[i][2 * (n - 'A')-j] = a[i][j];
			}
		}
		for (int i = 0; i <= n - 'A'; i++) {
			for (int j = 0; j <= 2 * (n - 'A'); j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
		for (int i = n - 'A'-1; i >=0; i--) {
			for (int j = 0; j <= 2 * (n - 'A'); j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}