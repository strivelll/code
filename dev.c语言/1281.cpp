#include<stdio.h>
#include<string.h>
int main()
{
    char a[201];
    while(gets(a) )
    {
        int f[26]={0};
        int count=0,x=0;
        int b=strlen(a);
        for(int i=0;i<b;i++){
            if(a[i]==' '){
               count++;
            }
			}
			for(int i=0;i<b;i++){
				for(int j=0;j<26;j++){
				if(a[i]==j+'a'||a[i]==j+'A'){
				if(f[j]==0){
                    	f[j]++;
						x++; 
                    }
                }
            }
			}
            if(x<=10&&count<10){
                printf("Yes\n");
            }
            else
            printf("No\n");
    }
     return 0;
}

