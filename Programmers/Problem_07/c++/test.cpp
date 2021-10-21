#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0;
    std::deque<int> queue;

    for(int i = 0; i < bridge_length; i++){
        queue.push_back(0);
    }

    while(queue.empty() == false || truck_weights.empty() == false){
        if(truck_weights.empty() == false){
            int vfront = *truck_weights.begin();
            int qfront = queue.front();

            if(total_weight + vfront -qfront <= weight){
                total_weight += vfront;
                truck_weights.erase(truck_weights.begin());

                total_weight -= qfront;
                queue.pop_front();
                queue.push_back(vfront);
            }
            else{
                total_weight -= qfront;
                queue.pop_front();
                queue.push_back(0);
            }
        }
        else{
            queue.pop_front();
        }

        answer++;
    }

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