#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    return answer;
}

void tc1(){
	std::string number = "1924";
	int k = 2;
	
    std::string answer = solution(number, k);
    if(answer == "94"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::string number = "1231234";
	int k = 3;
	
    std::string answer = solution(number, k);
    if(answer == "3234"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
	std::string number = "4177252841";
	int k = 4;
	
    std::string answer = solution(number, k);
    if(answer == "775841"){
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