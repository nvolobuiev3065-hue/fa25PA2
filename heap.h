//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;
        upheap(size, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) return -1;

        int temp = data[0];
        data[0] = data[size - 1];
        size--;

        downheap(0, weightArr);
        return temp;
        // Replace root with last element, then call downheap()
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos - 1)/2;
        while (pos > 0) {
            parent = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[parent], data[pos]);
                pos = parent;
            }
            else break;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int left, right, small = 0;
        while (true) {
            left = pos * 2 + 1;
            right = pos * 2 + 2;
            small = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[small]]) {
                small = left;
            }

            if (right < size && weightArr[data[right]] < weightArr[data[small]]) {
                small = right;
            }

            if (small != pos) {
                swap(data[pos], data[small]);
                pos = small;
            }

            else break;
        }
    }
};

#endif