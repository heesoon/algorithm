#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100'000 + 1;
bool visited[MAX];
int parents[MAX];
std::vector<int> shortPath;

int solution(int N, int K) {
    int answer = 0;
    int nextNode = 0;
    std::queue<std::vector<int>> Q;
    Q.push({N, 0});
    visited[N] = true;
    //parents[N] = N;

    while(!Q.empty()){
        int curNode = Q.front()[0];
        int elapseTime = Q.front()[1];
        Q.pop();

        if(curNode == K){
            answer = elapseTime;
            int node = curNode;
            while(node != N){
                auto it = shortPath.begin();
                shortPath.insert(it, node);
                node = parents[node];
            }

            auto it = shortPath.begin();
            shortPath.insert(it, N);
            break;
        }

        nextNode = curNode*2;
        if(nextNode < MAX && !visited[nextNode]){
            visited[nextNode] = true;
            parents[nextNode] = curNode;
            Q.push({nextNode, elapseTime+1});
        }

        nextNode = curNode - 1;
        if(nextNode >= 0 && !visited[nextNode]){
            visited[nextNode] = true;
            parents[nextNode] = curNode;
            Q.push({nextNode, elapseTime+1});
        }

        nextNode = curNode + 1;
        if(nextNode < MAX && !visited[nextNode]){
            visited[nextNode] = true;
            parents[nextNode] = curNode;
            Q.push({nextNode, elapseTime+1});
        }
    }

    return answer;
}

int main(){   
    int N, K;
    std::cin >> N >> K;
    std::cout << solution(N, K) << std::endl;

    for(const auto &v : shortPath){
        std::cout << v << " ";
    }
    std::cout << "\n";

    return 0;
}