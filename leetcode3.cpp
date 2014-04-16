#include <iostream>

/*
* Definition for a point.
*/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {

        vector<int> cnt;
        for (int i = 0; i < points.size(); i++)
        {
            int counter = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
                    {
                        counter++;
                    }
                    else if ()
                    {

                    }
                }
            }
        }

    }
};