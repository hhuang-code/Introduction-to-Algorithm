int PARENT(int i){
    return i / 2;
}

int LEFT(int i){
    return 2 * i;
}

int RIGHT(int i){
    return 2 * i + 1;
}

/*
    The max heap is stored in A and the index of the root is 1;
    heap_size = A.size() - 1
*/
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

/*
    The iteration version of MAX-HEAPIFY()
*/
/**6.2-5**/
void MAX_HEAPIFY_ITERATION(vector<int>& A, int heap_size, int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int largest = 0;
    while((left <= heap_size && A[largest] < A[left]) || (right <= heap_size && A[largest] < A[right])){
        largest = i;
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
            i = largest;
            left = LEFT(i);
            right = RIGHT(i);
        }
    }
}

/*
    The max heap is stored in A and the index of the root is 1;
    heap_size = A.size() - 1
*/
void BUILD_MAX_HEAP(vector<int>& A, int heap_size){
    for(int i = heap_size / 2; i >= 1; i--){
        MAX_HEAPIFY(A, heap_size, i);
    }
}

/*
    The iteration version of BUILD_MAX_HEAP()
*/
void BUILD_MAX_HEAP_ITERATION(vector<int>& A, int heap_size){
    for(int i = heap_size / 2; i >= 1; i--){
        MAX_HEAPIFY_ITERATION(A, heap_size, i);
    }
}

/*
    The max heap is stored in A and the index of the root is 1
    In ascending order
*/
void HEAPSORT(vector<int>& A){
    int heap_size = A.size() - 1;
    BUILD_MAX_HEAP(A, heap_size);

    for(int i = A.size() - 1; i >= 2; i--){
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        heap_size--;
        MAX_HEAPIFY(A, heap_size, 1);
    }
}

/*
    The iteration version of HEAPSORT()
*/
void HEAPSORT_ITERATION(vector<int>& A){
    int heap_size = A.size() - 1;
    BUILD_MAX_HEAP_ITERATION(A, heap_size);

    for(int i = A.size() - 1; i >= 2; i--){
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        heap_size--;
        MAX_HEAPIFY_ITERATION(A, heap_size, 1);
    }
}

/*
    The min heap is stored in A and the index of the root is 1;
    heap_size = A.size() - 1
*/
/**6.2-2**/
void MIN_HEAPIFY(vector<int>& A, int heap_size, int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int smallest = i;
    if(left <= heap_size && A[smallest] > A[left]){
        smallest = left;
    }
    if(right <= heap_size && A[smallest] > A[right]){
        smallest = right;
    }
    if(smallest != i){
        int tmp = A[i];
        A[i] = A[smallest];
        A[smallest] = tmp;
        MIN_HEAPIFY(A, heap_size, smallest);
    }
}

/*
    The min heap is stored in A and the index of the root is 1;
    heap_size = A.size() - 1
*/
void BUILD_MIN_HEAP(vector<int>& A, int heap_size){
    for(int i = heap_size / 2; i >= 1; i--){
        MIN_HEAPIFY(A, heap_size, i);
    }
}
