/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/

/* ++=======Solution=======
    Not found: true
    Found more than one: false
    Found one:
    If at 0 or n - 2, can easily change first or last num, true
    Otherwise check if removing nums[k] or nums[k+1] make it non-decreasing. If can, then change nums[k] or nums[k+1] can     make nums non-decreasing
 */
    
class Solution {
public:
    
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
       
        if(size <= 2){ 
            return true;
        }
        
        int k=-1;
        for(int i=0;i<size-1;i++)
        {
                if(nums[i]>nums[i+1])
                {
                    if(k>=0){
                        return false;
                    }
                    k=i;
                }
                
        }
        
        if( (k == -1)||(k == 0)||(k == size -2) ){
            return true;
        }else{
            return nums[k-1] <= nums[k+1] || nums[k]<=nums[k+2];
        }
        
    }
};
