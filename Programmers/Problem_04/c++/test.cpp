#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>

auto cmp = [](const std::tuple<int, int> &a, const std::tuple<int, int> &b){
    return std::get<1>(a) < std::get<1>(b);
};

template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::tuple<int,int> a = q.top();
        std::cout << std::get<0>(a) << ", " << std::get<1>(a) << std::endl;
        q.pop();
    }
    std::cout << '\n';
}

void test_case_1(){
    std::vector<std::string> genres = {"classic", "pop", "classic", "classic", "pop"};
    std::vector<int> plays = {500, 600, 150, 800, 2500};


    std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>, decltype(cmp)> pq(cmp);

    int cnt = 0;
    for(auto ve : plays){
        pq.push({cnt, ve});
        cnt++;
    }

    print_queue(pq);
}

int main(){
    test_case_1();
    return 0;
}