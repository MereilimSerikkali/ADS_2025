#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapify_up(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify_down(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    bool empty() { return heap.empty(); }
    int size() { return heap.size(); }

    void push(int x) {
        heap.push_back(x);
        heapify_up(heap.size() - 1);
    }

    int top() {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    MaxHeap heap;
    for (int i = 0; i < n; i++) {
        int seats;
        cin >> seats;
        heap.push(seats);
    }

    long long total = 0;

    for (int i = 0; i < m; i++) {
        int topRow = heap.top();  // highest ticket price (most seats)
        heap.pop();

        total += topRow;          // sell ticket at this price
        if (topRow - 1 > 0)
            heap.push(topRow - 1);  // update row after one seat sold
    }

    cout << total << "\n";
    return 0;
}