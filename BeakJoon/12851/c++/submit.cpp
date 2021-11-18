#include <iostream>
#include <queue>

using namespace std;

const int LIMIT = 100'000 + 1;;
bool visited[LIMIT];
int minPathCnt = 0;
int minCost = 0;

int solution(int N, int K) {
    
    queue<pair<int,int>> Q;
    Q.push(make_pair(N, 0));
    visited[N] = true;

    while(!Q.empty()){
        int curr = Q.front().first;
        int depth = Q.front().second;
        Q.pop();

        visited[curr] = true;
        //visited[K] = false;

        if(minCost && minCost == depth && curr == K){
            minPathCnt++;
        }

        if(!minCost && curr == K){
            minCost = depth;
            minPathCnt++;
        }
        
        if(curr + 1 < LIMIT && visited[curr + 1] == false){
            //visited[curr + 1] = true;
            Q.push(make_pair(curr + 1, depth+1));
        }
        
        if(curr - 1 >= 0 && visited[curr - 1] == false){
            //visited[curr - 1] = true;
            Q.push(make_pair(curr - 1, depth+1));
        }

        if(curr * 2 < LIMIT && visited[curr*2] == false){
            //visited[curr*2] = true;
            Q.push(make_pair(curr*2, depth+1));
        }
    }

    return minCost;
}


int main(){   
    int N, K;
    cin >> N >> K;

    cout << solution(N, K) << "\n";
    cout << minPathCnt << std::endl;
    return 0;
}