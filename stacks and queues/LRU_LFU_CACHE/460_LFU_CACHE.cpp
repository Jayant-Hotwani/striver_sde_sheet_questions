#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int value;
    int cnt;
    Node* prev=NULL;
    Node* next=NULL;
    Node(int k , int v){
        key=k;
        value=v;
        cnt=1;
    }
};

class List{
    public:
    Node* head;
    Node* tail;
    int size;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        size=0;
        head->next=tail;
        tail->prev=head;
    }

    void insert_in_front(Node* curr){

        Node* next_head=head->next;
        head->next=curr;
        curr->prev=head;
        curr->next=next_head;
        next_head->prev=curr;
        size++;

    }
    void remove_node(Node* curr){

        Node* prevCurr=curr->prev;
        Node* nextCurr=curr->next;
        prevCurr->next=nextCurr;
        nextCurr->prev=prevCurr;
        size--;
    }
};


class LFUCache {
public:
    map<int,List*>frequency_map;
    map<int,Node*>nodes;

    int min_freq;
    int max_cache_size;
    int curr_cache_size;
    LFUCache(int capacity) {
        min_freq=0;
        curr_cache_size=0;
        max_cache_size=capacity;        
    }

    void update_freq_map(Node* curr){
        if(curr==NULL) return;
        int curr_freq=curr->cnt;
        curr->cnt++;
        List* curr_list=frequency_map[curr_freq];
            // remove this from this list;
        if(curr_list!=NULL)
        curr_list->remove_node(curr);
        // if all elements from min freq is empty then update min freq;
        if (curr_freq==min_freq && frequency_map[curr_freq]->size==0){
            min_freq++;
        }
        int new_freq=curr->cnt;
            // add into new list;
        List* new_list=new List();
        if(frequency_map.find(new_freq)!=frequency_map.end()){
            new_list=frequency_map[new_freq];
        }
        if(new_list!=NULL)
        new_list->insert_in_front(curr);
        frequency_map[new_freq]=new_list;

    }
    
    int get(int key) {
        if (nodes.find(key)==nodes.end()) return -1;
        else{
            Node* curr=nodes[key];
            int value=curr->value;
            update_freq_map(curr);
            return value;
        }
    }
    
    void put(int key, int value) {
        if(max_cache_size==0) return;
        if (nodes.find(key)!=nodes.end()){
            Node* curr=nodes[key];
            curr->value=value;
            update_freq_map(curr);
        }
        else{
            //check capacity first;
            if(curr_cache_size==max_cache_size){
                List* min_freq_list=frequency_map[min_freq];
                Node* node_to_be_removed=min_freq_list->tail->prev;
                nodes.erase(node_to_be_removed->key);
                min_freq_list->remove_node(node_to_be_removed);
                curr_cache_size--;
            }
            curr_cache_size++;
            min_freq=1;
            List* new_freq_list=new List();
            if (frequency_map.find(min_freq)!=frequency_map.end()){
                new_freq_list=frequency_map[min_freq];
            }
            Node* newNode=new Node(key,value);
            new_freq_list->insert_in_front(newNode);
            nodes[key]=newNode;
            frequency_map[min_freq]=new_freq_list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */