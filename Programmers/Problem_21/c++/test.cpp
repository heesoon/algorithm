#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int lIdx = 0, rIdx = people.size() - 1;
    std::sort(people.begin(), people.end(), std::less<int>());
    
    while(lIdx <= rIdx){
        if(people[rIdx] + people[lIdx] <= limit){
            rIdx--;
            lIdx++;
            answer++;
        }
        else{
            rIdx--;
            answer++;
        }
    }

    return answer;
}

void tc1(){
    std::vector<int> people = {70, 50, 80, 50};
	int limit = 100;

    int answer = solution(people, limit);
    if(answer == 3){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> people = {70, 80, 50};
	int limit = 100;

    int answer = solution(people, limit);
    if(answer == 3){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
	tc2();
    return 0;
}