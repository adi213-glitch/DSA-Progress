
#include "VersionNode.hpp" // To know what a VersionNode is

// Use the standard namespace to simplify code (e.g., 'vector' instead of 'std::vector')
using namespace std;

/**
 * @namespace CustomAlgorithms
 * @brief A namespace to hold custom algorithm implementations.
 */
namespace CustomAlgorithms {

    /**
     * @brief The helper function that merges two sorted subarrays back into one.
     * This version uses a temporary vector to store the merged result before
     * copying it back into the original array.
     * @param arr The main vector containing the data.
     * @param left The starting index of the left subarray.
     * @param mid The ending index of the left subarray.
     * @param right The ending index of the right subarray.
     */
    void merge(vector<VersionNode*>& arr, int left, int mid, int right) {
        vector<VersionNode*> temp; // The temporary vector
        int i = left;     // Initial index for the left subarray
        int j = mid + 1;  // Initial index for the right subarray

        // --- Stage 1: Merge into temporary vector ---
        // Compare elements from the left and right subarrays and push the smaller one into temp.
        while (i <= mid && j <= right) {
            // The core comparison: sort by creation timestamp.
            if (arr[i]->created_timestamp < arr[j]->created_timestamp ||
               (arr[i]->created_timestamp == arr[j]->created_timestamp && arr[i]->version_id < arr[j]->version_id)) {
                temp.push_back(arr[i]);
                i++;
                // this handles the case when system runs the code too fast so that 2 files get same timestamp it then sorts them with version id.
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // If there are any remaining elements in the left subarray, add them to temp.
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // If there are any remaining elements in the right subarray, add them to temp.
        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        // --- Stage 2: Copy sorted elements from temp back to the original array ---
        for (int k = 0; k < temp.size(); k++) {
            // Place the sorted elements back into their correct positions in 'arr'.
            // The starting position in 'arr' is 'left'.
            arr[left + k] = temp[k];
        }
    }

    /**
     * @brief The main recursive merge sort function.
     * @param arr The vector to be sorted.
     * @param left The starting index of the segment to sort.
     * @param right The ending index of the segment to sort.
     */
    void mergeSortRecursive(vector<VersionNode*>& arr, int left, int right) {
        // Base case: if the segment has 1 or 0 elements, it is already sorted.
        if (left >= right) {
            return;
        }

        
        int mid = left + (right - left) / 2;

       
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

    
        merge(arr, left, mid, right);
    }

    /**
     * @brief The public-facing function to sort a vector of VersionNode pointers.
     * @param history_vector The vector to sort in-place.
     */
    void sortHistory(vector<VersionNode*>& history_vector) {
        if (history_vector.size() <= 1) {
            return; // Already sorted
        }
        // Kick off the recursive sorting process on the entire vector.
        mergeSortRecursive(history_vector, 0, history_vector.size() - 1);
    }

} // namespace CustomAlgorithms

