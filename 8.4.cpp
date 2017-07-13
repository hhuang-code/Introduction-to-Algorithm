struct Node{
    float x;
    Node* ptr;
};

/*
    linked list version of insertion sort
*/
Node* INSERTION_SORT(Node* header){
    assert(header != NULL);

    Node* cur = header->ptr;
    Node* pre = NULL;
    Node* next = NULL;
    while(cur != NULL){
        Node* sp = header;
        while(sp != cur && sp->x <= cur->x){
            sp = sp->ptr;
        }
        if(sp->x > cur->x){
            next = cur->ptr;
            pre = header;
            while(pre->ptr != cur){
                pre = pre->ptr;
            }
            pre->ptr = next;
            cur->ptr = sp;
            if(sp == header){
                header = cur;
            }else{
                pre = header;
                while(pre->ptr != sp){
                    pre = pre->ptr;
                }
                pre->ptr = cur;
            }
            cur = next;
        }
        if(sp == cur){
            cur = cur->ptr;
        }
    }

    return header;
}

void BUCKET_SORT(vector<float>& A){
    int n = A.size();
    vector<Node*> B(n);

    for(int i = 0; i < n; i++){
        B[i] = NULL;
    }

    float interval = 1.0 / n;
    for(int i = 0; i < n; i++){
        int idx = floor(A[i] / interval);
        Node* p = new Node();
        p->x = A[i];
        p->ptr = NULL;
        if(B[idx] == NULL){
            B[idx] = p;
        }else{
            Node* last = B[idx];
            while(last->ptr != NULL){
                last = last->ptr;
            }
            last->ptr = p;
        }
    }

    for(int i = 0; i < n; i++){
        if(B[i] != NULL){
            B[i] = INSERTION_SORT(B[i]);
        }
    }

    int k = 0;
    for(int i = 0; i < n; i++){
        if(B[i] != NULL){
            Node* cur = B[i];
            while(cur != NULL){
                A[k] = cur->x;
                cur = cur->ptr;
                k++;
            }
        }
    }
}

/*
    Output a linked list.
*/
void DISPLAY(Node* header){
    Node* cur = header;
    while(cur){
        cout << cur->x << " ";
        cur = cur->ptr;
    }
    cout << endl;
}
