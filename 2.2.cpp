/**Ascending Order**/
/*2.2-2*/
vector<int> SELECTION_SORT(vector<int> v){
    int len = v.size();
    for(int i = 0; i < len - 1; i++){
        int k = i;
        int min = v[k];
        for(int j = i; j < len; j++){
            if(v[j] < min){
                k = j;
                min = v[k];
            }
        }
        if(k != i){
            v[k] = v[i];
            v[i] = min;
        }
    }

    return v;
}

/**Descending Order**/
/*2.2-2*/
vector<int> SELECTION_SORT_DESC(vector<int> v){
    int len = v.size();
    for(int i = 0; i < len - 1; i++){
        int k = i;
        int max = v[k];
        for(int j = i; j < len; j++){
            if(v[j] > max){
                k = j;
                max = v[k];
            }
        }
        if(k != i){
            v[k] = v[i];
            v[i] = max;
        }
    }

    return v;
}
