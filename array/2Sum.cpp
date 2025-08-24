#include<iostream>
#include<vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
    // time complexity O(n) and space complexity O(n) because of map
    pair<int, int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int num= nums[i];
            int rest= target-num;
            if(mpp.find(rest)!=mpp.end()){
                return {mpp[rest],i};
            }
            mpp[num]=i;
        }
        return {-1,-1};
    }
    // with O(nlogn) time complexity and O(1) space complexity
    pair<int,int> twoSumJi(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        while(left<right){
            int sum= nums[left]+nums[right];
            if(sum==target) return {nums[left],nums[right]};
            else if(sum>target) right--;
            else left++;
        }
        return {-1,-1};
    }

};
int main(){
    Solution s;
    vector<int>nums={1,2,3,5,9};
   pair<int,int>ans= s.twoSum(nums,7);
   cout<<ans.first<<" and element is: "<<nums[ans.first]<<" , "<<ans.second<<" and element is: "<<nums[ans.second]<<endl;
  pair<int,int>result= s.twoSumJi(nums,7);
  cout<<result.first<<" "<<result.second<<endl;
   return 0;

}