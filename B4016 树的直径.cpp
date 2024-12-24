#include <bits/stdc++.h>
using namespace std;
int n,c;
int dis[100005];
vector<int>a[100005];
int read(){
	int x=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') w=-w;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*w;
}
void dfs(int u,int fa){
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(v==fa) continue;
        dis[v]=dis[u]+1;
        if(dis[v]>dis[c]) c=v;
        dfs(v,u);
    }
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    dis[c]=0;
    dfs(c,1);
    cout<<dis[c]<<'\n';
    return 0;
}
