#include <cstddef>
#include <iostream>
#include <stdexcept>

// This class owns a resizable heap array.
class DynamicArray {
public:
    explicit DynamicArray(std::size_t initialCapacity = 2)
        : size_(0), capacity_(initialCapacity), data_(new int[initialCapacity]) {}

    // Intentional bug: this class needs a destructor that deletes data_.

    void add(int value) {
        if (size_ == capacity_) {
            resize();
        }
        data_[size_] = value;
        ++size_;
    }

    int at(std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("index is outside the array");
        }
        return data_[index];
    }

    std::size_t size() const {
        return size_;
    }

private:
    void resize() {
        const std::size_t newCapacity = capacity_ * 2;
        int* newData = new int[newCapacity];

        for (std::size_t i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }

        delete[] data_;  // The old resized array is cleaned up correctly.
        data_ = newData;
        capacity_ = newCapacity;
    }

    std::size_t size_;
    std::size_t capacity_;
    int* data_;
};

int main() {
    DynamicArray numbers;

    for (int i = 1; i <= 10; ++i) {
        numbers.add(i * i);
    }

    std::cout << "Squares: ";
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers.at(i) << " ";
    }
    std::cout << "\n";

    // The output is correct, but data_ leaks when numbers is destroyed.
    return 0;
}
