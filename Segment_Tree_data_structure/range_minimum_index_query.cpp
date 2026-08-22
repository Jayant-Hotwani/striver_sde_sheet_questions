#include <iostream>
#include <vector>
#include <climits>

class RangeMaxIndexQuery {
private:
    std::vector<int> arr;
    std::vector<int> tree;
    int n;

    // Helper to build the segment tree
    void buildTree(int node, int start, int end) {
        if (start == end) {
            // Leaf node stores the index itself
            tree[node] = start;
            return;
        }
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        buildTree(leftChild, start, mid);
        buildTree(rightChild, mid + 1, end);

        // Merge step: Store the index containing the larger value
        if (arr[tree[leftChild]] >= arr[tree[rightChild]]) {
            tree[node] = tree[leftChild];
        } else {
            tree[node] = tree[rightChild];
        }
    }

    int queryUtil(int node, int start, int end, int L, int R) {
        // Out of range
        if (start > R || end < L) {
            return -1; 
        }
        // Completely inside range
        if (start >= L && end <= R) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftIdx = queryUtil(2 * node + 1, start, mid, L, R);
        int rightIdx = queryUtil(2 * node + 2, mid + 1, end, L, R);

        // Handle edge cases where one side is completely out of range
        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;

        // Compare values at the returned indices
        return (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

    void updateUtil(int node, int start, int end, int index) {
        if (start == end) {
            return; // Leaf node index mapping stays the same
        }
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (index <= mid) {
            updateUtil(leftChild, start, mid, index);
        } else {
            updateUtil(rightChild, mid + 1, end, index);
        }

        // Re-evaluate parent node after child update
        if (arr[tree[leftChild]] >= arr[tree[rightChild]]) {
            tree[node] = tree[leftChild];
        } else {
            tree[node] = tree[rightChild];
        }
    }

public:
    RangeMaxIndexQuery(const std::vector<int>& input) {
        arr = input;
        n = input.size();
        // Segment tree size upper bound is 4 * n
        tree.resize(4 * n);
        if (n > 0) {
            buildTree(0, 0, n - 1);
        }
    }

    // Query function to get the index of the maximum element in range [L, R]
    int query(int L, int R) {
        if (L < 0 || R >= n || L > R) return -1;
        return queryUtil(0, 0, n - 1, L, R);
    }

    // Update function to change value at a specific index
    void update(int index, int newValue) {
        if (index < 0 || index >= n) return;
        arr[index] = newValue;
        updateUtil(0, 0, n - 1, index);
    }
};

int main() {
    std::vector<int> data = {1, 3, 8, 2, 9, 4, 9};
    RangeMaxIndexQuery rmiq(data);

    // Query maximum index in range [0, 3] -> elements are {1, 3, 8, 2}. Max is 8 at index 2.
    std::cout << "Max index in range: " << rmiq.query(0, 3) << std::endl;

    // Query maximum index in range [1, 5] -> elements are {3, 8, 2, 9, 4}. Max is 9 at index 4.
    std::cout << "Max index in range: " << rmiq.query(1, 5) << std::endl;

     
    rmiq.update(2, 15);

    
    std::cout << "After update, max index in range: " << rmiq.query(0, 3) << std::endl;

    return 0;
}
