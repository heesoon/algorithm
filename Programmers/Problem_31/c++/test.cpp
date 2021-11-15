#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int cnt, std::string str, std::vector<int> &visited, std::vector<std::string> &answer, std::vector<std::string> &temp, vector<vector<string>> tickets){
    bool retval = false;
    temp.push_back(str);

    if(cnt == tickets.size()){
        answer = temp;
        return true;
    }

#if 0
    for(const auto &v : visited){
        std::cout << v << " ";
    }
    std::cout << std::endl;
#endif

    for(vector<vector<string>>::size_type i = 0; i < tickets.size(); i++){
        if(str == tickets[i][0] && visited[i] == 0){
            //std::cout << " >> " << i << " , " << str << std::endl;
            visited[i] = 1;
            retval = dfs(cnt+1, tickets[i][1], visited, answer, temp, tickets);
            visited[i] = 0;
            if(retval == true){
                return true;
            }
        }
    }
    temp.pop_back();
    return retval;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    std::vector<int> visited(tickets.size(), 0);
    std::sort(tickets.begin(), tickets.end());

#if 0
    for(const auto &v : tickets){
        std::cout << v[0] << " , " << v[1] << std::endl;
    }
    std::cout << std::endl;
#endif
    
    dfs(0, "ICN", visited, answer, temp, tickets);

#if 0
    for(const auto &v : answer){
        std::cout << v << " ";
    }
    std::cout << std::endl;
#endif

    return answer;
}

void tc1(){
	std::vector<std::vector<std::string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};

    std::vector<std::string> answer = solution(tickets);
    if(answer == std::vector<std::string>({"ICN", "JFK", "HND", "IAD"})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::vector<std::vector<std::string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};

    std::vector<std::string> answer = solution(tickets);
    if(answer == std::vector<std::string>({"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"})){
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