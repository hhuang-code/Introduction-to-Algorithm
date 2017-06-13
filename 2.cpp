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
