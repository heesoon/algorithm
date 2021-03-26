#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::vector<int>> G;
std::vector<int> V;

void debug(const std::vector<std::vector<int>>& v)
{
    auto it = v.begin();
    for(; it != v.end(); it++)
    {
        auto jt = (*it).begin();
        for(; jt != (*it).end(); jt++)
        {
            std::cout << *jt << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void solve(int v, int c, int n)
{
    V[v] = c;
    bool can = true;

    for(int i = 0; i < n; i++)
    {
        if(V[i] == c && G[v][i])
        {
            can = false;
        }
    }

    if(can == false)
    {
        V[v] = 0;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(V[i] == 0 && G[v][i])
        {
            solve(i, 1, n);
            solve(i, 2, n);
        }
    }
}

void testCase1()
{
    int N = 3;
    bool isPossible = true;

    std::vector<std::tuple<int,int>> data = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    G.assign(N, std::vector<int>(N, 0));
    V.assign(N, 0);

    std::vector<std::tuple<int,int>>::iterator it = data.begin();
    for(; it != data.end(); it++)
    {
        int a = std::get<0>(*it);
        int b = std::get<1>(*it);

        G[a][b] = G[b][a] = 1;
    }

    solve(0, 1, N);

    for(int i = 0; i < N; i++)
    {
        if(V[i] == 0)
        {
            isPossible = false;
            break;
        }
    }

    if(isPossible == false) std::cout << "IMPOSSIBLE" << std::endl;
    else std::cout << "OK" << std::endl;

    G.clear();
    V.clear();
}

void testCase2()
{
    int N = 9;
    bool isPossible = true;

    std::vector<std::tuple<int,int>> data = {
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5},
        {0, 6},
        {0, 7},
        {0, 8}
    };

    G.assign(N, std::vector<int>(N, 0));
    V.assign(N, 0);

    std::vector<std::tuple<int,int>>::iterator it = data.begin();
    for(; it != data.end(); it++)
    {
        int a = std::get<0>(*it);
        int b = std::get<1>(*it);

        G[a][b] = G[b][a] = 1;
    }

    solve(0, 1, N);

    for(int i = 0; i < N; i++)
    {
        if(V[i] == 0)
        {
            isPossible = false;
            break;
        }
    }

    if(isPossible == false) std::cout << "IMPOSSIBLE" << std::endl;
    else std::cout << "OK" << std::endl;

    G.clear();
    V.clear();
}

int main()
{
    testCase1();
    testCase2();

    return 0;
}