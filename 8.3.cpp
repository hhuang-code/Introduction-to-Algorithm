/*
    Get the i-th digit of x.
    e.g. The first digit of 100 is 0, the second is 0, the third is 1.
*/
int GET_DIGIT(int x, int i){
    int r = x / pow(10, i - 1);

    return r % 10;
}

/*
    Get the digits number of x.
    e.g. GET_DIGITS_NUM(24680) returns 5.
*/
int GET_DIGITS_NUM(int x){
    int d = 1;
    while(x / 10){
        d++;
        x /= 10;
    }

    return d;
}

/*
    A stable sort(counting sort) to sort array S on digit i
*/
vector<int> COUNTING_SORT(vector<int> S, int i){
    int len = S.size();
    vector<int> D(len);
    for(int k = 0; k < len; k++){
        D[k] = GET_DIGIT(S[k], i);
    }

    int max = D[0];
    for(int k = 1; k < len; k++){
        if(max < D[k]){
            max = D[k];
        }
    }

    vector<int> T(max + 1);
    for(int k = 0; k <= max; k++){
        T[k] = 0;
    }

    for(int k = 0; k < len; k++){
        T[D[k]]++;
    }

    for(int k = 1; k <= max; k++){
        T[k] = T[k] + T[k - 1];
    }

    vector<int> R(len);
    for(int k = len - 1; k >= 0; k--){  // to keep relative order between elements
        R[T[D[k]] - 1] = S[k];
        T[D[k]] = T[D[k]] - 1;
    }

    return R;
}

void RADIX_SORT(vector<int>& A){
    int d = 1;
    int len = A.size();
    for(int i = 0; i < len; i++){      //get the maximum d
        if(GET_DIGITS_NUM(A[i]) > d){
            d = GET_DIGITS_NUM(A[i]);
        }
    }

    for(int i = 1; i <= d; i++){
        A = COUNTING_SORT(A, i);    //COUNTING_SORT is stable
    }
}
