#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int* myStack = new int[tokens.size()];
        int myStackIndex = 0;

        for (unsigned int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].compare("+") && tokens[i].compare("-") && tokens[i].compare("*") && tokens[i].compare("/"))
            {
                myStack[myStackIndex] = atoi(tokens[i].c_str());
                myStackIndex++;
            }
            else
            {
                int a1 = myStack[myStackIndex - 1];
                int a2 = myStack[myStackIndex - 2];
                if (!tokens[i].compare("+"))
                {
                    myStack[myStackIndex - 2] = a1 + a2;
                }
                else if (!tokens[i].compare("-"))
                {
                    myStack[myStackIndex - 2] = a2 - a1;
                }
                else if (!tokens[i].compare("/"))
                {
                    myStack[myStackIndex - 2] = a2 / a1;
                }
                else if (!tokens[i].compare("*"))
                {
                    myStack[myStackIndex - 2] = a2 * a1;
                }

                myStackIndex -= 1;
            }
        }

        return myStack[0];
    }
};

int main()
{
    Solution mySolution;
    std::vector<string> in;
    in.push_back(string("4"));
    in.push_back(string("13"));
    in.push_back(string("5"));
    in.push_back(string("/"));
    in.push_back(string("+"));
    std::cout << mySolution.evalRPN(in) << "\n";
}
