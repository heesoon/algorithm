#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    std::sort(phone_book.begin(), phone_book.end(), [](std::string a, std::string b){
        return a.size() < b.size();
    });

    for(std::vector<std::string>::size_type i = 0; i < phone_book.size() - 1; i++){
        for(std::vector<std::string>::size_type j = i+1; j < phone_book.size(); j++){
            //if(phone_book[i].size() > phone_book[j].size()){
            //    continue;
            //}

            if(phone_book[i] == phone_book[j].substr(0, phone_book[i].size())){
                //std::cout << phone_book[i] << ", " << phone_book[j].substr(0, phone_book[i].size()) << std::endl;
                return false;
            }
        }
    }

    return answer;
}

void tc1(){
    std::vector<std::string> phone_book = {"119", "97674223", "1195524421"};
    if(solution(phone_book) == false){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<std::string> phone_book = {"123","456","789"};
    if(solution(phone_book) == true){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    std::vector<std::string> phone_book = {"12","123","1235","567","88"};
    if(solution(phone_book) == false){
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