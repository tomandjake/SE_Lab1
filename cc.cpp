#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <vector>
#include<string>
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
const int maxn = 100000005;

<<<<<<< HEAD
int n,m,k,mabit,asd;
int bbb;
vector<int> a;

int main() {
    freopen("C:\\Users\\10982\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\10982\\Desktop\\out.txt","w",stdout);

    cin>>n>>m>>k;
    a.resize(n);
    mabit=(1<<k)-1;
    for(int i=0;i<n;++i){
        int tmp=0,num;
        cin>>num;
        while(num--){
            int x;cin>>x;
            x--;
            int tmp1=(1<<x);
            tmp=tmp|tmp1;
        }
        a[i]=tmp;
    }
    
    int ans=0;
    for(int scheme=0;scheme<=mabit;++scheme){
        if(!Valid(scheme)) continue;
        int cnt=0;
        for(int i=0;i<n;++i){
            if(a[i]-(a[i]&scheme)==0){
                cnt++;    
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;

    return 0;
}