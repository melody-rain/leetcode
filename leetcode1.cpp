#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    struct Pos
    {
        int start;
        int end;
    };

    std::vector<Pos> pos_recoder;

    void reverseWords(std::string &s)
    {
        Pos pos;
        int cnt = 0;
        int numLetter = 0;
        for (unsigned int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                cnt++;
                if ((s[i + 1] == ' ') || (i == (s.length() - 1)))
                {
                    pos.end = i;
                    pos.start = i - cnt + 1;
                    pos_recoder.push_back(pos);
                    numLetter += cnt;
                    cnt = 0;
                }
            }
        }

        if (!numLetter)
            s = "";
        else
        {
            int reversedLength = numLetter + pos_recoder.size() - 1;
            char* out_string = new char[reversedLength + 1];
            out_string[reversedLength] = '\0';

            int offset = 0;
            for (int i = (pos_recoder.size() - 1); i >= 0; i--)
            {
                for (int j = pos_recoder[i].start; j <= pos_recoder[i].end; j++)
                {
                    out_string[offset++] = s[j];
                }

                if (i) out_string[offset++] = ' ';
            }

            s = out_string;
        }
    }
};

int main()
{
    Solution mySolution;
    std::string in = "hi!";
    mySolution.reverseWords(in);
    std::cout << in << "\n";
}
