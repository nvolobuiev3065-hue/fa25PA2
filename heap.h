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
        data[size-1] = idx;
        upheap(size-1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) return -1;

        int temp;
        temp = weightArr[0];
        weightArr[0] = weightArr[size - 1];
        weightArr[size - 1] = temp;

        downheap(0, weightArr);
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos - 1)/2;
        while (parent > 0) {
            if (weightArr[pos] < weightArr[parent]) {
                swap(data[parent], data[pos]);
            }
            parent = (parent - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int min = 0;
        int firstChild = pos*2 + 1;
        while (firstChild + 1 < 64) {
            if (weightArr[firstChild] <= weightArr[firstChild+1]) {
                if (weightArr[pos] > weightArr[firstChild]) {
                    swap(weightArr[pos], weightArr[firstChild]);
                }
                else {
                    if (weightArr[pos] > weightArr[firstChild+1]) {
                        swap(weightArr[pos], weightArr[firstChild+1]);
                    }
                }
            }
            firstChild = firstChild * 2 + 1;
        }
    }
};

#endif