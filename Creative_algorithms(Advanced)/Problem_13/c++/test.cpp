#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::string solution(int k, const std::vector<std::string> &code, const std::vector<std::string> &character, const std::string &encodeString){
    std::map<std::string, std::string> map;
    std::string answer;
    std::string tstring;

    for(int i = 0; i < k; i++){
        map[code[i]] = character[i];
    }

    for(const auto &c : encodeString){
        tstring += c;

        auto search = map.find(tstring);
        if(search != map.end()){
            answer += search->second;
            tstring.clear();
        }
    }

    return answer;
}

void tc1(){
    int k = 5;
    std::vector<std::string> code{"00", "01", "10", "110", "111"};
    std::vector<std::string> character{"A", "B", "C", "D", "E"};
    std::string encodeString = "00000101111";

    if("AABBE" == solution(k, code, character, encodeString)){
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