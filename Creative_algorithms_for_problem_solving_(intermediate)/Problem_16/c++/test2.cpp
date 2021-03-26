#include <iostream>
#include <vector>
#include <tuple>

std::vector<int> G[100];
std::vector<int> Visited;

void debug(const std::vector<int> a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        std::vector<int>::const_iterator it = a[i].begin();
        for(; it != a[i].end(); it++)
        {
            std::cout << i << " -> " << *it << " ";
        }
        std::cout << std::endl;
    }
}

void solve(int vIdx, int color)
{
    Visited[vIdx] = color;
    bool isCan = true;

    for(std::vector<int>::size_type i = 0; i < G[vIdx].size(); i++)
    {
        int nIdx = G[vIdx][i];
        if(Visited[nIdx] == color)
        {
            isCan = false;
            break;
        }
    }

    if(isCan == false)
    {
        Visited[vIdx] = 0;
        return;
    }

    for(std::vector<int>::size_type i = 0; i < G[vIdx].size(); i++)
    {
        int nIdx = G[vIdx][i];
        if(Visited[nIdx] == 0)
        {
            solve(nIdx, 1);
            solve(nIdx, 2);
        }
    }
}

void testCase1()
{
    const int N = 3;
    bool isCan = true;
    
    std::vector<std::tuple<int,int>> data = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    Visited.assign(N, 0);
    std::vector<std::tuple<int,int>>::iterator it = data.begin();
    for(; it != data.end(); it++)
    {
        int a = std::get<0>(*it);
        int b = std::get<1>(*it);

        G[a].push_back(b);
    }

    //debug(G, N);

    solve(0, 1);

    for(int i = 0; i < N; i++)
    {
        if(Visited[i] == 0)
        {
            isCan = false;
            break;
        }
    }

    if(isCan == false)
        std::cout << "IMPOSSIBLE" << std::endl;
    else
        std::cout << "OK" << std::endl;
    
    Visited.clear();    
    for(int i = 0; i < N; i++)
    {
        G[i].clear();
    }
}

void testCase2()
{
    const int N = 9;
    bool isCan = true;
    
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

    Visited.assign(N, 0);
    std::vector<std::tuple<int,int>>::iterator it = data.begin();
    for(; it != data.end(); it++)
    {
        int a = std::get<0>(*it);
        int b = std::get<1>(*it);

        G[a].push_back(b);
    }

    //debug(G, N);

    solve(0, 1);

    for(int i = 0; i < N; i++)
    {
        if(Visited[i] == 0)
        {
            isCan = false;
            break;
        }
    }

    if(isCan == false)
        std::cout << "IMPOSSIBLE" << std::endl;
    else
        std::cout << "OK" << std::endl;
    
    Visited.clear();    
    for(int i = 0; i < N; i++)
    {
        G[i].clear();
    }
}

int main()
{
    testCase1();
    testCase2();

    return 0;
}