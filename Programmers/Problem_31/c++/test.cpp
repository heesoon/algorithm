#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    return answer;
}

void tc1(){
	std::vector<std::vector<std::string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};

    std::vector<std::vector<std::string>> answer = solution(routes);
    if(answer == std::vector<std::vector<std::string>>({"ICN", "JFK", "HND", "IAD"})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::vector<std::vector<std::string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};

    std::vector<std::vector<std::string>> answer = solution(routes);
    if(answer == std::vector<std::vector<std::string>>({"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"})){
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