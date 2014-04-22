#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int index1 = 0, index2 = 0;
        HashTable myHashTable(numbers.size());
        myHashTable.createHashTable(numbers);

        int rest = 0;
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            index1 = i;
            rest = target - numbers[index1];
            if (rest < 0)
                continue;
            if (myHashTable.searchKey(rest, numbers.size(), index1, index2))
            {
                break;
            }
        }

        vector<int>index;
        index.push_back(index1 + 1);
        index.push_back(index2 + 1);
        return index;
    }

private:
    struct HashTable
    {
        int *elem;
        int count;
        int *indexRecoder;

        HashTable(int size)
        {
            count = size;
            elem = new int[count];
            indexRecoder = new int[count];
            for (int i = 0; i < count; i++)
            {
                elem[i] = -32768;
            }
        }

        ~HashTable()
        {
            delete[] elem;
        }

        void createHashTable(vector<int> &numbers)
        {
            for (unsigned int i = 0; i < numbers.size(); i++)
            {
                int addr = numbers[i] % numbers.size();

                while (elem[addr] != -32768)
                {
                    addr = (addr + 1) % numbers.size();
                }

                elem[addr] = numbers[i];
                indexRecoder[addr] = i;
            }
        }

        bool searchKey(int key, int width, int index1, int& index2)
        {
            int addr = key % width;

            while (1)
            {
                while (elem[addr] != key)
                {
                    addr = (addr + 1) % width;
                    if (elem[addr] == -32768 || addr == (key % width))
                        return false;
                }

                index2 = indexRecoder[addr];

                if (index1 < index2)
                    return true;
                else
                {
                    addr = (addr + 1) % width;
                }
            }
        }
    };
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
        input.push_back(4);
        input.push_back(56);
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