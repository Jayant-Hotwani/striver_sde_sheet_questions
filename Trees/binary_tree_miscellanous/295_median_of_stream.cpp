#include <queue>
using namespace std;

class MedianFinder {
public:

    priority_queue<double>max_heap;
    priority_queue<double,vector<double>,greater<double>>min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if (max_heap.size()==0 || num<max_heap.top()){
            max_heap.push(num);
        }
        else
            min_heap.push(num);


        if (max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (max_heap.size()<min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
        double ans=0;
        if(max_heap.size()==min_heap.size()){
            ans=(min_heap.top()+max_heap.top())/2.00;
            return ans;
        }
        else{
            return max_heap.top();
        }
    }
};
