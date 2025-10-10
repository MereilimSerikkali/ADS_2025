#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MinHeap {
private:
    vector<long long> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapify_up(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify_down(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }

public:
    bool empty() { return heap.empty(); }
    int size() { return heap.size(); }

    void push(long long x) {
        heap.push_back(x);
        heapify_up(heap.size() - 1);
    }

    long long top() {
        return heap[0];
    }

    void pop() {
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }
};

int main() {

    int q, k;
    cin >> q >> k;

    MinHeap heap;
    long long total = 0;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "insert") {
            long long x;
            cin >> x;
            heap.push(x);
            total += x;

            if (heap.size() > k) {
                total -= heap.top();
                heap.pop();
            }
        } 
        else if (cmd == "print") {
            cout << total << "\n";
        }
    }

    return 0;
}