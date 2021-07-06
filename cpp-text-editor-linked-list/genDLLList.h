//
//  genDLLList.h
//  Proje
//
//  Created by Muzaffer Tolga Yakar on 25.12.2020.
//

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include <iostream>
using namespace std;
template<class T>
class DLLNode {
public:
    DLLNode() {
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode<T> *n = 0, DLLNode<T> *p = 0) {
        info = el; next = n; prev = p;
    }
    T info;
    DLLNode<T> *next, *prev;
};

template<class T>
class DoublyLinkedList {
private:
    int size;
public:
    DoublyLinkedList() {
        head = tail = 0;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();
    ~DoublyLinkedList() {
        clear();
    }
    void print(int n){
        DLLNode<T> *iter = head;
        for(int i = 0; i < (n-1)*10; i++){
            iter = iter -> next;
        }
        for(int j = 1+((n-1)*10); j <=10*n;j++){
            if(iter != NULL){
                cout << j << ": " << iter->info << endl;
                iter = iter -> next;
            }
            else{
                cout << j << ":" << endl;
            }
        }
        cout << "--- Page " << n << " ---"<< endl;
    }
    T rep(const int&n, T s){
        DLLNode<T> *iter = head;
        for(int i = 0; i < n-1; i++){
            iter = iter -> next;
        }
        T el = iter -> info;
        iter -> info = s;
        return el;
    }
    int getSize(){
        return size;
    }
    bool isEmpty() const {
        return head == 0;
    }
    void clear();
    void setToNull() {
        head = tail = 0;
    }
    void addToDLLHead(const T&);
    void addToDLLAny(const T&, int);
    T deleteFromDLLAny(const int&);
    T deleteFromDLLHead();
    T& firstEl();
    T* find(const T&) const;
protected:
    DLLNode<T> *head, *tail;
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
        for (DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->info << ' ';
        return out;
    }
};

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el) {
    if (head != 0) {
         head = new DLLNode<T>(el,head,0);
         head->next->prev = head;
         size++;
    }
    else {head = tail = new DLLNode<T>(el); size = 1;}
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != 0) {
         tail = new DLLNode<T>(el,0,tail);
         tail->prev->next = tail;
         size++;
    }
    else {head = tail = new DLLNode<T>(el);size=1;}
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead() {
    T el = head->info;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
         size = 0;
    }
    else {              // if more than one DLLNode in the list;
         head = head->next;
         delete head->prev;
         head->prev = 0;
         size--;
    }
    return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
         size = 0;
    }
    else {              // if more than one DLLNode in the list;
         tail = tail->prev;
         delete tail->next;
         tail->next = 0;
         size--;
    }
    return el;
}

template <class T>
T* DoublyLinkedList<T>::find(const T& el) const {
    DLLNode<T> *tmp = head;
    for ( ; tmp != 0 && !(tmp->info == el);  // overloaded ==
         tmp = tmp->next);
    if (tmp == 0)
         return 0;
    else return &tmp->info;
}

template<class T>
T& DoublyLinkedList<T>::firstEl() {
    return head->info;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    for (DLLNode<T> *tmp; head != 0; ) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}
template<class T>
void DoublyLinkedList<T>::addToDLLAny(const T& data, int n){
    DLLNode<T> *iter = head;
    DLLNode<T> *temp = new DLLNode<T>;
    temp -> info = data;
    if(n > getSize() && n < 1){
        cout << "Wrong position!!!!" << endl;
    }
    for(int i =0;i<n-1;i++){
        iter = iter -> next;
    }
    temp -> next = iter;
    iter -> prev -> next = temp;
    temp -> prev = iter -> prev;
    iter -> prev = temp;
    size++;
}
template<class T>
T DoublyLinkedList<T>::deleteFromDLLAny(const int &n){
    DLLNode<T> * iter = head;
    DLLNode<T> * temp;
    for(int i = 0; i < n - 1; i++){
        iter = iter -> next;
    }
    T el = iter -> info;
    temp = iter;
    iter -> prev -> next = iter -> next;
    iter -> next -> prev = iter -> prev;
    size--;
    delete temp;
    return el;
}

#endif
