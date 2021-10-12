#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>

void test_case_1(){
    std::vector<std::string> genres = {"classic", "pop", "classic", "classic", "pop"};
    std::vector<int> plays = {500, 600, 150, 800, 2500};

    std::map<std::string, int> bestGenres;
    std::map<std::string, std::vector<std::tuple<int,int>>> bestGenresAlbums;
    std::vector<int> bestAlbums;
    for(std::vector<int>::size_type i = 0; i < plays.size(); i++){
        bestGenres[genres[i]] += plays[i];
        bestGenresAlbums[genres[i]].push_back({i, plays[i]});
    }

#if 0
    std::cout << "original best Genres" << std::endl;
    for(auto x : bestGenres){
        std::cout << std::get<0>(x) << ", " << std::get<1>(x)  << std::endl;
    }
#endif

    // sorting bestAlbum
    std::vector<std::tuple<std::string, int>> vBestGenres(bestGenres.begin(), bestGenres.end());
    std::sort(vBestGenres.begin(), vBestGenres.end(), [](const std::tuple<std::string, int> &a, const std::tuple<std::string, int> &b){
        return std::get<1>(a) > std::get<1>(b);
    });

#if 0
    std::cout << "ordered best Genres" << std::endl;
    for(auto x : vBestGenres){
        std::cout << std::get<0>(x) << ", " << std::get<1>(x)  << std::endl;
    }
#endif

    for(auto x : vBestGenres){
        std::string genres = std::get<0>(x);
        std::sort(bestGenresAlbums[genres].begin(), bestGenresAlbums[genres].end(), [](const std::tuple<int, int> &a, const std::tuple<int, int> &b){
            return std::get<1>(a) > std::get<1>(b);
        });

        int cnt = 0;
        for(auto a : bestGenresAlbums[genres]){
            if(cnt >= 2){
                break;
            }
            bestAlbums.push_back(std::get<0>(a));
            cnt++;
        }
    }

    for(auto d : bestAlbums){
        std::cout << d << " ";
    }
    std::cout << std::endl;
}

int main(){
    test_case_1();
    return 0;
}