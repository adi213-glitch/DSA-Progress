#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    vector<int> vec;
    Node * next;
    Node * back;
    
    Node (int key, int value,int freq, Node * n,Node * b){
        this->vec={key,value,freq};
        this->next=n;
        this->back=b;
    }

};


class LFUCache {
public:
    unordered_map<int,Node *> m1;
    unordered_map<int,Node *> m2;
    Node * dummyh,* dummyt;
    int mxsize;

    
    // del(node)
    // insertnode( insert after here, new node)
    LFUCache(int capacity) {
        dummyh=new Node(-1,-1,-1,NULL,NULL);
        dummyt=new Node(-1,-1,-1,NULL,NULL);
        dummyh->next=dummyt;
        dummyt->back=dummyh;
        
      
        mxsize= capacity;
    }
    void del(Node * n){
        n->next->back=n->back;
        n->back->next=n->next;

        delete n;
    }
    void insertnode(Node * pr, Node * n){
        n->next=pr->next;
        pr->next=n;

        n->next->back=n;
        n->back=pr;
    }
    
    int get(int key) {
        auto it= m1.find(key);
        if(it==m1.end()) return -1;
        else{
            Node * delet= it->second;
           

            // int m1_key = delet->vec[0];
            int val= delet->vec[1];
            int currfreq= delet->vec[2];
            auto let =m2.find(currfreq);

            Node * previous= delet->back;
            bool check=true;
             Node * insertafter= let->second;
            if(let->second== delet){
                if(  delet->back->vec[2]==currfreq){
                    let->second=delet->back;
                    insertafter=delet->back;
                }else{
                    // insertafter=delet->back;
                    m2.erase(currfreq);
                    check=false;
                }
            }
           
          
            del(delet);
            Node * ne= new Node(key,val,currfreq+1,NULL,NULL );
            auto i =m2.find(currfreq+1);
            if(i!=m2.end()){
                //  insert just after this node
                Node * ih = i->second;
                insertnode (ih, ne);
                // update m2 mein freq ka node
                i->second=ne;
            }else{
                if(check) insertnode(insertafter, ne);
                else insertnode(previous,ne); 
                m2[currfreq+1]=ne;
            }
            m1[key]=ne;
            return val;


        }
    }
    
    void put(int key, int value) {
        auto it= m1.find(key);
        if(it==m1.end()){
            // this is a brand new node must have freq =1
            if(m1.size()==mxsize){
                // erase stale node the acutal LFU ka lRU
                Node * delet = dummyh->next;
                int m1_key = delet->vec[0];
                int currfreq= delet->vec[2];
                auto let =m2.find(currfreq);
               
                
                if(let->second== delet){
                    
                    m2.erase(currfreq);
                        
                    
                }
               
                m1.erase(m1_key);
                del(delet);
            }
            // inserting fresh node at freq=1 ka MRU
            Node * ne= new Node(key,value,1,NULL,NULL );
            auto i =m2.find(1);
            if(i!=m2.end()){
                //  insert just after this node
                Node * ih = i->second;
                insertnode (ih, ne);
                // update m2 mein freq ka node
                i->second=ne;
            }else{
                
                insertnode(dummyh,ne);
                m2[1]=ne;
            }
            m1[key]=ne;
            
        }else{
            // this node already exists just inc freq and update value
            Node * delet =it->second;
           
            // int m1_key = delet->vec[0];
            int currfreq= delet->vec[2];
            
            Node * previous=delet->back;
            auto let =m2.find(currfreq);
            bool check = true;
            Node* insertafter = let->second;
            if(let->second== delet){
                if( delet->back->vec[2]==currfreq){
                    let->second=delet->back;
                    insertafter = delet->back;
                }else{
                    check=false;
                    m2.erase(currfreq);
                }
            }
             
            // m1[key]=;HOLD
            del(delet);
            Node * ne= new Node(key,value,currfreq+1,NULL,NULL );
            auto i =m2.find(currfreq+1);
           
            if(i!=m2.end()){
                //  insert just after this node
                Node * ih = i->second;
                insertnode (ih, ne);
                // update m2 mein freq ka node
                i->second=ne;
            }else{
                if(check)  insertnode(insertafter,ne);
                else insertnode(previous, ne); 
                m2[currfreq+1]=ne;
            }
            m1[key]=ne;


        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */