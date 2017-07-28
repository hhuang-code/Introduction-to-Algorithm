/**9-1 start**/
/*
    a) Use merge sort or heap sort, the worst time is O(n * lg(n)); The time of listing the first i-th large element
       is O(i); So the total time is O(n * lg(n) + i)
    b) The time of building a heap is O(n), and the time of EXTRACT-MAX() is O(lg(n)), so the total time is O(n + i * lg(n))
    c) The time of SELECT() is O(n), and the time of partition the array is O(n); The worst time of sorting the first
       i-th elements is O(i * lg(i)); So the total time is O(n + i * lg(i))
*/
/**9-1 end**/
