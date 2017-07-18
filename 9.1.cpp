void MAXIMUM_AND_MINIMUM(vector<int> A, int& max, int& min){
    int len = A.size();
    int tmin = A[0];
    int tmax = A[0];
    int s = 1;
    if(len % 2 == 0){
        tmin = (A[0] < A[1] ? A[0] : A[1]);
        tmax = (A[0] > A[1] ? A[0] : A[1]);
        s = 2;
    }
    for(int i = s; i + 1 < len; i += 2){
        if(A[i] > A[i + 1]){
            tmax = (A[i] > tmax ? A[i] : tmax);
            tmin = (A[i + 1] < tmin ? A[i + 1] : tmin);
        }else{
            tmax = (A[i + 1] > tmax ? A[i + 1] : tmax);
            tmin = (A[i] < tmin ? A[i] : tmin);
        }
    }

    max = tmax;
    min = tmin;
}
