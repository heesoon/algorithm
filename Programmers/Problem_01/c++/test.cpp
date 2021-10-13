#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    std::unordered_map<std::string, int> map;
    
    for(auto &p : participant){
        map[p] += 1;
    }

    for(auto &p : completion){
        map[p] -= 1;
    }

    for(auto &m : map){
        if(m.second > 0){
            answer = m.first;
        }
    }
    return answer;
}

void tc1(){
    std::vector<std::string> participant = {"leo", "kiki", "eden"};
    std::vector<std::string> completion = {"eden", "kiki"};

    std::string notCompletePerson = solution(participant, completion);
    if(notCompletePerson == "leo"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<std::string> participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
    std::vector<std::string> completion = {"josipa", "filipa", "marina", "nikola"};

    std::string notCompletePerson = solution(participant, completion);
    if(notCompletePerson == "vinko"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    std::vector<std::string> participant = {"mislav", "stanko", "mislav", "ana"};
    std::vector<std::string> completion = {"stanko", "ana", "mislav"};

    std::string notCompletePerson = solution(participant, completion);
    if(notCompletePerson == "mislav"){
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