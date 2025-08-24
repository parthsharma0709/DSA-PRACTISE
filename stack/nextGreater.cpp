#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
    public:
    vector<int>helper(vector<int> & nums2,vector<int>& nums1 ){
        stack<int>st;
        int n = nums2.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                 ans.push_back(-1);
                 mpp[nums2[i]]=-1;
            }
            else{
                 ans.push_back(st.top());
                 mpp[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        ans.clear();
        // only push those keys which are present in nums1
        for(int num: nums1){
            ans.push_back(mpp[num]);
        }
        return ans;
        
    }
};

int main(){
    Solution s;
    vector<int>nums1={4,1,2};
    vector<int>nums2={1,3,4,2};
  vector<int> result=  s.helper(nums2,nums1);
  for(int num:result){
    cout<<num<<" ";
  }
  return 0;

}