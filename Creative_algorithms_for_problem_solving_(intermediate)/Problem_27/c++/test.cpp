#include <iostream>
#include <string>

const int N = 8;
int seq[80];
int result = 987654321;

bool isSame(int a, int b){
    int i;
    for( i = a; i < b; i++){
        if(seq[i] != seq[b + i - a]){
            break;
        }
    }

    return (a == b) ? false : i == b;
}

bool isVaildSeq(int n){
    int i, j;
    for(i = n - 1, j = n; i > 0; i -= 2, j--){
        if(isSame(i, j) == true){
            return false;
        }
    }

    return true;
}

void solve(int n){
	if(n == N){
        int value = 0;
		std::string str;
        for(int i = 0; i < N; i++){
            str.push_back(seq[i] + '0');
        }

        value = std::stol(str);

        if(result > value){
            result = value;
        }
		return;
	}

	for(int i = 1; i <= 3; i++){
        seq[n] = i;
        if(isVaildSeq(n) == true){
            solve(n+1);
        }
        seq[n] = 0;
	}
}

int main(){

    solve(1);
    std::cout << result << std::endl;
	return 0;
}




#if 0
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

int x[4] = {2, 1, 2, 3};

bool gs(int s, int e){
    int m = (e - s)/2;
    
    if(e - s == 1){
        if(x[e] == x[s])
            return false;
        else
            return true;
    }
    else{
        bool fgood = false;
        for(int i = 0; i <= m; i++){
            std::cout << "cmp : " << x[s+i] << ", " << x[m+1 +i] << std::endl;
            if(x[s+i] != x[m+1 +i]){
                std::cout << "good : " << x[s+i] << ", " << x[m+1 +i] << std::endl;
                fgood = true;
                break;
            }
        }
        
        if(fgood == false){
            std::cout << "return false ... " << std::endl;
            return false;
        }
        else{
            std::cout << "divide ... " << std::endl;
            return gs(s, m) && gs(m+1, e);
        }
    }
}

int main(){

    std::cout << gs(0, 3) << std::endl;
	return 0;
}
#endif