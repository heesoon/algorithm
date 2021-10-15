#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    return answer;
}

void tc1(){
	std::vector<int> numbers = {1, 1, 1, 1, 1};
	int target = 3;

    int answer = solution(numbers, target);
    if(answer == 5){
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