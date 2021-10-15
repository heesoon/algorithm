#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    return answer;
}

void tc1(){
    std::vector<int> numbers = {6, 10, 2};

    std::string answer = solution(numbers);
    if(answer == "6210"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> numbers = {3, 30, 34, 5, 9};

    std::string answer = solution(numbers);
    if(answer == "9534330"){
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