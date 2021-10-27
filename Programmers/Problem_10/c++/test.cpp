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
        if(i < jobs.size() && time >= jobs[i][0]){
            pq.push({jobs[i][0], jobs[i][1]});
            i++;
            continue;
        }

        if(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            answer += (time - top[0]) + top[1];
            time += top[1];
        }
        else{
            time = jobs[i][0];
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

/*
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0; // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if(i == jobs.size()-1) start++;
        }
    }

    answer = time / size;
    return answer;
}
*/