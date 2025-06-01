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
    Node *head,*tail;
    int capacity,size;
    unordered_map<int,Node*> h;//��ϣ��洢�ڵ���key����Ϣ
    LRUCache(int _capacity): capacity(_capacity),size(0){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(h.count(key)){
            removenode(h[key]);//���˱����ʵ������Ƶ���������ǰ
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
                h.erase(remo->key); //�ӹ�ϣ����ɾ�����һ��
                removenode(remo); //��������ɾ�����һ��
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