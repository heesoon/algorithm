#include <iostream>
#include <vector>

using namespace std;

void solution(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B) {
    int N = A.size();
    int M = A[0].size();
    int K = B[0].size();
    std::vector<std::vector<int>> out(N, std::vector<int>(K, 0));

    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < K; j++){
            for(size_t t = 0; t < M; t++){
                out[i][j] += (A[i][t] * B[t][j]);
            }
        }
    }

    for(const auto &row : out){
        for(const auto &colum : row){
            std::cout << colum << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int n, m, k;
    std::cin >> n >> m;
    std::vector<std::vector<int>> A(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> A[i][j];
        }
    }

    std::cin >> m >> k;
    std::vector<std::vector<int>> B(m, std::vector<int>(k, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            std::cin >> B[i][j];
        }
    }

    solution(A, B);
    return 0;
}