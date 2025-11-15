#include <bits/stdc++.h>
using namespace std;

class minHeap {
  private:
    // Initialize your data members
    vector<int>heap;

  public:
  // Constructor
    minHeap() {
        // Write your code here
    }
    // Helper functions to maintain the heap property
    // You can add more helper functions if needed
    //heapify up
    //heapify down
    
    void heapify_up(int index){
        if (index==0) return ;
        int parent_index=(index-1)/2;
        if (heap[parent_index]>heap[index]){
            swap(heap[parent_index],heap[index]);
        }
        heapify_up(parent_index);
        
    }
    
    void heapify_down(int index){
        int n=heap.size();
        int smallest=index;
        int left=(2*index)+1;
        int right=(2*index )+2;
        if (left<n && heap[left]<heap[smallest])smallest=left;
        if (right<n && heap[right]<heap[smallest])smallest=right;
        
        if (smallest!=index){
            swap(heap[index],heap[smallest]);
            heapify_down(smallest);
        }
        else
        return;
        
    }
    

    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        heapify_up(heap.size()-1);
    }

    void pop() {
        // Remove the top (minimum) element
        if (heap.size()>0){
            swap(heap[0],heap[heap.size()-1]);
            heap.pop_back();
            if (heap.size()>0)
            heapify_down(0);
        }
        
    }

    int peek() {
        // Return the top element or -1 if empty
        if(heap.size()==0) return -1;
        else return heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};

int main() {
    minHeap h;
    h.push(3);
    h.push(5);
    cout << h.peek() << "\n"; // prints 3
    h.push(2);
    h.push(1);
    cout << h.peek() << "\n"; // prints 1
    h.pop();
    cout << h.peek() << "\n"; // prints 2
    cout << h.size() << "\n"; // prints 3
}