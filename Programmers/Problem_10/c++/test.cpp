#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    bool bstart = true;
    int first_start_time = 0;
    int prev_end_time = 0;
    int total = 0;

    auto cmp = [](const std::tuple<int,int> &a, const std::tuple<int,int> &b){
        if(std::get<0>(b) + std::get<1>(b) - std::get<0>(a) < std::get<0>(a) + std::get<1>(a) - std::get<0>(b)){
            return true;
        }
        return false;
    };
    std::priority_queue<std::tuple<int,int>, std::vector<std::tuple<int,int>>, decltype(cmp)> pq(cmp);

    for(const auto& v : jobs){
        pq.push({v[0], v[1]});
    }

    while(!pq.empty()){
        auto top = pq.top();
        //std::cout << std::get<0>(top) << ", " << std::get<1>(top) << std::endl;
        pq.pop();
        if(bstart == true){
            first_start_time = std::get<0>(top);
            prev_end_time = first_start_time + std::get<1>(top);
            bstart = false;
            total = std::get<1>(top);
            continue;
        }

        int start_time = std::get<0>(top);
        int end_time = prev_end_time + std::get<1>(top);
        total += std::get<1>(top) + (prev_end_time - start_time);
        prev_end_time = end_time;
    }

    answer = total/jobs.size();
    //std::cout << answer << std::endl;
    return answer;
}

void tc1(){
    std::vector<std::vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};

    int answer = solution(jobs);
    if(answer == 9){
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