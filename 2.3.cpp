/**Ascending Order**/
void MERGE(vector<int>& v, int p, int q, int r){
    int i = 0;
    int j = 0;
    vector<int> lv(q - p + 1, 0);
    vector<int> rv(r - q, 0);

    for(j = 0, i = p; i <= q; i++, j++){
        lv[j] = v[i];
    }
    for(j = 0, i = q + 1; i <= r; i++, j++){
        rv[j] = v[i];
    }

    i = 0;
    j = 0;
    int k = p;
    while(i < q - p + 1 && j < r - q){
        if(lv[i] < rv[j]){
            v[k] = lv[i];
            i++;
        }else{
            v[k] = rv[j];
            j++;
        }
        k++;
    }
    for(; i < q - p + 1; i++, k++){
        v[k] = lv[i];
    }
    for(; j < r - q; j++, k++){
        v[k] = rv[j];
    }
}

void MERGE_SORT(vector<int>& v, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        MERGE_SORT(v, p, q);
        MERGE_SORT(v, q + 1, r);
        MERGE(v, p, q, r);
    }
}

/**Insertion sort, ascending order, recursion version**/
/*2.3-4*/
void INSERTION(vector<int>& v, int s, int e, int n){
    for(int i = s; i <= e; i++){
        if(v[i] > v[n]){
            int tmp = v[i];
            v[i] = v[n];
            v[n] = tmp;
        }
    }
}

void INSERTION_SORT_RECURSION(vector<int>& v, int s, int e){
    if(s < e){
        INSERTION_SORT_RECURSION(v, s, e - 1);
        INSERTION(v, s, e - 1, e);
    }
}
