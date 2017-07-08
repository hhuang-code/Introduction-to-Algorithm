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
