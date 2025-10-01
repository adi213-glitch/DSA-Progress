#pragma once

#include <vector>
#include <list>
#include <string>
#include <utility> // For std::pair

// Forward declaration of File. This is sufficient for the hasher,
// which only needs to know that 'File' is a type it can have a pointer to.
// This avoids including the entire File.hpp, reducing dependencies.
class File; 
using namespace std;

// --- HASHER POLICY STRUCTS ---
// A "policy" struct must be provided to MyHashMap for each key type.
// This design ensures that no part of the standard library's hashing is used

/**
//  * @brief A compliant hasher for std::string keys.
//  * Implements a polynomial rolling hash function.
 */
struct StringHasher {
    size_t operator()(const std::string& key) const {
        size_t hash = 0;
        size_t p = 31; // A small prime number often used in string hashing
        for (char c : key) {
            hash = hash * p + c;
        }
        return hash;
    }
    // tc is O(length of string)
};

/**
 * @brief A compliant hasher for int keys.
 * For integer keys that are already well-distributed (like sequential version IDs),
 * the simplest hash function is the identity function. The modulo operation
 * in the map itself will handle bucket placement.
 */
struct IntHasher {
    size_t operator()(int key) const {
        return static_cast<size_t>(key);
    }
    //O(1)
};
struct FilePointerHasher {
    size_t operator()(const File* key) const {
        // Treat the pointer's memory address as a large unsigned integer.
        // fast and effective way to get a unique numeric value for each unique File object.
        return reinterpret_cast<uintptr_t>(key);
    }
    //O(1)
};

// --- HASHMAP IMPLEMENTATION ---

template <typename K, typename V, typename Hasher>
class MyHashMap {
private:
    // The main storage: a vector of lists (buckets). Each list stores
    // key-value pairs to handle collisions via separate chaining.
    vector<list<pair<const K, V>>> table;
    size_t current_size;
    size_t table_capacity;
    Hasher hasher; // An instance of the provided hasher policy object

public:
    /**
     * @brief Constructs the hash map with a given capacity.
     * @param capacity The number of buckets in the hash table.
     */
    explicit MyHashMap(size_t capacity = 100){
        table_capacity=capacity;
        current_size=0; 
        table.resize(table_capacity);
        //O(c) c= no. of lists
    }

    /**
     * @brief Inserts a key-value pair. If the key already exists, updates the value.
     * @param key The key to insert.
     * @param value The value to associate with the key.
     */
    void insert(const K& key, const V& value) {
        size_t index = hasher(key) % table_capacity;
        //O(L) L= key.length()
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
        current_size++;
        //avg tc = O(1) 
        //worst case all keys hash to same bucketlist so it takes O(n) just like the unordered map
    }

    /**
     * @brief Retrieves a pointer to the value associated with a key.
     * @param key The key to look for.
     * @return A pointer to the value if the key is found, otherwise nullptr.
     */
    V* get(const K& key) {
        size_t index = hasher(key) % table_capacity;
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return &pair.second;
            }
        }
        return nullptr;
        //avg tc O(1) worst case O(n) same logic
    }

    /**
     * @brief Removes a key-value pair from the map.
     * @param key The key to remove.
     */
    void remove(const K& key) {
        size_t index = hasher(key) % table_capacity;
        auto& bucket_list = table[index];
        for (auto it = bucket_list.begin(); it != bucket_list.end(); ++it) {
            if (it->first == key) {
                // LIST handles erase operation in O(1) time unlike vector which takes O(n).
                bucket_list.erase(it);
                current_size--;
                return;
            }
        }
        //avg tc O(1) worst case O(n) same logic
    }

    /**
     * @brief Returns the number of elements in the map.
     */
    size_t size() const {
        return current_size;
    }

    auto& getTable(){
        return table;
    }
};
