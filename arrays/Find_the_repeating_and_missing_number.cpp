#include <iostream>
#include <vector>
using namespace std;

// Function to find the repeating and missing numbers
// Time Complexity: O(n)
// Space Complexity: O(n)
// in this approach we are using hashing
// we are creating a hash array of size n+1 and storing the frequency of each number
// then we are traversing the hash array to find the repeating and missing numbers
// repeating number will have frequency 2 and missing number will have frequency 0
// we are returning the repeating and missing numbers in a vector

// we can eliminate the space complexity to O(1) by using mathematical approach or by using XOR operation
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n=nums.size();
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }

        int missing=-1,repeating=-1;
        for(int i=1;i<=n;i++){
            if (hash[i]==2){
                repeating=i;
            }
            if (hash[i]==0)
            {
                missing=i;
            }
            if (repeating !=-1 && missing !=-1){
                break;
            }
        }
        return {repeating,missing};
    }


#define ll long long
// mathematical approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// we can use the formula of sum of first n natural numbers and sum of squares of first n natural numbers
// sum of first n natural numbers = n(n+1)/2
// sum of squares of first n natural numbers = n(n+1)(2n+1)/6
// let x be the missing number and y be the repeating number
// we have two equations
// 1. x - y = sum of first n natural numbers - sum of array elements
// 2. x^2 - y^2 = sum of squares of first n natural numbers - sum of squares of array elements
// we can solve these two equations to find the values of x and y   
// x^2 - y^2 = (x - y)(x + y)
// from equation 1 we can find the value of x - y
// we can substitute the value of x - y in equation 2 to find the value of x + y
// now we have two equations with two variables we can solve them to find the values of x and y 
// x = (equation1 + equation2) / 2
// y = (equation2 - equation1) / 2
// we can return the values of x and y in a vector

// we can do by taking xor of all the elements in the array and xoring it with 1 to n
// the result will be x^y where x is the missing number and y is the repeating number
// now we can find the rightmost set bit in the result
// we can divide the elements in the array and 1 to n into two sets based on the rightmost set bit
// now we can take xor of all the elements in both the sets
// the result will be x and y   

    vector<int> findMissingRepeatingNumbers2(vector<int> nums){
        int n=nums.size();
        ll sum=(n*(n+1))/2;
        ll sum_sq=(n*(n+1)*(2*n+1))/6;

        ll curr_sum=0,curr_sum_sq=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            curr_sum_sq+=(nums[i]*nums[i]);
        }
        // x - miss y repeat
        ll y_minus_x=curr_sum-sum;
        ll y_plus_x =(curr_sum_sq-sum_sq)/y_minus_x;
        ll y=(y_minus_x+y_plus_x)/2;
        ll x=y_plus_x-y;
        return {(int)y,(int)x};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 3};
    vector<int> result = sol.findMissingRepeatingNumbers2(nums);
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}