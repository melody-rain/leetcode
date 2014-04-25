#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

        for (int j = triangle.size() - 2; j >= 0; j--)
        {
            for (int i = 0; i < triangle[j].size(); i++)
            {
                triangle[j][i] = min(triangle[j + 1][i] + triangle[j][i], triangle[j][i] + triangle[j + 1][i + 1]);
            }
        }
        return triangle[0][0];
    }
};

int main()
{
    vector<int> oneRow;
    vector<vector<int>> allRow;

    oneRow.push_back(2);
    allRow.push_back(oneRow);
    oneRow.clear();

    oneRow.push_back(3);
    oneRow.push_back(4);
    allRow.push_back(oneRow);
    oneRow.clear();

    oneRow.push_back(6);
    oneRow.push_back(5);
    oneRow.push_back(7);
    allRow.push_back(oneRow);
    oneRow.clear();

    oneRow.push_back(4);
    oneRow.push_back(4);
    oneRow.push_back(8);
    oneRow.push_back(3);
    allRow.push_back(oneRow);
    oneRow.clear();

    Solution mySolution;
    int output = mySolution.minimumTotal(allRow);
    printf("%d\n", output);
    return 0;
}
