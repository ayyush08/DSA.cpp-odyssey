// Count Collisions

// Given a road having n cars arranged from left to right at unique positions. Each car has a predefined movement direction or remains stationary, represented by a string directions of length n. In the string, 'L' denotes a car moving left, 'R' denotes a car moving right, and 'S' denotes a stationary car. All moving cars travel at the same speed. When two cars moving in opposite directions collide, the collision count increases by 2, and when a moving car collides with a stationary car, the collision count increases by 1. After any collision, the cars involved stop and remain stationary at the point of collision.

// Your task is to calculate the total number of collisions that occur on the road.

// Examples:
// Input: directions = "RLLRS"

// Output: 4

// Explanation:

// Car 1 ('R') collides with Car 2 ('L'), Total Collisons: 0+2=2

// Car 2, now stationary, collides with Car 3 ('L'), Total Collisons: 2+1=3

// Car 4 ('R') collides with Car 5 ('S'), Total Collisons: 3+1=4.

// Input: directions = "SSRRLL"

// Output: 4

// Explanation:

// Car 4 ('R') collides with Car 5 ('L'),Total Collisons: 0+2=2.

// Car 5 ('L') collides with Car 5 after it becomes stationary,Total Collisons: 2+1=3.

// Car 3 ('L') collides with Car 4 after it becomes stationary,Total Collisons: 3+1=4.

// Constraints:
// 1 <= directions.length <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCollisions(string dir)
    {
        bool collided = false;//trace if any collision has happened in the past
        stack<char> st;
        int cnt = 0;
        for (char c : dir)
        {
            if (c == 'R')
                st.push(c);
            else if (c == 'L')
            {
                if (!st.empty())
                {
                    cnt += 2;
                    st.pop();
                    cnt += st.size();
                    st = stack<char>();
                    collided = true;
                }
                else if (collided)
                    cnt += 1;
                // collided=true;
            }
            else
            {
                cnt += st.size();
                st = stack<char>();
                collided = true;
            }
        }
        return cnt;
    }
};
