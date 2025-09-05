#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    // is the heap empty?
    virtual bool isEmpty() const = 0;//Costs O(1)

    // number of elements in the heap
    virtual int size() = 0; //Costs O(1)

    // add an element to the heap
    virtual void insert(const int x) = 0; //Costs O(1)

    // find the maximum element in the heap
    virtual const int findMax() const = 0; //Costs O(1)

    // delete and return the maximum element of the heap
    virtual int deleteMax() = 0; //Costs O(1)

    virtual ~MaxHeap() = default; //Costs O(1)
};

// Implementation

class VectorMaxHeap : public MaxHeap {
private: 
    // Initialize vector
    vector<int> data; //Costs O(1)

public:
    // is the heap empty?
    bool isEmpty() const override 
    {
        if (data.empty()) { //Costs O(N) best case
             cout << "The MaxHeap is empty \n";//Costs O(1)
        }
        else //Costs O(N²) worst case.
            cout << "The maxheap is not empty \n"; //Costs O(1)
        return data.empty(); //Costs O(1)
    };

    // number of elements in the heap
    int size() override {
        cout << "The size of the MaxHeap is: " << data.size() << "\n"; //Costs O(1)
        return data.size(); //Costs O(1)
    }

    // add an element to the heap
    void insert(const int x) override {
        data.push_back(x); //Costs O(1)
        cout << "Inserted value: " << x << "\n"; //Costs O(1)
    }

    // find the maximum element in the heap
    const int findMax() const override {
        if (isEmpty()) throw runtime_error("empty heap"); 
        auto it  = max_element(data.begin(), data.end());   // iterator to max //Costs O(1)
        int idx  = static_cast<int>(distance(data.begin(), it)); //Costs O(1)
        int val  = *it; //Costs O(1) 
        cout << "[findMax] Max value " << val << " at index " << idx << "\n"; //Costs O(1)
        return val; //Costs O(1)
    }

    int deleteMax() override {
        if (isEmpty()) throw runtime_error("empty heap");
        auto it  = max_element(data.begin(), data.end());   // iterator to max //Costs O(1)
        int idx  = static_cast<int>(distance(data.begin(), it)); //Costs O(1)
        int val  = *it; //Costs O(1)
        cout << "[deleteMax] Removing value " << val << " at index " << idx << "\n"; //Costs O(1)
        data.erase(it); //Costs O(1)
        cout << "[deleteMax] Size after erase: " << data.size() << "\n"; //Costs O(1)
        return val; //Costs O(1)
    }
};

int main() {
    VectorMaxHeap heap;
    heap.insert(1);   //Costs O(1)
    heap.insert(2);     //Costs O(1)
    heap.insert(10);  //Costs O(1)
    heap.isEmpty();   //Costs O(1)
    heap.size();     //Costs O(1)
    heap.findMax(); //Costs O(1)
    heap.deleteMax(); //Costs O(1)
    heap.findMax(); //Costs O(1)
    return 0; //Costs O(1)
}
//Total complexity = O(N²) + 34*O(1)