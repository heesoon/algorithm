#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    return answer;
}

void tc1(){
	int n = 6;
	std::vector<int> times = {7, 10};

    long long answer = solution(n, times);
    if(answer == 28){
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