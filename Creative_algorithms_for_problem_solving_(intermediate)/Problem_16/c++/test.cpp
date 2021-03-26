#include <iostream>
#include <vector>
#include <tuple>

int G[200][200];
int visited[200];
const int TC = 2;
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

int main()
{
    for(int i = 0 ; i < TC; i++)
    {       
        std::vector<std::tuple<int,int>>::iterator it = data[i].begin();
        for(; it != data[i].end(); it++)
        {
            int a = std::get<0>(*it);
            int b = std::get<1>(*it);

        }

    }

    return 0;
}