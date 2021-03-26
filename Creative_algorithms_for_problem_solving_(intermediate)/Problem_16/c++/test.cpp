#include <iostream>
#include <vector>
#include <tuple>

const int N = 12;
const int TC = 2;
std::vector<int> vn = {3, 9};
std::vector<std::vector<int>> G;
std::vector<int> V;
std::vector<std::tuple<int,int>> data[TC] = {
    {
        {0, 1},
        {1, 2},
        {2, 0}
    },
    {
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5},
        {0, 6},
        {0, 7},
        {0, 8}                                                
    },
};

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

int main()
{
    for(int i = 0 ; i < TC; i++)
    {
        G.assign(N, std::vector<int>(N, 0));
        V.assign(N, 0);

        std::vector<std::tuple<int,int>>::iterator it = data[i].begin();
        for(; it != data[i].end(); it++)
        {
            int a = std::get<0>(*it);
            int b = std::get<1>(*it);

            G[a][b] = G[b][a] = 1;
        }

        //debug(G);

        solve(0, 1, vn[i]);

        bool isPossible = true;
        for(int i = 0; i < vn[i]; i++)
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

    return 0;
}