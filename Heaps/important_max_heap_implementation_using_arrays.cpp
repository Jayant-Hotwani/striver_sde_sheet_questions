#include <bits/stdc++.h>
using namespace std;

class maxHeap {
  private:
    // Initialize your data members
    vector<int>heap;

  public:
    void heapify_up(int index){
        int parent_index=(index-1)/2;
        if (heap[parent_index]<heap[index]){
            swap(heap[parent_index],heap[index]);
            heapify_up(parent_index);
        }
        else return;
    }
    void heapify_down(int index){
        int largest=index;
        int left=(2*index)+1;
        int right=(2*index)+2;
        int n=heap.size();
        if (left<n && heap[left]>heap[largest]){
            largest=left;
        }
        if (right<n && heap[right]>heap[largest]){
            largest=right;
        }
        
        if (largest!=index){
            swap(heap[largest],heap[index]);
            heapify_down(largest);
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
        // Remove the top (maximum) element
        int n=heap.size();
        swap(heap[0],heap[n-1]);
        heap.pop_back();
        if (heap.size()>0)
        heapify_down(0);
    }

    int peek() {
        // Return the top element or -1 if empty
        if(heap.size()>0) return heap[0];
        else return -1;
    }

    int size() {
        return heap.size();
        // Return the number of elements in the heap
    }
};

int main(){
    maxHeap h;
    h.push(3);
    h.push(4);
    h.push(1);
    h.push(5);
    h.push(2);
    cout<<h.peek()<<endl;
    h.pop();
    cout<<h.peek()<<endl;
    cout<<h.size()<<endl;
}