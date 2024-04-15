#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c,d,e,f;
        int t;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        if(b>c)
        {
            t=b;
            b=c;
            c=t;
        }
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        if(d>e)
        {
            t=d;
            d=e;
            e=t;
        }
        if(e>f)
        {
            t=e;
            e=f;
            f=t;
        }
        if(d>e)
        {
            t=d;
            d=e;
            e=t;
        }
        if(a*e==b*d&&b*f==c*e)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
