/*34. Find First and Last Position of Element in Sorted Array
Medium

14505

354

Add to List

Share
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n==0)return {-1,-1};
        //First Binary search to find first true for the condition nums[m] >= target
        int l = 0, h = n-1;
        while(l<h){
            int m = l + (h-l)/2;
            
            if(nums[m]>=target){
                h = m;
            }
            else{
                l  = m+1;
            }
            
        }
        
        if(nums[l]!=target) return {-1,-1};//To check either target is present or not
        
        int startIndex = l ;
        
        //Second binary search to find last false for the condition nums[m]>target
        
        l = 0;
        h = n-1;
        
        while(l<h){
            
            int m = l + (h-l+1)/2;
            
            if(nums[m]>target){
                h = m-1;
            }
            else{
                l = m;
            }
            
        }
        
        int endIndex = l;
        
        return {startIndex,endIndex};
        
        
    }
};
