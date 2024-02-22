#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        long long perimeter=0;
        long long remsides_sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<remsides_sum){
                perimeter=remsides_sum+nums[i];
            }
            remsides_sum+=nums[i];
        }
        return perimeter==0? -1:perimeter ;
    }
};