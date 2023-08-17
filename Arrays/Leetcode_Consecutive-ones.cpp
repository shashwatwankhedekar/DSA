//https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count =0;
        int freq = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                count =0;
            }
            freq = max(count,freq);
        }
        return freq;
    }
};