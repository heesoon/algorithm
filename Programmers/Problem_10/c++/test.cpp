#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;

    std::sort(jobs.begin(), jobs.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[0] < b[0];
    });

    auto cmp = [](const std::vector<int> &a, const std::vector<int> &b){
        return a[1] > b[1];
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pq(cmp);

    int i = 0;
    time = jobs[0][0];
    while(!pq.empty() || i < jobs.size()){
        if(i < jobs.size()){
            if(time >= jobs[i][0]){
                pq.push({jobs[i][0], jobs[i][1]});
                i++;
            }
            else{
                if(!pq.empty()){
                    auto top = pq.top();
                    pq.pop();
                    answer += (time - top[0] + top[1]); 
                    time += top[1];
                }
            }
        }
        else{
            if(!pq.empty()){
                auto top = pq.top();
                pq.pop();
                answer += (time - top[0] + top[1]); 
                time += top[1];
            }
        }
    }

    //std::cout << answer/jobs.size() << std::endl;
    return answer/jobs.size();
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