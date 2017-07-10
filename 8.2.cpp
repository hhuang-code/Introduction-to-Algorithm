/*
    S is the source array, and D is the result array.
    All elements in S are non-negative integers.
*/
void COUNTING_SORT(vector<int> S, vector<int>& D){
    int max = S[0];
    int len = S.size();
    for(int i = 1; i < len; i++){
        if(max < S[i]){
            max = S[i];
        }
    }

    vector<int> T(max + 1);
    for(int i = 0; i <= max; i++){
        T[i] = 0;
    }

    for(int i = 0; i < len; i++){
        T[S[i]]++;
    }

    for(int i = 1; i <= max; i++){
        T[i] = T[i] + T[i - 1];
    }

    for(int i = len - 1; i >= 0; i--){  // to keep relative order between elements
        D[T[S[i]] - 1] = S[i];
        T[S[i]] = T[S[i]] - 1;
    }
}

/**8.2-4 start**/
int GET_COUNT(vector<int> A, int left_bound, int right_bound){
    assert(right_bound >= left_bound);

    int max = A[0];
    int len = A.size();
    for(int i = 1; i < len; i++){
        if(max < A[i]){
            max = A[i];
        }
    }

    vector<int> T(max + 1);
    for(int i = 0; i <= max; i++){
        T[i] = 0;
    }

    for(int i = 0; i < len; i++){
        T[A[i]]++;
    }

    for(int i = 1; i <= max; i++){
        T[i] = T[i] + T[i - 1];
    }

    if(left_bound > max){
        return 0;
    }else if(right_bound < 0){
        return 0;
    }else{
        left_bound = (left_bound > 0 ? left_bound : 0);
        right_bound = (right_bound < max ? right_bound : max);
        return left_bound == 0 ? T[right_bound] : T[right_bound] - T[left_bound - 1];
    }
}
/**8.2-4 end**/
