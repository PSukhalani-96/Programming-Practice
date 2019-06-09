class Solution {
public:
    
    int separate_positive_and_negatives(vector<int>& nums) {
        
        int j=0;
        for ( int i=0; i<nums.size(); i++) {
            if ( nums[i] <= 0) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                j++;
            }
        }
        return j;
    }
        
    int firstMissingPositive(vector<int>& nums) {
     
        int index = separate_positive_and_negatives(nums);
        int size = nums.size() - index;
        
        for ( int i=0; i<size; i++)
           nums[i] = nums[i+index];
        
        for ( int i=0; i<size; i++) {
            if ( abs(nums[i])-1 < size && nums[abs(nums[i])-1] > 0 )
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        
        for ( int i=0; i<size; i++) {
            if ( nums[i] > 0 )
                return i+1;
        }
        return size + 1;
    }
};
