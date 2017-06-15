/**Ascending Order**/
/*2-2*/
vector<int> BUBBLE_SORT(vector<int> v){
    int len = v.size();
    for(int i = 0; i < len; i++){
        for(int j = len - 1; j > i; j--){
            if(v[j] < v[j - 1]){
                int tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
            }
        }
    }

    return v;
}

/**Horner's Rule for polynomial evaluation**/
/*2-3*/
double Horner_Rule_Poly(vector<double> A, double x){
    double y = 0.0;
    int n = A.size();
    for(int i = n - 1; i >= 0; i--){
        y = A[i] + y * x;
    }

    return y;
}

/**Naive polynomial evaluation**/
double Naive_Poly(vector<double> A, double x){
    double y = 0.0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        y += A[i] * pow(x, i);
    }

    return y;
}

/** Find inversion pair**/
/*2-4*/
int Merge_find(vector<int>& v, int s, int m, int e){
    int i = 0;
    int j = 0;
    vector<int> lv(m - s + 1, 0);
    vector<int> rv(e - m, 0);

    for(i = 0; i < m - s + 1; i++){
        lv[i] = v[s + i];
    }
    for(j = 0; j < e - m; j++){
        rv[j] = v[m + 1 + j];
    }

    int count = 0;
    int k = s;
    i = j = 0;
    while(i < m - s + 1 && j < e - m){
        if(lv[i] < rv[j]){
            v[k] = lv[i];
            i++;
        }else{
            v[k] = rv[j];
            count += (m - s + 1 - i);
            j++;
        }
        k++;
    }

    for(; i < m - s + 1; i++, k++){
        v[k] = lv[i];
    }

    for(; j < e - m; j++, k++){
        v[k] = rv[j];
    }

    return count;
}

int FIND_INVERSION(vector<int>& v, int s, int e){
    int count = 0;
    if(s < e){
        int m = (s + e) / 2;
        count += FIND_INVERSION(v, s, m);
        count += FIND_INVERSION(v, m + 1, e);
        count += Merge_find(v, s, m, e);
    }

    return count;
}
