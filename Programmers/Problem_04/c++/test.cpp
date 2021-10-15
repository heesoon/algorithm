#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    std::unordered_map<std::string, int> best_genre;
    std::unordered_map<std::string, std::vector<std::tuple<int, int>>> best_genre_play;

    for(std::vector<std::string>::size_type i = 0; i < genres.size(); i++){
        best_genre[genres[i]] += plays[i];
        best_genre_play[genres[i]].push_back({i, plays[i]});
    }

    std::vector<std::tuple<std::string, int>> vbest_genre(best_genre.begin(), best_genre.end());
    std::sort(vbest_genre.begin(), vbest_genre.end(), [](const std::tuple<std::string, int> &a, const std::tuple<std::string, int> &b){
        return std::get<1>(a) > std::get<1>(b);
    });

    for(auto& map : best_genre_play){
        std::sort(std::get<1>(map).begin(), std::get<1>(map).end(), [](const std::tuple<int, int> &a, const std::tuple<int, int> &b){
            return std::get<1>(a) > std::get<1>(b);
        });
    }

    for(const auto& sorted_genre : vbest_genre){
        int cnt = 0;
        for(const auto& play : best_genre_play[std::get<0>(sorted_genre)]){
            if(cnt > 1){
                break;
            }
            answer.push_back(std::get<0>(play));
            cnt++;
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