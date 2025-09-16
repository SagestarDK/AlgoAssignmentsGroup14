#include "list.h"

int main() {
    List<int> numbers;
    numbers.push_front(1);
    numbers.push_front(3);
    numbers.push_front(5);
    numbers.push_back(2);
    numbers.insert_kth(3,4);
    numbers.print_all();
    numbers.delete_kth(3);
    numbers.print_all();
    numbers.size();
    numbers.clear();
}
