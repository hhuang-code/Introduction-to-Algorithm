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

int RANDOMIZED_PARTITION(vector<int>& A, int s, int e){
    srand((unsigned)time(0));
    int i = s + rand() % (e - s + 1);
    int tmp = A[i];
    A[i] = A[e];
    A[e] = tmp;

    return PARTITION(A, s, e);
}

void RANDOMIZED_QUICKSORT(vector<int>& A, int s, int e){
    if(s < e){
        int m = RANDOMIZED_PARTITION(A, s, e);
        RANDOMIZED_QUICKSORT(A, s, m - 1);
        RANDOMIZED_QUICKSORT(A, m + 1, e);
    }
}
