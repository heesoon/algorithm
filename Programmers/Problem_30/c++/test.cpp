#include <string>
#include <vector>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    return answer;
}

void tc1(){
	std::string begin = "hit";
	std::string target = "cog";
	std::vector<std::string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    int answer = solution(begin, target, words);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::string begin = "hit";
	std::string target = "cog";
	std::vector<std::string> words = {"hot", "dot", "dog", "lot", "log"};

    int answer = solution(begin, target, words);
    if(answer == 0){
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