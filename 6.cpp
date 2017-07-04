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

int LEFT(int col){
    return col - 1;
}

int BOTTOM(int row){
    return row + 1;
}

int TOP(int row){
    return row - 1;
}

/*
    Make the element Y[sr][sc] to be the minimum element.
    The size of Y is sr...m and sc...n
*/
void MIN_TABLEAU(int** Y, int m, int n, int sr, int sc){
    int right = RIGHT(sc);
    int bottom = BOTTOM(sr);
    int min_row = sr;
    int min_col = sc;
    if(right < n && Y[sr][right] < Y[min_row][min_col]){
        min_row = sr;
        min_col = right;
    }
    if(bottom < m && Y[bottom][sc] < Y[min_row][min_col]){
        min_row = bottom;
        min_col = sc;
    }
    if(min_row != sr || min_col != sc){
        int tmp = Y[sr][sc];
        Y[sr][sc] = Y[min_row][min_col];
        Y[min_row][min_col] = tmp;
        MIN_TABLEAU(Y, m, n, min_row, min_col);
    }
}

void BUILD_YOUNG_TABLEAU(int** Y, int m, int n){
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(Y[i][j] != INT_MAX){
                MIN_TABLEAU(Y, m, n, i, j);
            }
        }
    }
}

int EXTRACT_MIN(int**Y, int m, int n){
    int min = Y[0][0];
    if(min == INT_MAX){
        return min;
    }

    int r = m - 1;
    int c = n - 1;
    bool found = false;
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(Y[i][j] != INT_MAX){
                r = i;
                c = j;
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }

    Y[0][0] = Y[r][c];
    Y[r][c] = INT_MAX;
    MIN_TABLEAU(Y, m, n, 0, 0);

    return min;
}

/*
    Insert x into the tableau.
*/
void INSERT_TABLEAU(int** Y, int m, int n, int x){
    assert(Y[m - 1][n - 1] == INT_MAX);

    int r = m - 1;
    int c = n - 1;
    bool found = false;
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(Y[i][j] != INT_MAX){
                r = i;
                c = j;
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
    r = r + (c + 1) / n;
    c = (c + 1) % n;
    Y[r][c] = x;

    int left = LEFT(c);
    int top = TOP(r);
    int max_row = r;
    int max_col = c;
    while(left >= 0 || top >= 0){
        int left_value = INT_MIN;
        int top_value = INT_MIN;
        if(left >= 0){
            left_value = Y[r][left];
        }
        if(top >= 0){
            top_value = Y[top][c];
        }

        int largest = Y[r][c];
        if(largest < left_value){
            max_row = r;
            max_col = left;
            largest = left_value;
        }
        if(largest < top_value){
            max_row = top;
            max_col = c;
            largest = top_value;
        }
        if(max_row != r || max_col != c){
            int tmp = Y[r][c];
            Y[r][c] = Y[max_row][max_col];
            Y[max_row][max_col] = tmp;
            r = max_row;
            c = max_col;
            left = LEFT(c);
            top = TOP(r);
        }else{
            break;
        }
    }
}

/*
    Sort n * n element by Young tableau.
*/
void YOUNG_TABLEAU_SORT(vector<int>& A){
    int size = A.size();
    assert(size == (int)sqrt(size) * (int)sqrt(size));

    int n = sqrt(size);
    int** Y;
    Y = new int*[n];
    for(int i = 0; i < n; i++){
        Y[i] = new int[n];
    }

    for(int i = 0; i < size; i++){
        Y[i / n][i % n] = A[i];
    }

    BUILD_YOUNG_TABLEAU(Y, n, n);

    int cur = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            A[cur] = Y[0][0];
            Y[0][0] = Y[i][j];
            Y[i][j] = INT_MAX;
            MIN_TABLEAU(Y, n, n, 0, 0);
            cur++;
        }
    }
}

bool FIND_IN_TABLEAU(int** Y, int m, int n, int x){
    int r = 0;
    int c = n - 1;
    while(r <= m - 1&& c >= 0){
        if(Y[r][c] == x){
            return true;
        }else if(Y[r][c] > x){
            c--;
        }else{
            r++;
        }
    }

    return false;
}
/**6-3 end*/
