#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();

        // for each element lets find greatest on left and right
        vector<int>gol(n,-1),gor(n,-1);
        gol[0]=height[0];
        for(int i=1;i<n;i++){
            gol[i]=max(height[i],gol[i-1]);
        }
        gor[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            gor[i]=max(height[i],gor[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(gol[i]!=-1 && gor[i]!=-1){
                int min_wall=min(gol[i],gor[i]);
                int space_left=min_wall-height[i];
                ans+=space_left;
            }
        }
        return ans;



        // most optimal sol without extra spce;

        int left=0,right=n-1;
        int ans=0;
        int left_max=0;
        int right_max=0;
        while(left<=right){
            if (height[left]<=height[right]){
                if (height[left]>=left_max){
                    left_max=height[left];
                }
                else{
                    ans+=(left_max-height[left]);
                }
                left++;
            }
            else{
                if (height[right]>=right_max){
                    right_max=height[right];
                }else{
                    ans+=(right_max-height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trappedWater = solution.trap(height);
    cout << "Trapped Rain Water: " << trappedWater << endl; // Output: 6
    return 0;
}