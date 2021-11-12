#include <iostream>
#include <string>
#include <vector>

using namespace std;

int depth = 87654321;
std::vector<int> visited;

int wdiff(const std::string &a, const std::string &b){
    int cnt = 0;
    for(std::string::size_type i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            cnt++;
        }
    }

    return cnt;
}

void  dfs(int cnt, std::string begin, std::string target, std::vector<std::string> words){
    //std::cout << cnt << " , " << begin << " , " << " , " << target << std::endl;
    if(cnt > words.size()){
        return;
    }
    
    if(begin == target){
        if(depth > cnt){
            depth = cnt;
        }
        return;
    }

    for(int i = 0; i < words.size(); i++){
        if(wdiff(begin, words[i]) == 1 && visited[i] == 0){
            visited[i] = 1;
            dfs(cnt+1, words[i], target, words);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    depth = 87654321;
    visited.assign(words.size(), 0);
    dfs(0, begin, target, words);
    visited.clear();
    answer = (depth == 87654321) ? 0 : depth;

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

void tc3(){
	std::string begin = "hit";
	std::string target = "cog";
	std::vector<std::string> words = {"cog", "log", "lot", "dog", "dot", "hot"};

    int answer = solution(begin, target, words);
    if(answer == 4){
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