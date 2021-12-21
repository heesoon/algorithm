#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> A;
std::vector<int> DT;
std::vector<int> B;
std::vector<int> C;
std::vector<int> answer;

int solve(int n){
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                B.push_back(A[j]);
                //DT[i] = std::max(DT[i], DT[j]+1);
                if(DT[i] < DT[j]+1){
                    C = B;
                    B.clear();
                    DT[i] = DT[j]+1;
                }
            }
        }
        //ans = std::max(ans, DT[i]);
        if(ans < DT[i]){
            ans = DT[i];
            answer = C;
            //std::copy(B.begin(), B.end(), std::back_inserter(C));
            //C.push_back(A[i]);
            answer.push_back(A[i]);
        }
        B.clear();
    }

    return ans;
}

int main(){
    int N;
    int v;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> v;
        A.emplace_back(v);
    }

    DT.assign(N, 1);
    std::cout << solve(N) << std::endl;
    for(const auto &a : answer){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

/*
8
30 1 9 40 7 5 4 90
*/

#if 0
#include <iostream>
#include <vector>
 
#define endl "\n"
#define MAX 1010
using namespace std;
 
int N;
int Arr[MAX];
int DP[MAX];
vector<int> LIS[MAX];
vector<int> Answer;
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Arr[i];
}
 
void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        LIS[i].push_back(Arr[i]);
        for (int j = 1; j < i; j++)
        {
            if (Arr[i] > Arr[j])
            {
                if (DP[i] < DP[j] + 1)
                {
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(Arr[i]);
                    DP[i] = DP[j] + 1;
                }
            }
        }
        if (Answer.size() < LIS[i].size())
        {
            Answer = LIS[i];
        }
    }
 
    cout << Answer.size() << endl;
    for (int i = 0; i < Answer.size(); i++) cout << Answer[i] << " ";
    cout << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

https://cocoon1787.tistory.com/455

#endif