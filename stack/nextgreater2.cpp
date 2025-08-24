#include<iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
    public:
    vector<int>helper(vector<int>& nums){
        stack<int>st;
         int n= nums.size();
        vector<int>ans(n,-1);
       // i will double the array hypothetically like not in real life but just for solving the problem 

        for(int i=2*n-1;i>=0;i--){
            while (!st.empty() && st.top()<=nums[i%n])
            {
               st.pop();
            }
// fill the array only for real index not for virtual like just for i<n
            if(i<n){
                ans[i]= st.empty() ? -1: st.top();
            }

            st.push(nums[i%n]);
        }
         return ans;
    }
};

int main(){
    Solution s;

    vector<int>nums={3,5,1,6,23,4,21};
    vector<int> ans= s.helper(nums);
    for(int num: ans){
        cout<<num<<" ";
    }
    return 0;


}

// tc O(4n), sc O(2n) in the stack +O(n) for answer array