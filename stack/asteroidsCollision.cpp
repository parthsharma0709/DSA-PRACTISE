#include<iostream>
#include <vector>
#include <list>
using namespace std;
class solution{
    public:
    vector<int> helper( vector<int>& nums){
        list<int>st;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                st.push_back(nums[i]);
            }
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(nums[i])){
                    st.pop_back();
                }
                if(!st.empty() && st.back()==abs(nums[i])){
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0){
                    st.push_back(nums[i]);
                }
            }
        }
        return vector<int>(st.begin(),st.end());
    }
};

int main(){
    solution s;
    vector<int>nums={4,7,1,1,2,-3,-7,17,15,-18,-19};
    vector<int>ans=s.helper(nums);
    for(int num:ans){
        cout<<num<<" ";
    }
    return 0;
}
