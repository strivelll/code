#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include <stdio.h>

int T, N;
__int64 ak47[50][5];
__int64 ans;

void slove()
{
    ak47[1][1] = ak47[1][2] = ak47[1][3] = ak47[1][4] = 1;
    for (int i = 2; i <= 45; i++)
    {
        ak47[i][1] = ak47[i - 1][2] + ak47[i - 1][3];
        ak47[i][2] = ak47[i - 1][1] + ak47[i - 1][3] + ak47[i - 1][4];
        ak47[i][3] = ak47[i - 1][1] + ak47[i - 1][2] + ak47[i - 1][4];
        ak47[i][4] = ak47[i - 1][2] + ak47[i - 1][3];
    }
}

int main()
{
    slove();                // µÝÍÆ
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        ans = ak47[N][1] + ak47[N][2] + ak47[N][3] + ak47[N][4];
        printf("%I64d\n", ans);
    }
    return 0;
}