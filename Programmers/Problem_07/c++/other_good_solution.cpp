#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx_front = 0;
    int idx_cur = 0;
    int sec = 0;
    int tot_weight = 0;

    std::queue<int> queue;

    while(idx_front < truck_weights.size()){
        // condition of deleting to queue
        if(!queue.empty() && (sec - queue.front() == bridge_length)){
            tot_weight -= truck_weights[idx_front++];
            queue.pop();
        }

        if(idx_cur < truck_weights.size() && tot_weight + truck_weights[idx_cur] <= weight){
            tot_weight += truck_weights[idx_cur++];
            queue.push(sec);
        }

        sec++;
    }

    answer = sec;

    return answer;
}

void tc1(){
	int bridge_length = 2;
	int weight = 10;
    std::vector<int> truck_weights = {7,4,5,6};

    int answer = solution(bridge_length, weight, truck_weights);
    if(answer == 8){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	int bridge_length = 100;
	int weight = 100;
    std::vector<int> truck_weights = {10};

    int answer = solution(bridge_length, weight, truck_weights);
    if(answer == 101){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
	int bridge_length = 100;
	int weight = 100;
    std::vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};

    int answer = solution(bridge_length, weight, truck_weights);
    if(answer == 110){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    tc2();
	tc3();
    return 0;
}