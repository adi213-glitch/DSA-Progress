#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    vector<int> data;
    Node * next;
    Node * back;
    
    Node (int key, int value,int freq, Node * n,Node * b){
        this->data={key,value,freq};
        this->next=n;
        this->back=b;
    }

};

class LFUCache{
public:
    Node * dumhead,*dumtail;
    unordered_map<int,Node*> keytonode;
    unordered_map<int,Node*> freqtonode;
    int capacity;
    int size;
    LFUCache(int c){
        dumhead = new Node(-1,-1,-1,NULL,NULL);
        dumtail = new Node(-1,-1,-1,NULL,dumhead);
        dumhead->next=dumtail;
        
        size=0;
        capacity=c;
    }
    void deletenode(Node * x){
        x->back->next = x->next;
        x->next->back = x->back;
        
        // If x was the leader for its frequency...
        if (freqtonode[x->data[2]] == x) {
            // ... and the node before it has a different frequency (or is the head)
            // then x was the only node of its kind.
            if (x->back->data[2] != x->data[2]) {
                freqtonode.erase(x->data[2]);
            } else {
                // Otherwise, the node before it becomes the new leader.
                freqtonode[x->data[2]] = x->back;
            }
        }
        
        keytonode.erase(x->data[0]);
        delete x;
    }
    void insertnode(int key,int value,int freq, Node * b){
        Node * temp = b->next;
        Node * n = new Node(key,value,freq,temp,b);
        
        b->next=n;
        temp->back= n;
        
        keytonode[key]=n;
        freqtonode[freq]=n;
    }
    int get(int  key){
        auto it = keytonode.find(key);
        if(it!=keytonode.end()){
            int val = it->second->data[1];
            int currfreq= it->second->data[2];
            
            //insert just behind currfreq+1 ka corresponding node
            auto let = freqtonode.find(currfreq+1);
            if(let!=freqtonode.end()){       
                deletenode (it->second);
                insertnode(key,val,currfreq+1,let->second);
            }else{
                
                Node * x = it->second;
                if( (x->next->data[2]==currfreq )){
                    //move posn
                    x->back->next= x->next;
                    x->next->back=x->back;


                    // set posn
                    auto puthere = freqtonode[currfreq];
                    puthere->next->back=x;
                    x->next=puthere->next;
                    x->back=puthere;
                    puthere->next=x;
                    //set freq map
                    x->data[2]=currfreq+1;
                    freqtonode[currfreq+1]=x;



                    
                }else if((x->back->data[2]==currfreq )){
                    
                    freqtonode[currfreq]=x->back;
                    freqtonode[currfreq+1]=x;
                    x->data[2]=currfreq+1;
                    
                }else{
                    freqtonode[currfreq+1]=x;
                    x->data[2]=currfreq+1;
                    freqtonode.erase(currfreq);
                }
                

            }
            return val;
        }


        return -1;
    }
    void put(int key, int value){
            if (capacity == 0) { // Handle zero capacity edge case
                return;
            }
            auto it = keytonode.find(key);
            
            if(it!=keytonode.end()){
                
                int currfreq= it->second->data[2];
                
                //insert just behind currfreq+1 ka corresponding node
                auto let = freqtonode.find(currfreq+1);
                if(let!=freqtonode.end()){       
                    deletenode (it->second);
                    insertnode(key,value,currfreq+1,let->second);
                }else{
                    
                    Node * x = it->second;
                    if( (x->next->data[2]==currfreq )){
                        //move posn
                        x->back->next= x->next;
                        x->next->back=x->back;


                        // set posn
                        auto puthere = freqtonode[currfreq];
                        puthere->next->back=x;
                        x->next=puthere->next;
                        x->back=puthere;
                        puthere->next=x;
                        //set freq map
                        x->data[2]=currfreq+1;
                        freqtonode[currfreq+1]=x;



                        
                    }else if((x->back->data[2]==currfreq )){
                        
                        freqtonode[currfreq]=x->back;
                        freqtonode[currfreq+1]=x;
                        x->data[2]=currfreq+1;
                        
                    }else{
                        freqtonode[currfreq+1]=x;
                        x->data[2]=currfreq+1;
                        freqtonode.erase(currfreq);
                    }
                    x->data[1]=value;

                }
                
            }else{
                if(size==capacity){
                        Node * x = dumhead->next;
                        x->back->next= x->next;
                        x->next->back=x->back;
                        keytonode.erase(x->data[0]);
                        if((x->next->data[2])!=x->data[2]){
                            freqtonode.erase(x->data[2]);
                        }
                        delete x;
                        size--;
                    }
                // original key not found in LL/MAP so insert at after dummyhead
                if(freqtonode.find(1)!=freqtonode.end()){
                    insertnode(key,value,1,freqtonode[1]);
                }else{
                    insertnode(key,value,1,dumhead);
                }
                size++;
            }
            
            


           
    }
    



};