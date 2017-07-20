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

/*
    Select the i-th element of an array.
*/
int RANDOMIZED_SELECT(vector<int>& A, int s, int e, int i){
    assert(i >= 1 && i <= (int)A.size());

    if(s == e){
        return A[s];
    }else{
        int q = RANDOMIZED_PARTITION(A, s, e);
        int k = q - s + 1;
        if(k == i){
            return A[q];
        }else if(k < i){
            return RANDOMIZED_SELECT(A, q + 1, e, i - k);
        }else{
            return RANDOMIZED_SELECT(A, s, q - 1, i);
        }
    }
}
