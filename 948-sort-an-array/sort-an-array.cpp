class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
    
private:
    void heapSort(vector<int>& nums) {
        int n = nums.size();
        
        // Build the heap
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(nums, n, i);
        }
        
        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; --i) {
            // Move current root to end
            std::swap(nums[0], nums[i]);
            
            // Call heapify on the reduced heap
            heapify(nums, i, 0);
        }
    }
    
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        // If left child is larger than root
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        
        // If right child is larger than largest so far
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        
        // If largest is not root
        if (largest != i) {
            std::swap(nums[i], nums[largest]);
            
            // Recursively heapify the affected sub-tree
            heapify(nums, n, largest);
        }
    }
};
