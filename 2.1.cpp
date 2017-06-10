/**Ascending Order**/
vector<int> INSERTION_SORT(vector<int> v){
    int len = v.size();
    for(int i = 1; i < len; i++){
        int tmp = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > tmp){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = tmp;
    }

    return v;
}

/**Descending Order**/
/*2.1-2*/
vector<int> INSERTION_SORT_DESC(vector<int> v){
    int len = v.size();
    for(int i = 1; i < len; i++){
        int tmp = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] < tmp){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = tmp;
    }

    return v;
}

/**Array Addition**/
/*2.1-4*/
vector<int> Array_Addition(vector<int> A, vector<int> B){
    int alen = A.size();
    int blen = B.size();
    int clen = alen > blen ? alen : blen;
    vector<int> C(clen + 1, 0);

    int carry = 0;
    int i = A.size() - 1;
    int j = B.size() - 1;
    int k = C.size() - 1;
    for(; i >= 0 && j >= 0; i--, j--, k--){
        C[k] = (A[i] + B[j] + carry) % 10;
        carry = (A[i] + B[j] + carry) / 10;
    }
    if(i < 0){
        for(; j >= 0; j--, k--){
            C[k] = (B[j] + carry) % 10;
            carry = (B[j] + carry) / 10;
        }
    }
    if(j < 0){
        for(; i >= 0; i--, k--){
            C[k] = (A[i] + carry) % 10;
            carry = (A[i] + carry) / 10;
        }
    }
    for(; k >= 0; k--){
        C[k] = carry % 10;
        carry /= 10;
    }

    return C;
}
