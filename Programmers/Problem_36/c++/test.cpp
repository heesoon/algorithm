#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    return answer;
}
void tc1(){
	std::vector<int> = arrows = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};
	int n = 2;

    int answer = solution(arrows);
    if(answer == 3){
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