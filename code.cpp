#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    const int MOD=1e9+7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>,vector<vector<int>>,
            CmpClass1> sellQ;
        // priority_queue<vector<int>,vector<vector<int>>,
        //     greater<vector<int>>> sellQ;        
        priority_queue<vector<int>,vector<vector<int>>,
            CmpClass2> buyQ;
        // priority_queue<vector<int>,vector<vector<int>>,
        //    less<vector<int>>> buyQ;

        for(auto paper:orders){
            if(paper[2]==0){  //buy
                while(sellQ.size()&&paper[1]){
                    auto miniSell=sellQ.top();
                    if(miniSell[0]<=paper[0]){
                        auto del=min(miniSell[1],paper[1]);
                        miniSell[1]-=del;
                        paper[1]-=del;

                        sellQ.pop();
                        if(miniSell[1]){
                            sellQ.push(miniSell);
                        }
                    }
                    else {
                        break;
                    }
                }
                if(paper[1]){
                    buyQ.push(paper);
                }                
            }else{
                while(buyQ.size()&&paper[1]){   //sell
                    auto maxBuy=buyQ.top();
                    if(maxBuy[0]>=paper[0]){
                        auto del=min(maxBuy[1],paper[1]);
                        maxBuy[1]-=del;
                        paper[1]-=del;

                        buyQ.pop();
                        if(maxBuy[1]){
                            buyQ.push(maxBuy);
                        }
                    }
                    else{
                        break;
                    }
                }                
                if(paper[1]){
                    sellQ.push(paper);
                }
            }
        }
        long long ans=0;
        while(sellQ.size()){
            auto & top=sellQ.top();
            ans+=1ll*top[1];
            ans%=MOD;
            sellQ.pop();
        }
        while(buyQ.size()){
            auto & top=buyQ.top();
            ans+=1ll*top[1];
            ans%=MOD;
            buyQ.pop();
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> a={{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    Solution solver;
    int ans=solver.getNumberOfBacklogOrders(a);
    cout<<ans<<endl;
    
    system("pause");
    return 0;
}