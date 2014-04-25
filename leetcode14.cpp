#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
        {
            return 0;
        }
        int min = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }


            if (prices[i] - min > profit)
            {
                profit = prices[i] - min;
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> oneRow;
    oneRow.push_back(3);
    oneRow.push_back(2);
    oneRow.push_back(6);
    oneRow.push_back(5);
    oneRow.push_back(0);
    oneRow.push_back(3);
    Solution mySolution;
    int output = mySolution.maxProfit(oneRow);
    printf("%d\n", output);
    return 0;
}
