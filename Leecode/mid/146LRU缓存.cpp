#include<iostream>
using namespace std;
#include<unordered_map>

/*
������Ʋ�ʵ��һ������  LRU (�������ʹ��) ���� Լ�������ݽṹ��
ʵ�� LRUCache �ࣺ
LRUCache(int capacity) �� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� -1 ��
void put(int key, int value) ����ؼ��� key �Ѿ����ڣ�����������ֵ value ��
��������ڣ����򻺴��в������ key-value ���������������¹ؼ����������� capacity ����Ӧ�� ��� ���δʹ�õĹؼ��֡�
���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
*/

//����˫������
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