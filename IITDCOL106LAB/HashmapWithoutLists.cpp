#include <iostream>
#include <vector>
#include <list>

#include <utility> // For std::pair



using namespace std;

class Node{
public : 
    pair<int,int> data;
    Node * next ;
    Node(int key, int value){
        data = {key,value};
        next=NULL;
        
    }
    Node(int key, int value,Node *n){
        data = {key,value};
        next=n;
    }
};


// --- HASHMAP IMPLEMENTATION ---


class MyHashMap {
private:
    
    
    
    // The main storage: a vector of lists (buckets). Each list stores
    // key-value pairs to handle collisions via separate chaining.
    vector<Node *> table;
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
    
        
        for(int i =0; i<capacity;i++) table[i]=new Node(-1,-1);
        
    }
    ~MyHashMap(){
        for(Node * i: table){
            Node * temp = i;
            while(temp){
                Node * nex = temp->next;
                delete temp;
                temp = nex;
            }
        }

    }
    /**
     * @brief Inserts a key-value pair. If the key already exists, updates the value.
     * @param key The key to insert.
     * @param value The value to associate with the key.
     */
    void insert(const int& key, const int& value) {
        size_t index = IntHasher(key) % table_capacity;
        Node * h = table[index];
        Node * temp =h->next;

        while (temp) {
            if (temp->data.first==key) {
                temp->data.second = value;
                return;
            }
            temp=temp->next;
        }
        Node * newpair = new Node(key,value,h->next);
        h->next=newpair;
        current_size++;
    }

    /**
     * @brief Retrieves a pointer to the value associated with a key.
     * @param key The key to look for.
     * @return A pointer to the value if the key is found, otherwise nullptr.
     */
    int* get(const int& key) {
        size_t index = IntHasher(key) % table_capacity;
        Node * h = table[index];
        Node * temp =h->next;

        while (temp) {
            if (temp->data.first==key) {
                return &temp->data.second ;
               
            }
            temp=temp->next;
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

        Node * h = table[index];
        Node * temp =h;
        
        while (temp->next) {
            if (temp->next->data.first==key) {
                Node * del = temp->next;
                temp->next=temp->next->next;
                delete del;
                current_size--;
                return;
            }
            temp=temp->next;
        }


        
    }

    /**
     * @brief Returns the number of elements in the map.
     */
    size_t size() const {
        return current_size;
    }

    
};

int func (vector<int> &links){
    if(links.size()==0) return 0;
    MyHashMap m(links.size());
    for(int i : links){
        m.insert(i,i-1);
    }
    vector<int> vec;
    for(int i : links){
        
        if(m.get(i-1)==NULL){
            
            vec.push_back(i);
        }
    }    
    int mxsize =0;
    for(auto v : vec){
        int currlen=1;
        int currele = v;
        while(m.get(currele +1)!=NULL  ){
            currlen++;
            currele++;
        }
        if(currlen>mxsize) mxsize=currlen;
        
    }
    return mxsize;
}
