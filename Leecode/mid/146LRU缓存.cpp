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
    Node *head,*tail;
    int capacity,size;
    unordered_map<int,Node*> h;//哈希表存储节点与key的信息
    LRUCache(int _capacity): capacity(_capacity),size(0){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(h.count(key)){
            removenode(h[key]);//将此被访问的数据移到缓存区最前
            addnodetohead(h[key]);
            return h[key]->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(h.count(key)){
            removenode(h[key]);
            addnodetohead(h[key]);
            h[key]->val = value;
        }
        else{
            if(capacity == size){
                Node *remo = tail->prev;
                h.erase(remo->key); //从哈希表中删除最后一个
                removenode(remo); //从链表中删除最后一个
                size --;
            }
            Node *new_node = new Node(key,value);
            addnodetohead(new_node);
            h[key] = new_node;
            size ++;
        }
    }
    void addnodetohead(Node *node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removenode(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};