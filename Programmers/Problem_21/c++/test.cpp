#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
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