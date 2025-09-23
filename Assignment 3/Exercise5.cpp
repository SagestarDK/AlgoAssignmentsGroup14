// ============================================================================
// Exercise 5 – List ADT: recursive search(x)   (SKELETON ONLY)
// Goal:
//   Add int search(const T& x) that returns the index of x (or -1 if absent)
//   using RECURSION. No loops in the core search logic.
//
// Conventions (adjust if your ADT differs):
//   • 0-based indexing is used for the return value.
//   • Equality uses operator== on T.
//   • Complexity to state in write-up:
//       Time (worst):  Θ(n)  via T(n)=T(n-1)+Θ(1)
//       Space:         Θ(n)  recursion depth
// ============================================================================

#include <cstddef>  // std::size_t
#include <stdexcept>

template <typename T>
class List {
public:
    // ---------- public API already in Week 3 (examples; keep whatever you have) ----------
    List();
    ~List();
    // void push_back(const T& value);
    // void push_front(const T& value);
    // std::size_t size() const;
    // bool empty() const;

    // ---------- NEW: recursive search ----------
    // Returns the index of the first occurrence of x, or -1 if not found.
    // Must be implemented using recursion (no loops in the core algorithm).
    int search(const T& x) const;

private:
    // ---------- node definition ----------
    struct Node {
        T data;
        Node* next;
        // Node(const T& d, Node* n=nullptr) : data(d), next(n) {}
    };

    Node* head_ = nullptr;
    std::size_t size_ = 0;

    // ---------- recursive helper ----------
    // Recursively search starting at node 'cur' with current index 'idx'.
    // Return index if found, else -1.
    // Base cases & recursive step are to be filled by you.
    static int search_rec(const Node* cur, const T& x, int idx);
};

// ========================== STUBS (fill TODOs only) =========================

// public entry
template <typename T>
int List<T>::search(const T& x) const {
    // TODO: delegate to helper starting at head_ with idx = 0
    // NOTE: no loops here.
    (void)x; // remove after implementing
    return -1; // placeholder
}

// private helper
template <typename T>
int List<T>::search_rec(const Node* cur, const T& x, int idx) {
    // TODO: Base case 1: cur == nullptr  -> not found
    // TODO: Base case 2: cur->data == x  -> return idx
    // TODO: Recursive case: move to next node with idx+1
    (void)cur; (void)x; (void)idx; // remove after implementing
    return -1; // placeholder
}

// ============================== QUICK CHECKS ================================
// After implementing, try simple tests (or your unit framework):
//
// int main() {
//     List<int> L;
//     // L.push_back(10); L.push_back(20); L.push_back(30);
//     // assert(L.search(10) == 0);
//     // assert(L.search(30) == 2);
//     // assert(L.search(99) == -1);
//     return 0;
// }
// ============================================================================

