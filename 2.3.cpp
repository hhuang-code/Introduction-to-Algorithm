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

/** Binary search, recursion version**/
/** Suppose the array is in ascending order**/
/*2.3-5*/
int Binary_search_recursion(vector<int> v, int s, int e, int t){
    if(s <= e){
        int mid = (s + e) / 2;
        if(v[mid] == t){
            return mid;
        }else if(v[mid] < t){
            return Binary_search_recursion(v, mid + 1, e, t);
        }else{
            return Binary_search_recursion(v, s, mid - 1, t);
        }
    }else{
        return -1;
    }
}

/** Binary search, iteration version**/
/** Suppose the array is in ascending order**/
/*2.3-5*/
int Binary_search_iteration(vector<int> v, int t){
    int s = 0;
    int e = v.size() - 1;
    int mid = (s + e) / 2;
    while(s <= e){
        if(v[mid] == t){
            return mid;
        }else if(v[mid] < t){
            s = mid + 1;
            mid = (s + e) / 2;
        }else{
            e = mid - 1;
            mid = (s + e) / 2;
        }
    }

    return -1;
}

/**Insertion sort, combined with binary search; ascending order**/
/*2.3-6*/
/*
    Given a number t and an ascending ordered array, find the first number in the array that is larger than t.
    If not found, return (max_index_of_array + 1).
*/
int Binary_search_first_larger(vector<int> v, int s, int e, int t){
    int mid = (s + e) / 2;
    while(s <= e){
        if(v[mid] <= t){
            s = mid + 1;
            mid = (s + e) / 2;
        }else{
            e = mid - 1;
            mid = (s + e) / 2;
        }
    }

    return s;
}

vector<int> INSERTION_SORT_BS(vector<int> v){
    int len = v.size();
    for(int i = 1; i < len; i++){
        int key = v[i];
        int j = Binary_search_first_larger(v, 0, i - 1, key);
        for(int k = i - 1; k >= j; k--){
            v[k + 1] = v[k];
        }
        v[j] = key;
    }

    return v;
}

/*2.3-7*/
bool IS_SUM_EQUAL(set<int> s, int x){
    int size = s.size();
    vector<int> v;
    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        v.push_back(*iter);
    }

    MERGE_SORT(v, 0, size - 1);     //O(nlgn)

    int index = -1;
    for(int i = 0; i < size; i++){
        index = Binary_search_iteration(v, x - v[i]);   //O(n * lgn)
        if(index != -1 && index != i){
            return true;
        }
    }

    return false;
}
