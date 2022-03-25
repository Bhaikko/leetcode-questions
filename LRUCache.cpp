#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int key;
        int value;
        Node* left;
        Node* right;
    
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class LRUCache {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> cache;
    int capacity;
    
private:
    void deleteLRUentry()
    {
        if (!tail) {
            return;
        }
        
        Node* node = tail;
        tail = tail->right;
        
        if (!tail) {
            tail = nullptr;
            head = nullptr;
            
        } else {
            tail->left = nullptr;
        }
        
        cache.erase(node->key);
        delete node;
    }
    
    void insertLRUEntry(int key, int value)
    {
        Node* node = new Node(key, value);
        
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            head->right = node;
            node->left = head;
            
            head = node;
        }
        
        cache[key] = node;
    }
    
    void moveToHead(Node* node)
    {
        if (head == tail || head == node) {
            return;
        }
        
        if (tail == node) {
            tail = tail->right;
        }
        
        Node* left = node->left;
        Node* right = node->right;
        
        if (left) {
            left->right = right;
        }
        
        if (right) {
            right->left = left;
        }
        
        head->right = node;
        node->left = head;
        
        head = node;
        
    }
    
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        moveToHead(cache[key]);
        
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            moveToHead(cache[key]);
            cache[key]->value = value;
        } else {
            if (cache.size() >= capacity) {
                deleteLRUentry();
            } 
            
            insertLRUEntry(key, value);
        }
        
        
    }
};

