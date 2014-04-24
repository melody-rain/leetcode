#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {

        int cnt = 0;
        int max = 0;
        int index = 0;

        int asciiTable[256];
        for (int i = 0; i < 256; i++)
        {
            asciiTable[i] = -1;
        }

        string::iterator str_it = s.begin();
        while (str_it != s.end())
        {
            char c1 = *str_it;

            if (asciiTable[c1] != -1)
            {
                str_it = s.begin() + asciiTable[c1] + 1;
                index = asciiTable[c1] + 1;
                for (int i = 0; i < 256; i++)
                {
                    asciiTable[i] = -1;
                }
                if (cnt > max)
                {
                    max = cnt;
                }
                cnt = 0;
                continue;
            }
            else
            {
                cnt++;
                asciiTable[c1] = index;
            }
            str_it++;
            index++;
        }

        if (cnt > max)
        {
            max = cnt;
        }

        return max;
    }
};
int main()
{
    string myString("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    Solution mySolution;
    int max = mySolution.lengthOfLongestSubstring(myString);
    printf("%d\n", max);
    return 0;
}
