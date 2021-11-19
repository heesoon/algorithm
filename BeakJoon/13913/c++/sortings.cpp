#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#if 0
void pair(std::vector<std::pair<int,int>> v){
    std::sort(v.begin(), v.end(), std::less<std::pair<int,int>>());

    for(const auto &p : v){
        std::cout << p.first << " , " << p.second << std::endl;
    }
}

void arr(std::vector<std::vector<int>> v){
    std::sort(v.begin(), v.end());

    for(const auto &p : v){
        std::cout << p[0] << " , " << p[1] << std::endl;
    }
}
#else
void pair(std::vector<std::pair<int,int>> v){
    //auto cmp = [](const std::pair<int,int> &a, const std::pair<int,int> &b){
    //    return a.second > b.second;
    //};
    //std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(cmp)> pq(cmp);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    //std::priority_queue<std::pair<int,int>> pq;

    for(const auto &a : v){
        pq.push(a);
    }

    while(!pq.empty()){
        std::cout << pq.top().first << " , " << pq.top().second << std::endl;
        pq.pop();
    }
}

void arr(std::vector<std::vector<int>> v){
    //auto cmp = [](const std::vector<int> &a, const std::vector<int> &b){
    //    return a[0] > b[0];
    //};
    //std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pq(cmp);
    //std::priority_queue<std::vector<int>> pq;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;

    for(const auto &a : v){
        pq.push(a);
    }

    while(!pq.empty()){
        std::cout << pq.top()[0] << " , " << pq.top()[1] << std::endl;
        pq.pop();
    }
}
#endif


int main(){
    //std::vector<std::pair<int,int>> v1{{4, 5}, {3, 4}, {1, 1}, {2, 3}, {5, 2}};
    //std::vector<std::pair<int,int>> v1{{4, 0}, {3, 0}, {1, 1}, {2, 0}, {5, 2}};
    std::vector<std::pair<int,int>> v1{{0, 4}, {0, 3}, {1, 1}, {0, 2}, {2, 5}};
    pair(v1);

    std::cout << "===================================" << std::endl;

    //std::vector<std::vector<int>> v2{{4, 5}, {3, 4}, {1, 1}, {2, 3}, {5, 2}};
    //std::vector<std::vector<int>> v2{{4, 0}, {3, 0}, {1, 1}, {2, 0}, {5, 2}};
    std::vector<std::vector<int>> v2{{0, 4}, {0, 3}, {1, 1}, {0, 2}, {2, 5}};
    arr(v2);

    return 0;
}