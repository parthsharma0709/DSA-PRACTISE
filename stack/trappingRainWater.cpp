#include<iostream>
#include <vector>
using namespace std;
class Solution {
    public:
     
    vector<int> leftMax(vector<int>& nums){
        int n= nums.size();
        vector<int>ans(n,-1);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            ans[i]= max(nums[i],ans[i-1]);
        }
        return ans;
    }

      vector<int> rightMax(vector<int>& nums){
        int n= nums.size();
        vector<int>ans(n,-1);
        ans[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]= max(nums[i],ans[i+1]);
        }
        return ans;
    }
    int trappingRainWater(vector<int>& nums){
        vector<int> prefixMax= leftMax(nums);
         vector<int> suffixMax= rightMax(nums);
         int total=0;
         for(int i=0;i<nums.size();i++){
            if(nums[i]<prefixMax[i] && nums[i]<suffixMax[i]){
                total+= (min(prefixMax[i],suffixMax[i])-nums[i]);
            }
         }
         return total;
    }
    

    int optimizedTrappingRainWater(vector<int>nums){
        int left=0, right= nums.size()-1,leftMax=0, rightMax=0,total=0;
        while(left<=right){
            if(nums[left]<=nums[right]){
                if(nums[left]>=leftMax){
                    leftMax=nums[left];
                }
                else{
                    total+= leftMax-nums[left];
                }
                left++;
            }
            else{
                if(nums[right]>=rightMax){
                    rightMax=nums[right];
                }
                else{
                    total+= rightMax-nums[right];
                }
                right--;
            }
        }
        return total;

    }
};

int main(){
    Solution s;
    vector<int>nums={0,1,0,2,1,0,1,3,2,1,2,1};
   int ans= s.optimizedTrappingRainWater(nums);
   cout<<ans;
   return 0;


}