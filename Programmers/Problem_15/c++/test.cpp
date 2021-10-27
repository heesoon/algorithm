#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<std::vector<int>> counter{{1, 0}, {2, 0}, {3, 0}};
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{2, 1, 2, 3, 2, 4, 2, 5};
    std::vector<int> c{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    std::vector<std::vector<int>> answer_sheets;
    //int repeat = (answers.size() > c.size() ? static_cast<int>(log2(static_cast<double>((answers.size() + 1)/c.size()))) : 0);

    //std::cout << answers.size() << ", " << static_cast<int>(log2(static_cast<double>(40/10))) <<std::endl;
    //for(int i = 0; i < repeat; i++){
    //    a.insert(a.end(), a.begin(), a.end());
    //    b.insert(b.end(), b.begin(), b.end());
    //    c.insert(c.end(), c.begin(), c.end());
    //}

    while(a.size() < answers.size()){
        a.insert(a.end(), a.begin(), a.end());
    }
    while(b.size() < answers.size()){
        b.insert(b.end(), b.begin(), b.end());
    }
    while(c.size() < answers.size()){
        c.insert(c.end(), c.begin(), c.end());
    }

    answer_sheets.push_back(a);
    answer_sheets.push_back(b);
    answer_sheets.push_back(c);

    for(int i = 0; i < answers.size(); i++){
        for(int j = 0; j < counter.size(); j++){
            if(answer_sheets[j][i] == answers[i]){
                counter[j][1]++;
            }
        }
    }

    std::sort(counter.begin(), counter.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[1] > b[1]; 
    });

    answer.push_back(counter[0][0]);
    for(int i = 1; i < counter.size(); i++){
        if(counter[0][1] == counter[i][1]){
            answer.push_back(counter[i][0]);
        }
    }

    return answer;
}

void tc1(){
    std::vector<int> answers = {1,2,3,4,5};

    std::vector<int> answer = solution(answers);
    if(answer == std::vector<int>({1})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> answers = {1,3,2,4,2};

    std::vector<int> answer = solution(answers);
    if(answer == std::vector<int>({1,2,3})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    std::vector<int> answers = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    std::vector<int> answer = solution(answers);
    if(answer == std::vector<int>({1})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
	tc2();
    tc3();
    return 0;
}

/*
<<< good code >>>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    return answer;
}
*/