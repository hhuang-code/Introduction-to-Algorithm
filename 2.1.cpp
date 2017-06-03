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
