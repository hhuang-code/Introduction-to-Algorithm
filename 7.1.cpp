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

int PARTITION_ALT(vector<int>& A, int s, int e){
    int x = A[e];
    int i = s;
    int j = e;
    while(i < j){
        while(A[i] < x){
            i++;
        }
        while(A[j] >= x){
            j--;
        }
        if(i < j){
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    A[e] = A[i];
    A[i] = x;

    return i;
}

/**7.1-4**/
int PARTITION_NOT_INCREASE(vector<int>& A, int s, int e){
    int x = A[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(A[j] >= x){
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

void QUICKSORT(vector<int>& A, int s, int e){
    if(s < e){
        int m = PARTITION(A, s, e); // or PARTITION_ALT(A, s, e)
        QUICKSORT(A, s, m - 1);
        QUICKSORT(A, m + 1, e);
    }
}
