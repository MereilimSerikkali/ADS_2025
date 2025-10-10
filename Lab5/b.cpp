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
    int n;
    cin >> n;

    MaxHeap heap;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
    }

    while (heap.size() > 1) {
        int y = heap.top(); heap.pop();  // heaviest
        int x = heap.top(); heap.pop();  // second heaviest

        if (y != x) {
            heap.push(y - x);
        }
    }

    cout << (heap.empty() ? 0 : heap.top()) << endl;
    return 0;
}