#include <iostream>

class Solution 
{
public:
    int reverse(int x) 
    {
        int a = 0;
        int b = 0;
        while (x != 0)
        {
            a = x % 10;
            
            b = a + b * 10;

            x = x / 10;
        }

        return b;
    }
};

int main()
{
    Solution mySolution;
    int out = mySolution.reverse(-10100);

    printf("%d\n", out);
}