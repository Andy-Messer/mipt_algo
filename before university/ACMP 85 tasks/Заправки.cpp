#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
 
vector <vector <pair<int,int>>>g;
int n,a,b;
vector <int> vs;
int main(){
    cin >>n;
    for (int i=0;i<n;i++){
        int u;
        cin >>u;
        vs.push_back(u);
    }
    int m;
    cin >>m;
    g.resize(n,vector <pair<int,int>>());
    for (int i=0;i<m;i++){
        int c,a2;
        cin>>a2>>b;a2--;b--;
        g[a2].push_back({vs[a2],b});
        g[b].push_back({vs[b],a2});
    }
    a=0;
    set <pair<int,int>>s;
    vector <int>d(n,INT_MAX);
    vector <int>pred(n,-1);
    d[a]=0;
    s.insert({0,a});
    while (!s.empty()){
        pair <int,int> now=*s.begin();
        int to=now.second;int ves=d[to];
        s.erase(s.begin());
        for (auto now_2:g[to]){
            int ves_2=now_2.first;
            int to_2=now_2.second;
            if (ves+ves_2<d[to_2]){
                s.erase({d[to_2],to_2});
                d[to_2]=ves+ves_2;
                pred[to_2]=to;
                s.insert({d[to_2],to_2});}
        }
    }
    if (d[n-1]==INT_MAX){
        cout <<-1;
    }else{
    cout <<d[n-1];
    }
}