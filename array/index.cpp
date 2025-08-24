#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <map>
using namespace std;
// to check if a number is prime
bool checkPrime(int n ){
    int count=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count++;
            if(n/i!=i){
                count++;
            }
        }
    }
    return count==2 ;
}
// print all the divisors
vector<int> printDivisors(int n){
    vector<int>ans;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i!=i){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
 // second smallest and largest element in an array

pair<int, int> element(vector<int>& arr) {
    int n = arr.size();
    int small = INT_MAX, smaller = INT_MAX;
    int great = INT_MIN, greater = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Largest and second largest
        if (arr[i] > great) {
            greater = great; // shift old max to second max
            great = arr[i];
        }
        else if (arr[i] > greater && arr[i] != great) {
            greater = arr[i];
        }

        // Smallest and second smallest
        if (arr[i] < small) {
            smaller = small; // shift old min to second min
            small = arr[i];
        }
        else if (arr[i] < smaller && arr[i] != small) {
            smaller = arr[i];
        }
    }
    return {smaller, greater};
}
 // selections sort
void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
                swap(arr[i],arr[mini]);
            }
        }
    }
}

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        int swapped=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0) break;
    }
}
// insertion sort

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int subarrayLen(vector<int>& nums,int target){
    int n= nums.size();
    int maxlen=-1;
    map<int,int>preSum;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==target) maxlen=max(maxlen,i+1);
        int rem= target-sum;
        if(preSum.find(rem)!=preSum.end()){
            int len=i-preSum[rem];
            maxlen=max(len,maxlen);
        }
        if(preSum.find(sum)==preSum.end()){
            preSum[sum]=i;
        }
    }
    return maxlen;

}

int removeDulicates(vector<int>& vec){
    int n= vec.size();
    int i=1;
    for(int j=1;j<n;j++){
        if(vec[j]!=vec[i-1]){
            vec[i]=vec[j];
            i++;
        }
    }
    return i;
}


int main() {
    vector<int> arr = {2, 5, 7, 4};
    vector<int>vec={1,1,1,2,2,2,3,3,4,5,5,5,6,7};
    // second largest and second smallest
    cout << element(arr).first << " " << element(arr).second<<endl;;
    // to check prime 
    cout<<checkPrime(2)<<endl;
    // to print all divisors
    vector<int>ans= printDivisors(12);
    for(int num:ans){
        cout<<num<<" , ";
    }
    cout<<endl;
    // selection sort 
    selectionSort(arr);
    for(int m:arr){
    cout<<m<<" ";
    }
    cout<<endl;
    // bubble sort
    bubbleSort(arr);
    for(int m:arr){
    cout<<m<<" ";
    }
    cout<<endl;
    // insertion sort
    insertionSort(arr);
     for(int m:arr){
    cout<<m<<" ";
    }
    cout<<endl;
    int ind=removeDulicates(vec);
    for(int i=0;i<ind;i++){
        cout<<vec[i]<<" ";
    }

    vector<int>nums={1,0,2,3,0,2,4,5,6};
    cout<<endl<<"maxlen is: "<<subarrayLen(nums,8);
    return 0;
}
