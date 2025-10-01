
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int,int> pair;
    Node * next;
    Node * back;
    
    Node (int key, int value, Node * n,Node * b){
        this->pair={key,value};
        this->next=n;
        this->back=b;
    }

};
class LRUCache{
    Node * head,*dumtail;
    unordered_map<int,Node*> m;
    int capacity;
    int size;
    LRUCache(int c){
        head = new Node(-1,-1,NULL,NULL);
        dumtail = new Node(-1,-1,NULL,head);
        head->next=dumtail;
        
        size=0;
        capacity=c;
    }
    void deletenode(Node * x){
        x->back->next= x->next;
        x->next->back=x->back;
        delete x;
    }
    void insertnode(int key,int value, Node * b){
        Node * temp = b->back;
        Node * n = new Node(key,value,b,temp);
        temp->next= n;
        b->back=n;
        
        this->m[key]=n;
    }
    int get(int key){
        auto it = m.find(key);
        if(it!=m.end()){
            
            int val = it->second->pair.second;
            deletenode(it->second);
            insertnode(key,val,dumtail);
            
            return val;
        }
        return -1;

    }
    void put(int key,int value){
        auto it = m.find(key);
        
        if(it!=m.end()){
            
            
            deletenode(it->second);
            
            size--;//temporarily for delete 
            
        }
        insertnode(key,value,dumtail);
        
        size++;
        if(size>capacity) {
            m.erase(head->next->pair.first);
            deletenode(head->next);
            size--;
            
        }
    }




};