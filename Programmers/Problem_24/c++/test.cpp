#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    return answer;
}

void tc1(){
	int N = 5;
	int number = 12;

    int answer = solution(routes);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	int N = 2;
	int number = 11;

    int answer = solution(routes);
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