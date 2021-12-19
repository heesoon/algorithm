#include <iostream>
#include <vector>
#include <algorithm>

std::string pattern;
std::string word;
std::vector<std::vector<int>> cache;
const int MAX_LEN = 101;

int solve(int pIdx, int wIdx){
    int &ref = cache[pIdx][wIdx];
    if(ref != -1){
        return ref;
    }

    if(pIdx < pattern.size() && wIdx < word.size() && (pattern[pIdx] == '?' || pattern[pIdx] == word[wIdx])){
        return ref = solve(pIdx+1, wIdx+1);
    }

    if(pIdx == pattern.size()){
        return ref = (wIdx == word.size());
    }

    if(pattern[pIdx] == '*'){
        if(solve(pIdx+1, wIdx)|| (wIdx < word.size() && solve(pIdx, wIdx+1))){
            return ref = 1;
        }
    }

    return ref = 0;
}

void tc1(){
    std::vector<std::string> result;
    pattern = "he?p";
    std::string testString[3] = {"help", "heap", "helpp"};

    for(const auto &str : testString){
        word = str;
        cache.assign(MAX_LEN, std::vector<int>(MAX_LEN, -1));
        if(solve(0, 0)){
            result.push_back(str);
        }
        cache.clear();
    }

    std::sort(result.begin(), result.end());

    //for(const auto &str : result){
    //    std::cout << str << " ";
    //}
    std::cout << std::endl;

    if(std::vector<std::string>{"heap", "help"} == result){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<std::string> result;
    pattern = "*p*";
    std::string testString[3] = {"help", "papa", "hello"};

    for(const auto &str : testString){
        word = str;
        cache.assign(MAX_LEN, std::vector<int>(MAX_LEN, -1));
        if(solve(0, 0)){
            result.push_back(str);
        }
        cache.clear();
    }

    std::sort(result.begin(), result.end());

    //for(const auto &str : result){
    //    std::cout << str << " ";
    //}
    std::cout << std::endl;

    if(std::vector<std::string>{"help", "papa"} == result){
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