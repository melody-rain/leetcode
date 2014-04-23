#include <iostream>

class Solution {
public:
    int atoi1(const char *str)
    {
        const int MAX = (int)pow(2, sizeof(int)* 8 - 1) - 1;
        const int MIN = -(int)pow(2, sizeof(int)* 8 - 1);

        const char *temp = str;
        char c;
        char c2;
        double b = 0;

        bool isNegtive = true;

        while (*temp != '\0')
        {
            c = *temp;
            c2 = *(temp + 1);
            if (c == '-' && c2 >= 48 && c2 <= 57)
            {
                temp++;

                while (*temp != '\0')
                {
                    c = *temp;

                    if (c >= 48 && c <= 57)
                    {
                        c = c - 48;
                        b = c + b * 10;
                        if (*(temp + 1) > 57 || *(temp + 1) < 48)
                        {
                            break;
                        }
                    }
                    temp++;
                }

                if (b < -MIN)
                {
                    b = -MIN;
                }
                return (int)(-b);
            }
            else if (c == '-' && (c2 < 48 || c2 > 57))
            {
                return 0;
            }
            else
            {
                isNegtive = false;
            }

            if (!isNegtive && c >= 48 && c <= 57)
            {
                while (*temp != '\0')
                {
                    c = *temp;

                    if (c >= 48 && c <= 57)
                    {
                        c = c - 48;
                        b = c + b * 10;
                        temp++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (b > MAX)
                {
                    b = MAX;
                }
                return (int)b;
            }

            temp++;
        }

        return 0;
    }

    int atoi(const char *str)
    {
        const int MAX = (int)pow(2, sizeof(int)* 8 - 1) - 1;
        const int MIN = -(int)pow(2, sizeof(int)* 8 - 1);

        const char *temp = str;
        char c;
        char c2;
        double b = 0;

        bool isNegtive = true;
        bool found = false;
        const char *index = str;

        while (*temp != '\0')
        {
            if (*temp != ' ')
            {
                break;
            }
            temp++;
        }

        if (*temp != '\0')
        {
            c = *temp;
            c2 = *(temp + 1);

            if (c != '+' && c != '-' && (c > 57 || c < 48))
            {
                return 0;
            }

            if ((c == '+' || c == '-') && (c2 > 57 || c2 < 4))
            {
                return 0;
            }

            if (c == '-' && c2 >= 48 && c2 <= 57)
            {
                isNegtive = true;
                index = temp + 1;
                found = true;
            }
            else if (c == '+' && c2 >= 48 && c2 <= 57)
            {
                isNegtive = false;
                index = temp + 1;
                found = true;
            }
            else if (c <= 57 && c >= 48)
            {
                isNegtive = false;
                index = temp;
                found = true;
            }
        }

        if (found)
        {
            while (*index != '\0')
            {
                c = *index;
                c = c - 48;
                b = c + b * 10;
                if (*(index + 1) > 57 || *(index + 1) < 48)
                {
                    break;
                }
                index++;
            }


            if (isNegtive)
            {
                if (b < -MIN)
                {
                    b = -MIN;
                }
                return (int)(-b);
            }
            else
            {
                if (b > MAX)
                {
                    b = MAX;
                }
                return (int)b;
            }

        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    char *str = new char[9];
    str[0] = ' ';
    str[1] = ' ';
    str[2] = ' ';
    str[3] = ' ';
    str[4] = '+';
    str[5] = '3';
    str[6] = '2';
    str[7] = '1';
    str[8] = '\0';
//     char *str = new char[1];
//     str[0] = '\0';
    Solution mySolution;
    int out = mySolution.atoi(str);

    printf("%d\n", out);
}