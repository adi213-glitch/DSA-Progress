// My personal favourite question. I wrote this in my first try with 1 bug which was the updation of key value pair.
// i was using the value to find it in map but i should have used key. asked chatgpt to tell the flaw becuase it totally 
// went under my nose.


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int,int> pair;
    Node * next;
    Node * back;
    
    Node (int value, int key, Node * n,Node * b){
        this->pair={value,key};
        this->next=n;
        this->back=b;
    }

};


class LRUCache  {
public:
    unordered_map<int, Node * > m;
    Node *dummy= new Node(-1,-1,NULL,NULL);
    Node * temp=dummy;
    int mxsize= 0;
    int currsize=0;
    LRUCache(int capacity) {
        
        mxsize= capacity;
        
    }
    
    int get(int key) {
        auto it= m.find(key);
        if(it==m.end()) return -1;
        Node * k = it->second;
        if(k!=temp){
            k->back->next=k->next;
            k->next->back=k->back;
            k->next=NULL;
            k->back=temp;
            temp->next=k;
            temp=k;
        }


        return it->second->pair.first;
        
    }
    
    void put(int key, int value) {
        auto it= m.find(key);
        if(it==m.end()) {
            if(currsize==mxsize){
                Node * head=dummy->next;
                int delfuture= head->pair.second;
                head->pair={value,key};
                if(head->next!=NULL){             
                    head->next->back=head->back;
                    head->back->next=head->next;
                    head->next=NULL;
                    head->back=temp;
                    temp->next=head;                    
                }
                temp=head;
                m.erase(delfuture);
                m[key]=head;
            }else{
                Node * p= new Node(value,key,NULL,temp);
                temp->next=p;
                temp=p;
                currsize++;
                m[key]=p;
            }
        }else{
            it->second->pair.first=value;
            
            Node * k = it->second;
            if(k!=temp){
                k->back->next=k->next;
                k->next->back=k->back;
                k->next=NULL;
                k->back=temp;
                temp->next=k;
                temp=k;
            }
            m[key]=k;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */