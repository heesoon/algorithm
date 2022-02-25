#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int n, m, t;
std::vector<std::vector<std::pair<int,int>>> G;
const int INF = std::numeric_limits<int>::max()/2;

std::vector<int> solve(int start){
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> Q;
    std::vector<int> distance(n+1, INF);
    Q.push(std::make_pair(0, start));
    distance[start] = 0;

    while(!Q.empty()){
        int fWeight = Q.top().first;
        int fNode = Q.top().second;
        Q.pop();

        for(auto p : G[fNode]){
            int nNode = p.first;
            int nWeight = p.second + fWeight;

            if(nWeight < distance[nNode]){
                distance[nNode] = nWeight;
                Q.push(std::make_pair(nWeight, nNode));
            }
        }
    }

    return distance;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while(T--){
        int s, g, h, dgh;
        int crossRoad1, crossRoad2;
        std::vector<int> ans;

        std::cin >> n >> m >> t;
        G = std::vector<std::vector<std::pair<int,int>>>(n+1);
        std::cin >> s >> g >> h;

        for(int i = 0; i < m; i++){
            int a, b, d;
            std::cin >> a >> b >> d;
            G[a].push_back(std::make_pair(b, d));
            G[b].push_back(std::make_pair(a, d));

            if((a == g && b == h) || (a == h && b == g))
                dgh = d;
        }

        auto result1 = solve(s);

        if(result1[g] > result1[h]){
            crossRoad1 = h;
            crossRoad2 = g;
        }
        else{
            crossRoad1 = g;
            crossRoad2 = h;            
        }

        auto result2 = solve(crossRoad2);

        for(int i = 0; i < t; i++){
            int x;
            std::cin >> x;
            if(result1[x] == result1[crossRoad1] + dgh + result2[x]){
                ans.push_back(x);
            }
        }

        std::sort(ans.begin(), ans.end());

        for(const auto &a : ans){
            std::cout << a << " ";
        }
        std::cout << "\n";
    }
    return 0;
}