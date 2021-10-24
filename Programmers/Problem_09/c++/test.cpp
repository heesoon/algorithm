#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(scoville.begin(), scoville.end());

    while(pq.size() >= 2){
        if(pq.top() >= K){
            break;
        }
        else{
            int A = pq.top();
            pq.pop();
            int B = pq.top();
            pq.pop();

            pq.push(A + B*2);
        }

        answer++;
    }

    if(pq.top() < K){
        return -1;
    }

    return answer;
}

void tc1(){
    std::vector<int> scoville = {1, 2, 3, 9, 10, 12};
	int K = 7;

    int answer = solution(scoville, K);
    if(answer == 2){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}