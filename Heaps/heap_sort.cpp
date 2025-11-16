// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // Function to sort an array using Heap Sort.
    static void heapify(vector<int>& heap, int n , int index){
        int largest=index;
        int left=(2*index)+1;
        int right=(2*index)+2;
        if(left<n && heap[left]>heap[largest]) largest=left;
        if(right<n && heap[right]>heap[largest]) largest=right;
        
        if (largest!=index){
            swap(heap[largest],heap[index]);
            heapify(heap,n,largest);
            
        }else return;
        
    }
    void heap_sort(vector<int>& heap , int n){
        
        // building heap process 
        // from n/2 to n-1 all are lead nodes 
        // they are already heap in themselves 
        // so no need of heapying them
        for(int i=(n/2)-1;i>=0;i--){
            heapify(heap,n,i);
        }
        
        for(int i=n-1;i>=0;i--){
            swap(heap[0],heap[i]);
            // shrink the heap 
            heapify(heap,i,0);
        }
    }
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        heap_sort(arr,n);
        
    }
};
int main(){
    Solution s;
    vector<int>arr={12,11,13,5,6,7};
    s.heapSort(arr);
    for (int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}