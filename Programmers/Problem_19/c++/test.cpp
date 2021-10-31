#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int cnt_left = 0;
    int cnt_right = 0;
    std::string init(name.size(), 'A');
    std::string str_left(name.size(), 'A');
    std::string str_right(name.size(), 'A');

    for(int i = 0; i < name.size(); i++){
        // go right
        cnt_right += (name[i] - 'A' > 'Z' - name[i] + 1 ? 'Z' - name[i] + 1 : name[i] - 'A');
        //std::cout << "in : " << name[i] << ", " << name[i] - 'A' << ", " << 'Z' - name[i] + 1 << std::endl;
        std::cout << "in : " << name[i] << ", " << int(name[i]) << " : " << name[i] - 'A' << ", " << 'Z' - name[i] + 1 << std::endl;
        str_right[i] = name[i];

        // go left
        cnt_left += (name[name.size() - 1 - i] - 'A' > 'Z' - name[name.size() - 1 - i] + 1 ? 'Z' - name[name.size() - 1 - i] + 1 : name[name.size() - 1 - i] - 'A');
        str_left[name.size() - 1 - i] = name[name.size() - 1 - i];
    }

    cnt_right += (name.size() - 1);
    cnt_left += (name.size());
    std::cout << cnt_left << ", " << cnt_right << std::endl;
    if(init == str_left){
        answer = 0;
    }
    else{
        answer = cnt_right >= cnt_left ? cnt_left : cnt_right;
    }

    std::cout << "answer : " << answer << std::endl;
    return answer;
}

void tc1(){
	std::string name = "JEROEN";

    int answer = solution(name);
    if(answer == 56){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::string name = "JAN";

    int answer = solution(name);
    if(answer == 23){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
	tc2();
    return 0;
}