/*
********************************** MOST IMPORTANT QUESTION FOR PRODUCT BASED COMPANIES*********************************************************************************
**********************************MOST COMPANY ASK THESE QUESTION*******************************************************************************************************
33. Search in Rotated Sorted Array
Medium

18325

1093

Add to List

Share
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
Accepted
1,791,105
Submissions
4,633,935
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        
        while(start< end){
            int mid = start + (end -start)/2;
            
            if(nums[0] - nums[mid] > 0){
                end = mid;
            }
            else{
                start = mid + 1;
                
            }
        }
        int pivot = start;
        
        start = 0;
        end = pivot - 1;
        
        while(start< end){
            int mid = start + (end -start)/2;
            
            if(nums[mid] >= target){
                end = mid;
            }
            else{
                start = mid + 1;
                
            }
        }
        if(nums[start] == target) return start;
        
        start = pivot;
        end = n - 1;
        
        while(start< end){
            int mid = start + (end -start)/2;
            
            if( nums[mid] >= target){
                end = mid;
            }
            else{
                start = mid + 1;
                
            }
        }
        if(nums[start] == target) return start;
        
        return -1;
    }
    
};
