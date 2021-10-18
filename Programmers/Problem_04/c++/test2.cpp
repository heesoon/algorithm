#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    std::unordered_map<std::string, int> best_genres;

#if 0
    auto cmp = [](const std::pair<int, int> &a, const std::pair<int, int> &b){
        return a.second > b.second;
    };
    std::unordered_map<std::string, std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)>> best_genres_play(cmp);
#else

    std::unordered_map<std::string, std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)>> best_genres_play(cmp);
#endif


    for(std::vector<std::string>::size_type i = 0; i < genres.size(); i++){
        best_genres[genres[i]] += plays[i];
        best_genres_play[genres[i]].push({i, plays[i]});
    }

    std::vector<std::pair<std::string, int>> ordered_best_genres(best_genres.begin(), best_genres.end());
    std::sort(ordered_best_genres.begin(), ordered_best_genres.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b){
        return a.second > b.second;
    });

    for(const auto& v : ordered_best_genres){
        int cnt = 0;
        while(best_genres_play[v.first].empty() == false){
            answer.push_back(best_genres_play[v.first].top());
            best_genres_play[v.first].pop();
            if(cnt++ > 1){
                break;
            }
        } 
    }

    return answer;
}

void tc1(){
    std::vector<std::string> genres = {"classic", "pop", "classic", "classic", "pop"};
    std::vector<int> plays = {500, 600, 150, 800, 2500};

    std::vector<int> answer = solution(genres, plays);
    if(answer == std::vector<int>({4, 1, 3, 0})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}