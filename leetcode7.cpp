#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<int, int> table;
        map<int, int>::iterator iter;
        vector<int> result;
        int comp;
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            comp = target - numbers[i];
            iter = table.find(comp);
            if (iter == table.end()) {
                table.insert(pair<int, int>(numbers[i], i));
            }
            else {
                result.push_back(iter->second + 1);
                result.push_back(i + 1);
                return result;
            }
        }
        return result;
    }
};

int main()
{
    const int numInput = 8;
    const int target = 8;
    vector<int> input;
    //for (int i = 0; i < numInput; i++)
    {
        //int randNum = rand() % 10;
        //input.push_back(randNum);
        input.push_back(2);
        input.push_back(1);
        input.push_back(9);
        input.push_back(4);
        input.push_back(56);
        input.push_back(4);
        input.push_back(90);
        input.push_back(3);
    }
    Solution mySolution;
    vector<int>index;
    index = mySolution.twoSum(input, target);

    cout << "indexes are: \n";
    for (unsigned int i = 0; i < index.size(); i++)
    {
        cout << index[i] << "\n";
    }
}