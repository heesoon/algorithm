#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    return answer;
}

void tc1(){
    std::vector<int> prices = {7,4,5,6};

    std::vector<int> answer = solution(prices);
    if(answer == std::vector<int>({4, 3, 1, 1, 0})){
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