#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vParents;
std::vector<int> vParentSize;
std::map<std::string, int> mStringToIndex;

int doFind(int a){
    if(vParents[a] == a) return a;
    return vParents[a] = doFind(vParents[a]);
}

void doUnion(int a, int b){
    int pa = doFind(a);
    int pb = doFind(b);

    if(pa != pb){
        if(vParentSize[pa] < vParentSize[pb]){
            std::swap(pa, pb);
        }

        vParents[pb] = pa;
        vParentSize[pa] += vParentSize[pb];
        vParentSize[pb] = 0;
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;

    while(T--){
        int F, idx = 1;
        std::cin >> F;

        for(int i = 0; i <= 200'000; i++){
            vParents.push_back(i);
            vParentSize.push_back(1);
        }

        for(int i = 0; i < F; i++){
            std::string str1, str2;
            std::cin >> str1 >> str2;

            if(mStringToIndex.count(str1) == 0){
                mStringToIndex[str1] = idx++;
            }

            if(mStringToIndex.count(str2) == 0){
                mStringToIndex[str2] = idx++;
            }

            doUnion(mStringToIndex[str1], mStringToIndex[str2]);
            auto parentOfBothFriend = doFind(mStringToIndex[str1]);
            std::cout << vParentSize[parentOfBothFriend] << "\n";
        }

        vParents.clear();
        vParentSize.clear();
        mStringToIndex.clear();
    }
    return 0;
}