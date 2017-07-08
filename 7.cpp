/**7-1 start**/
int HOARE_PARTITION(vector<int>& A, int s, int e){
    int x = A[s];
    int i = s - 1;
    int j = e + 1;
    while(true){
        do{
            j--;
        }while(A[j] > x);
        do{
            i++;
        }while(A[i] <= x);
        if(i < j){
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }else{
            A[s] = A[j];
            A[j] = x;
            return j;
        }
    }
}

void QUICKSORT(vector<int>& A, int s, int e){
    if(s < e){
        int m = HOARE_PARTITION(A, s, e);
        QUICKSORT(A, s, m - 1);
        QUICKSORT(A, m + 1, e);
    }
}
/**7-1 end**/

/**7-3 start**/
void STOOGE_SORT(vector<int>& A, int i, int j){
    if(A[i] > A[j]){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
    if(i + 1 >= j){
        return;
    }

    int k = (j - i + 1) / 3;
    STOOGE_SORT(A, i, j - k);
    STOOGE_SORT(A, i + k, j);
    STOOGE_SORT(A, i, j - k);
}
/**7-3 end**/

/**7-4 start**/
int PARTITION(vector<int>& A, int s, int e){
    int x = A[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(A[j] < x){
            i++;
            int tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }
    A[e] = A[i + 1];
    A[i + 1] = x;

    return i + 1;
}

void QUICKSORT_ALT(vector<int>& A, int s, int e){
    while(s < e){
        int m = PARTITION(A, s, e);
        QUICKSORT_ALT(A, s, m - 1);
        s = m + 1;
    }
}

/*
    Get the index of the median.
*/
int GET_MEDIAN_INDEX(vector<int>& A, int s, int e){
    int mid = (s + e) / 2;
    int idx = -1;
    while(idx != mid){
        idx = PARTITION(A, s, e);
        if(idx == mid){
            return idx;
        }else if(idx < mid){
            s = idx + 1;
        }else{
            e = idx - 1;
        }
    }
}

void QUICKSORT_REVISED(vector<int>& A, int s, int e){
    while(s < e){
        int m = GET_MEDIAN_INDEX(A, s, e);
        QUICKSORT_REVISED(A, s, m - 1);
        s = m + 1;
    }
}
/**7-4 end**/

/**7-5 start**/
int PARTITION(vector<int>& A, int s, int e){
    int x = A[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(A[j] < x){
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    A[e] = A[i + 1];
    A[i + 1] = x;

    return i + 1;
}

/*
    Select three elements randomly, and choose the median as the pivot.
*/
int RANDOMIZED_PARTITION_REVISED(vector<int>& A, int s, int e){
    int i = -1;
    if(s - e + 1 >= 3){
        srand((unsigned)time(0));
        int idx1 = s + rand() % (e - s + 1);
        int idx2 = s + rand() % (e - s + 1);
        while(idx2 == idx1){
            idx2 = s + rand() % (e - s + 1);
        }
        int idx3 = s + rand() % (e - s + 1);
        while(idx3 == idx1 && idx3 == idx2){
            idx3 = s + rand() % (e - s + 1);
        }

        if(A[idx1] < A[idx2]){
            if(A[idx2] < A[idx3]){
                i = idx2;
            }else{
                if(A[idx1] < A[idx3]){
                    i = idx3;
                }else{
                    i = idx1;
                }
            }
        }else{
            if(A[idx1] < A[idx3]){
                i = idx1;
            }else{
                if(A[idx2] < A[idx3]){
                    i = idx3;
                }else{
                    i = idx2;
                }
            }
        }
    }else{
        i = s + rand() % (e - s + 1);
    }

    int tmp = A[i];
    A[i] = A[e];
    A[e] = tmp;

    return PARTITION(A, s, e);
}

void RANDOMIZED_QUICKSORT_REVISED(vector<int>& A, int s, int e){
    if(s < e){
        int m = RANDOMIZED_PARTITION_REVISED(A, s, e);
        RANDOMIZED_QUICKSORT_REVISED(A, s, m - 1);
        RANDOMIZED_QUICKSORT_REVISED(A, m + 1, e);
    }
}
/**7-5 end**/

/**7-6 start**/
struct closed_interval{
    int left;
    int right;
};

bool IS_OVERLAP(closed_interval x, closed_interval y){
    if(x.right < y.left || x.left > y.right){
        return false;
    }else{
        return true;
    }
}

closed_interval GET_OEVRLAP(closed_interval x, closed_interval y){
    closed_interval ci;
    ci.left = (x.left >= y.left ? x.left : y.left);
    ci.right = (x.right <= y.right ? x.right : y.right);

    return ci;
}

int INTERVAL_PARTITION(vector<closed_interval>& A, int s, int e){
    closed_interval x = A[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(A[j].left < x.left){
            i++;
            closed_interval tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }
    A[e] = A[i + 1];
    A[i + 1] = x;

    return i + 1;
}

void INTERVAL_QUICKSORT(vector<closed_interval>& A, int s, int e){
    if(s < e){
        int m = INTERVAL_PARTITION(A, s, e);

        bool is_overlap = true;
        closed_interval overlap = A[m - 1];
        for(int i = m - 1; i >= s; i++){
            if(IS_OVERLAP(overlap, A[i])){
                overlap = GET_OEVRLAP(overlap, A[i]);
            }else{
                is_overlap = false;
                break;
            }
        }
        if(!is_overlap){
            INTERVAL_QUICKSORT(A, s, m - 1);
        }

        is_overlap = false;
        overlap = A[m + 1];
        for(int i = m + 1; i <= e; i++){
            if(IS_OVERLAP(overlap, A[i])){
                overlap = GET_OEVRLAP(overlap, A[i]);
            }else{
                is_overlap = false;
                break;
            }
        }
        if(!is_overlap){
            INTERVAL_QUICKSORT(A, m + 1, e);
        }
    }
}

void DISPLAY(vector<closed_interval>& A, int s, int e){
    for(int i = s; i <= e; i++){
        cout << "[" << A[i].left << " , " << A[i].right << "]" << endl;
    }
}
/**7-6 end**/
