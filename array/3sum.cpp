#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
   public:
   vector<vector<int>> threeSum(vector<int>& nums, int target){
        vector<vector<int>>result;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i])continue;
            int left=i+1;
            int right= n-1;
            while(left<right){
                int sum= nums[i]+nums[left]+nums[right];
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    //skip duplicate for left
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return result;

   }  
};
int main(){
    Solution s;
    vector<int>nums={-1,0,-1,2,4,-2,3};
    vector<vector<int>>ans=s.threeSum(nums,1);
    for(auto & it: ans){
        for(int num:it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}