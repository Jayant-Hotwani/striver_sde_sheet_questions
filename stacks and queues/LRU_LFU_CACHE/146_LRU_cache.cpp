#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node* prev=NULL;
    Node* next=NULL;
    Node(int key , int value){
        this->key=key;
        this->value=value;
    }
};

class LRUCache {
public:
    int cap=-1;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    map<int,Node*>mp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void delete_node(Node* curr){
        if (curr == head || curr == tail) return;
        Node* prev_node=curr->prev;
        Node* next_node=curr->next;
        prev_node->next=next_node;
        next_node->prev=prev_node;
        int key=curr->key;
        mp.erase(key);
    }

    void insert_in_front(Node* curr){
        int key=curr->key;
        mp[key]=curr;
        Node* next_to_head=head->next;
        head->next=curr;
        curr->prev=head;
        curr->next=next_to_head;
        next_to_head->prev=curr;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        else{
            Node* curr=mp[key];
            int value=curr->value;
            delete_node(curr);
            insert_in_front(curr);
            return value;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            delete_node(curr);
            Node* new_node=new Node(key,value);
            insert_in_front(new_node);
        }
        else{
            // we need to delete soemthing and then add
            if (mp.size()>=cap){
            Node* lru=tail->prev;
            delete_node(lru);
            Node* new_node=new Node(key,value);
            insert_in_front(new_node);
            }
            else{
                Node* new_node=new Node(key,value);
                insert_in_front(new_node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */