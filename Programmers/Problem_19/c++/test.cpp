#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    return answer;
}

void tc1(){
	std::string name = "JEROEN";

    int answer = solution(name);
    if(answer == 56){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::string name = "JAN";

    int answer = solution(name);
    if(answer == 23){
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