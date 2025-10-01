#pragma once
// Project Headers
#include "File.hpp"         // Required for the definition of File used in comparators.
#include "MyHashMap.hpp"    // Required for the MyHashMap member (index_map).

// Standard Library Headers
#include <vector>


using namespace std;

// --- Comparators ---
// We define policy structs to tell the heap HOW to compare File pointers.

struct CompareByTimestamp {
    bool operator()(const File* a, const File* b) const {
        return a->last_modification_time < b->last_modification_time;
    }
};

struct CompareByVersions {
    bool operator()(const File* a, const File* b) const {
        return a->total_versions < b->total_versions;
    }
};


// --- Generic Max-Heap Implementation ---
template <typename T, typename Comparator, typename Hasher>
class MyMaxHeap {
private:
    vector<T> heap_data;
    Comparator comparator; // An instance of the comparison policy
     // A reference to the external map that tracks indices.
    MyHashMap<T, int, Hasher> &index_map; // Note: This assumes T is hashable. A real implementation would need a separate key. For File*, we can use filename.
    /**
     * @brief Bubbles an element up the heap to maintain the heap property.
     * @param index The index of the element to bubble up.
     */
    void swap_and_update(int idx1, int idx2) {
        swap(heap_data[idx1], heap_data[idx2]);
        index_map.insert(heap_data[idx1], idx1);
        index_map.insert(heap_data[idx2], idx2);
    }
    void heapifyUp(int index) {
        // Stop if we are at the root
        if (index == 0) return;

        int parent_index = (index - 1) / 2;

        // If the child is greater than the parent (using the comparator), swap them.
        if (comparator(heap_data[parent_index], heap_data[index])) {
            swap_and_update(parent_index, index);
            // Recursively continue bubbling up from the parent's new position.
            heapifyUp(parent_index);
        }
    }

    /**
     * @brief Bubbles an element down the heap to maintain the heap property.
     * @param index The index of the element to bubble down.
     */
    void heapifyDown(int index) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest = index; // Assume the current node is the largest

        // Check if left child exists and is larger than the current largest
        if (left_child_index < size() && comparator(heap_data[largest], heap_data[left_child_index])) {
            largest = left_child_index;
        }

        // Check if right child exists and is larger than the current largest
        if (right_child_index < size() && comparator(heap_data[largest], heap_data[right_child_index])) {
            largest = right_child_index;
        }

        // If the largest element is not the current node, swap them
        if (largest != index) {
            swap_and_update(index, largest);;
            // Recursively continue bubbling down from the new position
            heapifyDown(largest);
        }
    }
    

public:
    // The constructor now requires a reference to the index map.
    MyMaxHeap(MyHashMap<T, int, Hasher>& map_ref) :index_map(map_ref) {
    }

    /**
     * @brief Inserts a new element into the heap.
     */
    void insert(const T& value) {
        // 1. Add the new element to the end of the vector.
        heap_data.push_back(value);
        // 2. add to map and Bubble it up to its correct position.
        int new_index = heap_data.size() - 1;
        index_map.insert(value, new_index);
        heapifyUp(new_index);
    }

    /**
     * @brief Removes and returns the maximum element from the heap.
     */
    bool pop(T &max_value) {
        if (isEmpty()) {
            return false;
        }
        // 1. The max element is always at the root.
        max_value = heap_data[0];
        index_map.remove(max_value); // Remove from index map
      

        // 2. move last element to root and Bubble the new root down to restore the heap property.
        if (size() > 1) {
            heap_data[0] = heap_data.back();
            index_map.insert(heap_data[0], 0); // Update index of moved element
            heap_data.pop_back();
            heapifyDown(0);
        } else {
            heap_data.pop_back();
        }
        return true;
    }

    /**
     * @brief Returns the maximum element without removing it.
     */
    bool top(T &max_value) const {
        if (isEmpty()) {
            return false;
        }
        max_value=heap_data[0];
        return true;
    }
    // The new, efficient update function.
    void updateheap(int index) {
        // After an element's value changes, it might need to move up or down.
        // We can call both; only one will have an effect.
        heapifyUp(index);
        heapifyDown(index);
    }
    
    bool isEmpty() const {
        return heap_data.empty();
    }

    size_t size() const {
        return heap_data.size();
    }
    void clear(){
        heap_data.clear();
        
    }
};
