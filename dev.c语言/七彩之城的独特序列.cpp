#include <bits/stdc++.h>
#include<set> 
using namespace std;
int n;
int a[100010]={0};
int b[100010]={0};
unsigned long long ans=0;
void dfs(int pos,unordered_set<int>set){
  if(pos==n){
    ans=(ans+1)%(1000000000+7);
    return ;
  }
  for(int i=0;i<n;i++){
    if(b[i]==0&&set.count(a[i])==0){
      b[i]=1;
      set.insert(a[i]);
      dfs(pos+1,set);
      set.erase(a[i]);
      b[i]=0;
    }
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  unordered_set<int>set;
  dfs(0,set);
  cout<<ans;
  return 0;
}
