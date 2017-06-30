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
    Node(int k, int v): key(k), value(v){};
    int get_key();
    int get_value();
    void set_key(int k);
    void set_value(int v);
    Node& operator=(const Node& node);
private:
    int key;
    int value;
};

int Node::get_key(){
    return key;
}

int Node::get_value(){
    return value;
}

void Node::set_key(int k){
    key = k;
}

void Node::set_value(int v){
    value = v;
}

Node& Node::operator=(const Node& node){
    if(this != &node){
        this->key = node.key;
        this->value = node.value;
    }

    return *this;
}

class MAX_PRIORITY_QUEUE{
public:
    MAX_PRIORITY_QUEUE();
    int GET_SIZE();
    Node MAXIMUM();
    Node EXTRACT_MAX();
    void INCREASE_KEY(int i, int k);
    void INSERT(Node node);
    void INCREASE_ALL_KEY();
    void DECREASE_ALL_KEY();
private:
    int PARENT(int i);
    int LEFT(int i);
    int RIGHT(int i);
    void MAX_HEAPIFY(int i);
    vector<Node> nv;
    int heap_size;
};

MAX_PRIORITY_QUEUE::MAX_PRIORITY_QUEUE(){
    Node node(INT_MIN, 0);
    nv.push_back(node);    //unused node
    heap_size = 0;
}

int MAX_PRIORITY_QUEUE::GET_SIZE(){
    assert(heap_size >= 0);

    return heap_size;
}

/*
    Return the element with the maximum key.
*/
Node MAX_PRIORITY_QUEUE::MAXIMUM(){
    return nv[1];
}

/*
    Return and delete the element with the maximum key.
*/
Node MAX_PRIORITY_QUEUE::EXTRACT_MAX(){
    assert(heap_size >= 1);

    Node max_node = MAXIMUM();
    nv[1] = nv[heap_size];
    nv.pop_back();
    heap_size--;
    MAX_HEAPIFY(1);

    return max_node;
}

/*
    Increase the key of the i-th element to k.
*/
void MAX_PRIORITY_QUEUE::INCREASE_KEY(int i, int k){
    assert(k >= nv[i].get_key());

    nv[i].set_key(k);
    while(i > 1 && nv[PARENT(i)].get_key() < nv[i].get_key()){
        Node tmp_node = nv[i];
        nv[i] = nv[PARENT(i)];
        nv[PARENT(i)] = tmp_node;
        i = PARENT(i);
    }
}

/*
    Insert a node to the maximum priority queue.
*/
void MAX_PRIORITY_QUEUE::INSERT(Node node){
   Node new_node(INT_MIN, node.get_value());

   nv.push_back(new_node);
   heap_size++;
   INCREASE_KEY(heap_size, node.get_key());
}

/*
    Increase all keys in the maximum priority queue by 1.
*/
void MAX_PRIORITY_QUEUE::INCREASE_ALL_KEY(){
    for(int i = 1; i <= heap_size; i++){
        nv[i].set_key(nv[i].get_key() + 1);
    }
}

/*
    Decrease all keys in the maximum priority queue by 1.
*/
void MAX_PRIORITY_QUEUE::DECREASE_ALL_KEY(){
    for(int i = 1; i <= heap_size; i++){
        nv[i].set_key(nv[i].get_key() - 1);
    }
}

int MAX_PRIORITY_QUEUE::PARENT(int i){
    return i / 2;
}

int MAX_PRIORITY_QUEUE::LEFT(int i){
    return 2 * i;
}

int MAX_PRIORITY_QUEUE::RIGHT(int i){
    return 2 * i + 1;
}

void MAX_PRIORITY_QUEUE::MAX_HEAPIFY(int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int largest = i;
    if(left <= heap_size && nv[largest].get_key() < nv[left].get_key()){
        largest = left;
    }
    if(right <= heap_size && nv[largest].get_key() < nv[right].get_key()){
        largest = right;
    }
    if(largest != i){
        Node tmp_node = nv[i];
        nv[i] = nv[largest];
        nv[largest] = tmp_node;
        MAX_HEAPIFY(largest);
    }
}

class FIFO_QUEUE{
public:
    bool empty();
    int size();
    int front();
    int pop();
    void push(int x);
private:
    MAX_PRIORITY_QUEUE mpq;
};

bool FIFO_QUEUE::empty(){
    assert(mpq.GET_SIZE() >= 0);

    if(mpq.GET_SIZE() == 0){
        return true;
    }else if(mpq.GET_SIZE() > 0){
        return false;
    }else{
        return true;
    }
}

int FIFO_QUEUE::size(){
    return mpq.GET_SIZE();
}

int FIFO_QUEUE::front(){
    assert(mpq.GET_SIZE() > 0);

    return mpq.MAXIMUM().get_value();
}

int FIFO_QUEUE::pop(){
    assert(mpq.GET_SIZE() > 0);

    return mpq.EXTRACT_MAX().get_value();
}

void FIFO_QUEUE::push(int x){
    mpq.INCREASE_ALL_KEY();
    Node new_node(INT_MIN, x);
    mpq.INSERT(new_node);
}

class STACK{
public:
    bool empty();
    int size();
    int top();
    int pop();
    void push(int x);
private:
    MAX_PRIORITY_QUEUE mpq;
};

bool STACK::empty(){
    assert(mpq.GET_SIZE() >= 0);

    if(mpq.GET_SIZE() == 0){
        return true;
    }else if(mpq.GET_SIZE() > 0){
        return false;
    }else{
        return true;
    }
}

int STACK::size(){
    return mpq.GET_SIZE();
}

int STACK::top(){
    assert(mpq.GET_SIZE() > 0);

    return mpq.MAXIMUM().get_value();
}

int STACK::pop(){
    assert(mpq.GET_SIZE() > 0);

    return mpq.EXTRACT_MAX().get_value();
}

void STACK::push(int x){
    mpq.DECREASE_ALL_KEY();
    Node new_node(INT_MAX, x);
    mpq.INSERT(new_node);
}

/**6.5-7**/
void HEAP_DELETE(vector<int>& A, int& heap_size, int i){
    if(heap_size == i){
        A.pop_back();
        heap_size--;
    }else{
        A[i] = A[heap_size];
        A.pop_back();
        heap_size--;
        MAX_HEAPIFY(A, heap_size, i);
    }
}

/**6.5-8 start**/
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)

class LinkNode{
public:
    LinkNode(int k, LinkNode* p): key(k), ptr(p){}
    int get_key();
    void set_key(int k);
    LinkNode* get_ptr();
    void set_ptr(LinkNode* p);
private:
    int key;
    LinkNode* ptr;
};

int LinkNode::get_key(){
    return key;
}

void LinkNode::set_key(int k){
    key = k;
}

LinkNode* LinkNode::get_ptr(){
    return ptr;
}

void LinkNode::set_ptr(LinkNode* p){
    ptr = p;
}

void MIN_HEAPIFY(vector<LinkNode*>& A, int heap_size, int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int smallest = i;
    if(left <= heap_size && A[smallest]->get_key() > A[left]->get_key()){
        smallest = left;
    }
    if(right <= heap_size && A[smallest]->get_key() > A[right]->get_key()){
        smallest = right;
    }
    if(smallest != i){
        LinkNode* tmp = A[i];
        A[i] = A[smallest];
        A[smallest] = tmp;
        MIN_HEAPIFY(A, heap_size, smallest);
    }
}

void BUILD_MIN_HEAP(vector<LinkNode*>& A, int heap_size){
    for(int i = heap_size / 2; i >= 1; i--){
        MIN_HEAPIFY(A, heap_size, i);
    }
}

int main(){

    vector<LinkNode*> v;
    LinkNode* cur = NULL;
    LinkNode* tmp = NULL;
    int x, k, n;
    n = 0;

    cout << "Input k: ";
    cin >> k;
    cout << "Input elements of k links (input 0 to end every link):" << endl;
    v.push_back(NULL);  //1-st element is unused.
    for(int i = 1; i <= k; i++){
        v.push_back(NULL);
        do{
           cin >> x;
           if(x){
            if(v[i] == NULL){
                v[i] = new LinkNode(x, NULL);
                cur = v[i];
            }else{
                tmp = new LinkNode(x, NULL);
                cur->set_ptr(tmp);
                cur = cur->get_ptr();
            }
            n++;
           }
        }while(x);
    }

    BUILD_MIN_HEAP(v, k);

    LinkNode* head = NULL;
    cur = NULL;
    while(v.size() > 1){
        if(v[1]){
            MIN_HEAPIFY(v, k, 1);
            if(head == NULL){
                head = v[1];
                cur = head;
            }else{
                cur->set_ptr(v[1]);
                cur = v[1];
            }
            v[1] = v[1]->get_ptr();
        }
        if(!v[1]){
            v[1] = v[k];
            v.pop_back();
            k--;
        }
    }

    /*test start*/
    cur = head;
    while(cur){
        cout << cur->get_key() << " ";
        cur = cur->get_ptr();
    }
    cout << endl;
    /*test end*/

    return 0;
}
/**6.5-8 end**/
