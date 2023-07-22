#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node{
    int data;
    node *next;
    node *prev;
};

node *makeNode(int x){
    node *newNode = new node;
    newNode->data = x;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

int dem(node *head){
    int ans = 0;
    while(head != NULL){
        ++ans;
        head = head->next;
    }
    return ans;
}

void themdau(node *&head, int x){
    node* newNode = makeNode(x);
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
}

void themcuoi(node *&head, int x){
    node *newNode = makeNode(x);
    node *tmp = head;
    if(tmp == NULL){
        head = newNode; return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

void themgiua(node *&head, int x, int k){
    node *newNode = makeNode(x);
    node *tmp = head;
    if(k == 1){
        themdau(head, x); return;
    }
    for(int i = 1; i <= k - 1; i++){
        tmp = tmp->next;
    }
    //tmp : k 
    //1.new node tro vao node thu k
    newNode->next = tmp;
    //2.Ket node node k - 1 voi newNode
    tmp->prev->next = newNode;
    newNode->prev = tmp->prev;
    //3.cho tmp tro nguoc lai newnode
    tmp->prev = newNode;
}

void xoadau(node *&head){
    if(head == NULL) return;
    node *tmp = head;
    head = head->next; 
    if(head != NULL)
        head->prev = NULL;
    delete tmp;
}

void xoacuoi(node *&head){
    if(head == NULL) return;
    node *tmp = head;
    if(tmp->next == NULL){
        head = NULL; delete tmp; return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    delete tmp;
}

void xoagiua(node *&head, int k){
    if(k < 1 || k > dem(head)) return;
    node *tmp = head;
    if(k == 1){
        xoadau(head); return;
    }
    for(int i = 1; i <= k - 1; i++){
        tmp = tmp->next;
    }
    tmp->prev->next = tmp->next;
    if(tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    delete tmp;
}

int main(){
    node *head = NULL;
    for(int i = 1; i <= 5; i++){
        themcuoi(head, i);
    }
    themdau(head, 0);
    themgiua(head, 100, 4);
    xoagiua(head, 4);
    xoagiua(head, 6);
    duyet(head);
}