#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> schedule;

    for(int i = 0; i < n; i++){
        int start, end;
        std::cin >> start >> end;
        schedule.push_back(std::make_pair(end, start));
    }

    std::sort(schedule.begin(), schedule.end());

    int time = schedule[0].first;
    int cnt = 1;

    for(int i = 1; i < n; i++){
        if(schedule[i].second >= time){
            time = schedule[i].first;
            cnt++;
        }
    }

    std::cout << cnt << "\n";

    return 0;
}