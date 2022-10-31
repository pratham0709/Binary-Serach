/* 69. Sqrt(x)
Easy

5122

3638

Add to List

Share
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
Accepted
1,252,759
Submissions
3,382,412
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int l = 1;
        int h = x;
        
        while(l<h){
            long long int m = l +(h - l + 1)/ 2;
            
            if(m * m > x){
                h = m - 1;
            }
            else{
                l = m;
            }
        }
        return l;
    }
};
