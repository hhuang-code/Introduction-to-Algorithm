void INSERTION_SORT(vector<int>& A, int s, int e){
    for(int i = s + 1; i <= e; i++){
        int tmp = A[i];
        int j = i - 1;
        while(j >= s && A[j] > tmp){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
    }
}

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

/*
    Find the j-th element, and the worst time limit is O(n)
*/
int SELECT(vector<int>& A, int s, int e, int i){
    assert(i >= 1 && i <= (int)A.size());

    if(s == e){
        return A[s];
    }else{
        //Divide the array into n/5 groups, and sort each group.
        for(int j = s; j <= e; j += 5){
            if(j + 4 <= e){
                INSERTION_SORT(A, j, j + 4);
            }
        }
        if((e - s + 1) % 5 != 0){
            INSERTION_SORT(A, s + (e - s + 1) / 5 * 5, e);
        }

        //Find the median of every group, and store them into an ancillary array.
        vector<int> B;
        for(int j = s; j <= e; j += 5){
            if(j + 4 <= e){
                B.push_back(A[j + 2]);
            }
        }
        if((e - s + 1) % 5 != 0){
            B.push_back(A[s + ((e - s + 1) / 5 * 5 + (e - s + 1) - 1) / 2]);
        }

        //Find the median of the medians.
        int median = SELECT(B, 0, B.size() - 1, (B.size() + 1) / 2);

        //Partition the array by the median of medians
        int idx = e;
        for(int j = s; j <= e; j++){
            if(A[j] == median){
                idx = j;
                break;
            }
        }
        A[idx] = A[e];
        A[e] = median;
        int m = PARTITION(A, s, e);

        //Call SELECT() recursively if necessary.
        int k = m - s + 1;
        if(i == k){
            return A[m];
        }else if(i < k){
            return SELECT(A, s, m - 1, i);
        }else{
            return SELECT(A, m + 1, e, i - k);
        }
    }
}

/**9.3-5 start**/
int MEDIAN(vector<int> A, int s, int e){
    vector<int> B;
    for(int i = s; i <= e; i++){
        B.push_back(A[i]);
    }
    int median = SELECT(B, 0, B.size() - 1, (B.size() + 1) / 2);

    return median;
}

/*
    Suppose the function MEDIAN() could find the median of an array in time O(n) and return its index.
*/
int SELECT_USING_MEDIAN(vector<int>& A, int s, int e, int i){
    assert(i >= 1 && i <= (int)A.size());

    if(s == e){
        return A[s];
    }else{
        int median = MEDIAN(A, s, e);
        //Partition the array by the median
        int idx = e;
        for(int j = s; j <= e; j++){
            if(A[j] == median){
                idx = j;
                break;
            }
        }
        A[idx] = A[e];
        A[e] = median;
        int m = PARTITION(A, s, e);
        int k = m - s + 1;
        if(i == k){
            return A[m];
        }else if(i < k){
            return SELECT_USING_MEDIAN(A, s, m - 1, i);
        }else{
            return SELECT_USING_MEDIAN(A, m + 1, e, i - k);
        }
    }
}
/**9.3-5 end**/

/**9.3-6 start**/
/*
    Array R is the result.
*/
void QUANTILE(vector<int>& A, vector<int>& R, int s, int e, int k){
    if(k == 1){
        return;
    }else if(k == 2){
        R.push_back(SELECT(A, s, e, (s + e) / 2 - (s - 1)));    //median
        return;
    }else{
        int len = e - s + 1;
        int interval = (len - (k - 1)) / k;
        R.push_back(SELECT(A, s, e, interval * (k / 2) + k / 2 + s));
        QUANTILE(A, R, s, interval * (k / 2) + k / 2 - 2, k / 2);   //left
        QUANTILE(A, R, interval * (k / 2) + k / 2, e, k - k / 2);   //right
    }
}

void QUANTILE_TEST(vector<int>& A, vector<int>& R, int s, int e, int k){
    INSERTION_SORT(A, s, e);
    int len = A.size();
    int interval = (len - (k - 1)) / k;
    for(int i = 1; i < k; i++){
        R.push_back(A[interval * i + (i - 1)]);
    }
}
/**9.3-6 end**/
