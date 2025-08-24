#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
    public:
    vector<int>helper(vector<int> & nums ){
            stack<int>st;
            vector<int>ans(nums.size(), -1);
            for(int i=0;i<nums.size();i++){
                while(!st.empty() && st.top()>=nums[i]){
                    st.pop();
                }

                ans[i]=st.empty() ? -1: st.top();

                st.push(nums[i]);


            }
            return ans;
        } 
    
};

int main(){
    Solution s;
  
    vector<int>nums={1,3,4,2};
  vector<int> result=  s.helper(nums);
  for(int num:result){
    cout<<num<<" ";
  }
  return 0;

}