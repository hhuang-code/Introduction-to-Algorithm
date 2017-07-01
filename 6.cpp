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

/**6-2 start**/
// k-th child of i-th element
int CHILD(int i, int d, int k){
    return d * (i - 1) + k + 1;
}

int PARENT(int i, int d){
    return (i - 2) / d + 1;
}

void MAX_HEAPIFY(vector<int>& A, int d, int heap_size, int i){
    int largest = i;
    for(int k = 1; k <= d; k++){
        if(CHILD(i, d, k) <= heap_size){
            if(A[largest] < A[CHILD(i, d, k)]){
                largest = CHILD(i, d, k);
            }
        }else{
            break;
        }
    }

    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        MAX_HEAPIFY(A, d, heap_size, largest);
    }
}

void BUILD_MAX_HEAP(vector<int>& A, int d, int heap_size){
    for(int i = (heap_size - 2) / d + 1; i >= 1; i--){
        MAX_HEAPIFY(A, d, heap_size, i);
    }
}

int EXTRACT_MAX(vector<int>& A, int d, int& heap_size){
    assert(heap_size >= 1);

    int max = A[1];
    A[1] = A[heap_size];
    A.pop_back();
    heap_size--;
    MAX_HEAPIFY(A, d, heap_size, 1);

    return max;
}

/*
    Increase the i-th value to k
*/
void INCREASET_KEY(vector<int>& A, int d, int i, int k){
    A[i] = max(A[i], k);

    while(i > 1 && A[PARENT(i, d)] < A[i]){
        int tmp = A[i];
        A[i] = A[PARENT(i, d)];
        A[PARENT(i, d)] = tmp;
        i = PARENT(i, d);
    }
}
/**6-2 end*/

/**6-3 start**/
/*
    The tableau has m rows and n columns.
*/
int RIGHT(int col){
    return col + 1;
}

int BOTTOM(int row){
    return row + 1；
}

void BUILD_YOUNG_TABLEAU(int** Y, int m, int n){
    int r = m - 1;
    int c = n - 1;
    bool empty = true;
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(Y[i][j] != INT_MAX){
                r = i;
                c = j;
                empty = false;
                break;
            }
        }
        if(!empty){
            break;
        }
    }


}
/**6-3 end*/
