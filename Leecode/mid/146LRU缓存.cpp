#include<iostream>
using namespace std;
#include<unordered_map>

/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

//定义双向链表
struct Node
{
    int key,val;
    Node *prev,*next;
    Node():key(0),val(0),prev(nullptr),next(nullptr){}
    Node(int key,int val):key(key),val(val),prev(nullptr),next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity), size(0) {
        this->head = new Node();
        this->tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key)){
            movetohead(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            movetohead(cache[key]);
            cache[key]->val = value;
        }
        else{
            Node* newnode = new Node(key,value);
            addhead(newnode);
            cache[key] = newnode;
            size ++;
            if(size > _capacity){
                Node* node = deletail();
                cache.erase(node->key);
                size --;
                delete node;
            }
        }
    }

    void rmnode(Node* node1){
        node1->prev->next = node1->next;
        node1->next->prev = node1->prev;
    }

    void addhead(Node* node1){
        node1->prev = head;
        node1->next = head->next;
        head->next->prev = node1;
        head->next = node1;

    }

    void movetohead(Node *node){
        rmnode(node);
        addhead(node);
    }

    Node* deletail(){
        Node *node = tail->prev;
        rmnode(node);
        return node;
    }

private:
    int _capacity, size;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> cache;
};