#include <iostream>

unsigned int sumupOfdivisor(unsigned int n)
{
    unsigned int sum = 0;
    
    // O(n) calculate complexity
    for(unsigned int i = 1; i <= n; i++)
    {
        if( (n % i) == 0 )
        {
            sum += i;
        }
    }
    
    return sum;
}

int main()
{
    unsigned int n;
    std::cout << "insert number : ";
    std::cin >> n;
    std::cout << std::endl;
    
    std::cout << "result : " << sumupOfdivisor(n) << std::endl;
    return 0;
}