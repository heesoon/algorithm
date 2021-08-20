#include <iostream>

const int N = 8;
int seq[80];

void solve(int n){
	if(n == N){
		dd
		return;
	}

	for(int i = 1; i <= 3; i++){
		solve(n+1);
	}
}

int main(){
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