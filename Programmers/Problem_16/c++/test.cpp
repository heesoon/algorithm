#include <string>
#include <vector>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    return answer;
}

void tc1(){
    std::string numbers = "17";

    int answer = solution(numbers);
    if(answer == 3){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::string numbers = "011";

    int answer = solution(numbers);
    if(answer == 2){
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