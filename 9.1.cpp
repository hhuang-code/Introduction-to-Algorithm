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

/**9.1-1 start**/
/*
    Use two-dimension variable-length vector to emulate a tree.
*/

void NEXT_MINIMUM(vector<int> A, int& next_min){
    assert(A.size() >= 2);

    int n = A.size();
    int depth = ceil(log(n) / log(2)) + 1;

    //Build a tree
    vector< vector<int> > tree;
    tree.push_back(A);
    int i = 1;
    while(i < depth){
        int len = tree[i - 1].size();
        vector<int> T;
        int j = 0;
        for(; j + 1 < len; j += 2){
            int min = (tree[i - 1][j] < tree[i - 1][j + 1] ? tree[i - 1][j] : tree[i - 1][j + 1]);
            T.push_back(min);
        }
        if(j < len){
            T.push_back(tree[i - 1][j]);
        }
        tree.push_back(T);
        i++;
    }

//    for(int i = 0; i < depth; i++){
//        int len = tree[i].size();
//        for(int j = 0; j < len; j++){
//            cout << tree[i][j] << " ";
//        }
//        cout << endl;
//    }

    //Find all elements that has been compared with the minimum element directly.
    vector<int> C;
    int min_idx = 0;
    int cmp_idx = 0;
    int min = tree[depth - 1][0];
    for(int i = depth - 2; i >= 0; i--){
        unsigned idx1 = min_idx * 2;
        unsigned idx2 = min_idx * 2 + 1;
        if(idx2 >= tree[i].size()){
            min_idx = idx1;
        }else{
            cmp_idx = (tree[i][idx1] == min ? idx2 : idx1);
            min_idx = (tree[i][idx1] == min ? idx1 : idx2);
            C.push_back(tree[i][cmp_idx]);
        }
    }

//    for(int i = 0; i < C.size(); i++){
//        cout << C[i] << " ";
//    }
//    cout << endl;

    next_min = C[0];
    for(unsigned i = 1; i < C.size(); i++){
        if(next_min > C[i]){
            next_min = C[i];
        }
    }
}
/**9.1-1 end**/
