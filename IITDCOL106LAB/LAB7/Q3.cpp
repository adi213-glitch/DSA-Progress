#include <iostream>
#include <vector>
#include <list>

#include <utility> // For std::pair



using namespace std;




// --- HASHMAP IMPLEMENTATION ---


class MyHashMap {
private:
    
    
    
    // The main storage: a vector of lists (buckets). Each list stores
    // key-value pairs to handle collisions via separate chaining.
    vector<list<pair<const int, int>>> table;
    size_t current_size;
    size_t table_capacity;
    
    
    /**
     * @brief A compliant hasher for int keys.
     * For integer keys that are already well-distributed (like sequential version IDs),
     * the simplest hash function is the identity function. The modulo operation
     * in the map itself will handle bucket placement.
     */

    size_t IntHasher(int key) const {
        return static_cast<size_t>(key);
    }
public:
    /**
     * @brief Constructs the hash map with a given capacity.
     * @param capacity The number of buckets in the hash table.
     */
    explicit MyHashMap(size_t capacity){
        table_capacity=capacity;
        current_size=0; 
        table.resize(table_capacity);
    }

    /**
     * @brief Inserts a key-value pair. If the key already exists, updates the value.
     * @param key The key to insert.
     * @param value The value to associate with the key.
     */
    void insert(const int& key, const int& value) {
        size_t index = IntHasher(key) % table_capacity;
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
        current_size++;
    }

    /**
     * @brief Retrieves a pointer to the value associated with a key.
     * @param key The key to look for.
     * @return A pointer to the value if the key is found, otherwise nullptr.
     */
    int* get(const int& key) {
        size_t index = IntHasher(key) % table_capacity;
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return &pair.second;
            }
        }
        return nullptr;
    }

    /**
     * @brief Removes a key-value pair from the map.
     * @param key The key to remove.
     */
    void remove(const int& key) {
        size_t index = IntHasher(key) % table_capacity;
        auto& bucket_list = table[index];
        for (auto it = bucket_list.begin(); it != bucket_list.end(); ++it) {
            if (it->first == key) {
                // LIST handles erase operation in O(1) time unlike vector which takes O(n).
                bucket_list.erase(it);
                current_size--;
                return;
            }
        }
    }

    /**
     * @brief Returns the number of elements in the map.
     */
    size_t size() const {
        return current_size;
    }

    
};
int abs(int x){
    return (x<0)? (-1 *x) : x;
}
pair<int,int> func(vector<int> &transaction, int auditsum, int maxindexdistance){
    int n = transaction.size();
    
    MyHashMap m(n);
    int i=0,j=0;

    while(j<n){


        if(abs(j-i)<=maxindexdistance){
            int target = auditsum-transaction[j];
            int * sec = m.get(target);
            if(sec!=NULL){
                if(abs(j- *sec)<=maxindexdistance){
                    return {j, *sec};
                }
            }
            m.insert(transaction[j],j);
            j++;
        }else{
            m.remove(transaction[i]);
            i++;
        }

    }
    
    return {-1,-1};


}