#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    size_t i = 1;

    for(; i < triangle.size(); i++){
        for(size_t j = 0; j < triangle[i].size(); j++){
            if(j == 0){
                triangle[i][j] += triangle[i-1][j];
            }
            else if(j == triangle[i].size() - 1){
                int prevLast = triangle[i-1].size() - 1;
                triangle[i][j] += triangle[i-1][prevLast];
            }
            else{
                triangle[i][j] += std::max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }

    answer = *std::max_element(triangle[i-1].begin(), triangle[i-1].end());

    return answer;
}

void tc1(){
	std::vector<std::vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

    int answer = solution(triangle);
    if(answer == 30){
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