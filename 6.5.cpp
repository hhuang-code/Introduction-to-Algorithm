#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <climits>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
    The priority queue is implemented by a max heap.
    The heap is stored in a vector and the index of the root is 1.
*/

/*
    Return the maximum element.
*/
int HEAP_MAXIMUM(vector<int>& A){
    return A[1];
}

/*
    Return and delete the maximum element.
*/
int HEAP_EXTRACT_MAX(vector<int>& A){
    int heap_size = A.size() - 1;
    assert(heap_size >= 1);

    int max = HEAP_MAXIMUM(A);
    A[1] = A[heap_size];
    A.pop_back();
    heap_size--;
    MAX_HEAPIFY(A, heap_size, 1);

    return max;
}

/*
    Increase the value of the i-th element to key.
*/
void HEAP_INCREASE_KEY(vector<int>& A, int i, int key){
    assert(key > A[i]);

    A[i] = key;
    while(i > 1 && A[PARENT(i)] < A[i]){
        int tmp = A[i];
        A[i] = A[PARENT(i)];
        A[PARENT(i)] = tmp;
        i = PARENT(i);
    }
}

/*
    Insert a value (key) to the maximum priority queue.
*/
void MAX_HEAP_INSERT(vector<int>& A, int key){
    A.push_back(INT_MIN);       //#include <climits>
    int heap_size = A.size() - 1;
    HEAP_INCREASE_KEY(A, heap_size, key);
}


/*
    The minimum priority queue is implemented by a min heap.
    The heap is stored in a vector and the index of the root is 1.
*/
/**6.5-3**/

/*
    Return the minimum element.
*/
int HEAP_MIMIMUM(vector<int>& A){
    return A[1];
}

/*
    Return and delete the minimum element.
*/
int HEAP_EXTRACT_MIN(vector<int>& A){
    int heap_size = A.size() - 1;
    assert(heap_size >= 1);

    int min = HEAP_MIMIMUM(A);
    A[1] = A[heap_size];
    A.pop_back();
    heap_size--;
    MIN_HEAPIFY(A, heap_size, 1);

    return min;
}

/*
    Decrease the value of the i-th element to key.
*/
void HEAP_DECREASE_KEY(vector<int>& A, int i, int key){
    assert(key < A[i]);

    A[i] = key;
    while(i > 1 && A[PARENT(i)] > A[i]){
        int tmp = A[i];
        A[i] = A[PARENT(i)];
        A[PARENT(i)] = tmp;
        i = PARENT(i);
    }
}

/*
    Insert a value (key) to the minimum priority queue.
*/
void MIN_HEAP_INSERT(vector<int>& A, int key){
    A.push_back(INT_MAX)        //#include <climits>
    int heap_size = A.size() - 1;
    HEAP_DECREASE_KEY(A, heap_size, key);
}

/*
    Use a maximum priority queue to implement a FIFO queue.
*/
/**6.5-6**/
class Node{
public:
    int key, value;
    Node(int v){
        key = INT_MIN;
        value = v;
    }
}

class QUEUE{
public:
    QUEUE();
    int size();
    void empty();
    int top();
    void push(int x);
    void pop();
private:
    void increase_key(int i, int k);    //Similar to HEAP_INCREASE_KEY
    void insert(Node node); //Similar to MAX_HEAP_INSERT

    MAX_PRIORITY_QUEUE mpq;
}

QUEUE::QUEUE(){
    A.push_back(Node(INT_MAX));   //The 0-the element is not used.
}

int QUEUE::size(){
    return A.size() - 1;
}

void QUEUE::empty(){
    while(size > 1){
        A.pop_back();
    }
}

int QUEUE::top(){
    assert(A.size() > 1);

    return A[1].value;
}

void QUEUE::push(int x){
    Node node = new Node(x);
    int heap_size = A.size() - 1;
    for(int i = 1; i <= heap_size; i++){
        A[i].key++;
    }
    heap_insert(node);
}

void QUEUQ::pop(){
    int heap_size = A.size() - 1;
    assert(heap_size >= 1);

    A.pop_back();
    heap_size--;
    for(int i = 1; i <= heap_size; i++){
        A[i].key--;
    }
}

void QUEUE::increase_key(int i, int key){
    assert(key > A[i].key);

    A[i].key = key;
    while(i > 1 && A[PARENT(i)].key < A[i].key){
        int tmp_key = A[i].key;
        int tmp_value = A[i].value;
        A[i].key = A[PARENT(i)].key;
        A[i].value = A[PARENT(i)].value;
        A[PARENT(i)].key = tmp_key;
        A[PARENT(i)].value = tmp_value;
        i = PARENT(i);
    }
}

void QUEUE::insert(Node node){
    A.push_back(INT_MIN);       //#include <climits>
    int heap_size = A.size() - 1;
    HEAP_INCREASE_KEY(A, heap_size, key);
}

#endif // HEADER_H_INCLUDED
