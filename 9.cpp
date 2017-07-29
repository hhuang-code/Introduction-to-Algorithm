/**9-1 start**/
/*
    a) Use merge sort or heap sort, the worst time is O(n * lg(n)); The time of listing the first i-th large element
       is O(i); So the total time is O(n * lg(n) + i)
    b) The time of building a heap is O(n), and the time of EXTRACT-MAX() is O(lg(n)), so the total time is O(n + i * lg(n))
    c) The time of SELECT() is O(n), and the time of partition the array is O(n); The worst time of sorting the first
       i-th elements is O(i * lg(i)); So the total time is O(n + i * lg(i))
*/
/**9-1 end**/

/**9-2 start**/
class Node{
public:
    Node(int v, float w): value(v), weight(w){};
    int get_value();
    float get_weight();
    void set_value(int v);
    void set_weight(float w);
    Node& operator=(const Node& node);
private:
    int value;
    float weight;
};

int Node::get_value(){
    return value;
}

float Node::get_weight(){
    return weight;
}

void Node::set_value(int v){
    value = v;
}

void Node::set_weight(float w){
    weight = w;
}

Node& Node::operator=(const Node& node){
    if(this != &node){
        this->value = node.value;
        this->weight = node.weight;
    }

    return *this;
}
/*
    Generate an array with different elements.
*/
void RANDOM_ARRAY_NOREPEAT(vector<int>& A, int n){
    assert(n >= 1);
    vector<int> hashtable(n);
    for(int i = 0; i < n; i++){
        hashtable[i] = 0;
    }
    srand((unsigned)time(0));
    for(int i = 0; i < n; i++){
        int t = rand() % n;
        while(hashtable[t]){
            t = rand() % n;
        }
        A.push_back(t);
        hashtable[t] = 1;
    }
}

/*
    Generate an weighted array.
*/
vector<Node*> GENERATE_ARRAY(int n){
    assert(n >= 1);

    //Generate weight array
    vector<float> W;
    float sum = 0.0;
    srand((unsigned)time(0));
    for(int i = 0; i < n; i++){
        int w = rand() % n + 1;     //To ensure the weight will be positive
        sum += (float)w;
        W.push_back((float)w);
    }
    for(int i = 0; i < n; i++){
        W[i] /= sum;
    }

    //Generate value array
    vector<int> V;
    RANDOM_ARRAY_NOREPEAT(V, n);

    //Combine the weight and value
    vector<Node*> A;
    for(int i = 0; i < n; i++){
        Node* node = new Node(V[i], W[i]);
        A.push_back(node);
    }

    return A;
}

void DISPLAY(vector<Node*> A){
    int len = A.size();
    cout << "value \t weight" << endl;
    for(int i = 0; i < len; i++){
        cout << A[i]->get_value() << "\t" << A[i]->get_weight() << endl;
    }
}
/*
    b) Use heap sort to solve this problem
*/
int LEFT(int i){
    return 2 * i + 1;
}

int RIGHT(int i){
    return 2 * i + 2;
}

void MAX_HEAPIFY(vector<Node*>& A, int heap_size, int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int largest = i;
    if(left <= heap_size && A[largest]->get_value() < A[left]->get_value()){
        largest = left;
    }
    if(right <= heap_size && A[largest]->get_value() < A[right]->get_value()){
        largest = right;
    }
    if(largest != i){
        Node* tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        MAX_HEAPIFY(A, heap_size, largest);
    }
}

void BUILD_MAX_HEAP(vector<Node*>& A, int heap_size){
    for(int i = (heap_size - 1) / 2; i >= 0; i--){
        MAX_HEAPIFY(A, heap_size, i);
    }
}

void HEAPSORT(vector<Node*>& A){
    int heap_size = A.size() - 1;
    BUILD_MAX_HEAP(A, heap_size);

    float sum_weight = 1.0;
    bool found = false;
    for(int i = A.size() - 1; i >= 1; i--){
        sum_weight -= (A[0]->get_weight());
        if(sum_weight < 0.5 && !found){
            cout << "median value: " << A[0]->get_value() << " median weight: " << A[0]->get_weight() << endl;
            found = true;
        }
        Node* tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        heap_size--;
        MAX_HEAPIFY(A, heap_size, 0);
    }
}

/*
    c) Use SELECT() function to solve this problem.
*/
void INSERTION_SORT(vector<Node*>& A, int s, int e){
    for(int i = s + 1; i <= e; i++){
        Node* tmp = A[i];
        int j = i - 1;
        while(j >= s && A[j]->get_value() > tmp->get_value()){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
    }
}

int PARTITION(vector<Node*>& A, int s, int e, float& sum_weight){
    Node* x = A[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(A[j]->get_value() < x->get_value()){
            i++;
            sum_weight += (A[j]->get_weight());
            Node* tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }
    A[e] = A[i + 1];
    A[i + 1] = x;   //pivot

    return i + 1;
}

//Return the pointer to the median.
Node* SELECT(vector<Node*>& A, int s, int e, float median_weight){
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
        vector<Node*> B;
        for(int j = s; j <= e; j += 5){
            if(j + 4 <= e){
                B.push_back(A[j + 2]);
            }
        }
        if((e - s + 1) % 5 != 0){
            B.push_back(A[s + ((e - s + 1) / 5 * 5 + (e - s + 1) - 1) / 2]);
        }

        //Find the middle element of the medians.
        Node* median = B[(B.size() - 1) / 2];

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
        float sum_weight = 0.0;
        int m = PARTITION(A, s, e, sum_weight);

        //Call SELECT() recursively if necessary.
        if(sum_weight < median_weight && sum_weight + A[m]->get_weight() >= median_weight){
            return A[m];
        }else if(sum_weight >= median_weight){
            return SELECT(A, s, m - 1, median_weight);
        }else{
            return SELECT(A, m + 1, e, median_weight - sum_weight - A[m]->get_weight());
        }
    }
}
/**9-2 end**/
