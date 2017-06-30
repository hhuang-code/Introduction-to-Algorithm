/**6-1 start**/
#define LEFT(i) (i * 2)
#define RIGHT(i) (i * 2 + 1)
#define PARENT(i) (i / 2)

void MAX_HEAPIFY(vector<int>& A, int heap_size, int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int largest = i;
    if(left <= heap_size && A[largest] < A[left]){
        largest = left;
    }
    if(right <= heap_size && A[largest] < A[right]){
        largest = right;
    }
    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        MAX_HEAPIFY(A, heap_size, largest);
    }
}

void BUILD_MAX_HEAP(vector<int>& A, int heap_size){
    for(int i = heap_size / 2; i >= 1; i--){
        MAX_HEAPIFY(A, heap_size, i);
    }
}

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

void MAX_HEAP_INSERT(vector<int>& A, int heap_size, int key){
    A[heap_size] = INT_MIN;       //#include <climits>
    HEAP_INCREASE_KEY(A, heap_size, key);
}

void BUILD_MAX_HEAP_ALT(vector<int>& A, int heap_size){
    for(int i = 2; i <= heap_size; i++){
        MAX_HEAP_INSERT(A, i, A[i]);
    }
}
/**6-1 end**/
