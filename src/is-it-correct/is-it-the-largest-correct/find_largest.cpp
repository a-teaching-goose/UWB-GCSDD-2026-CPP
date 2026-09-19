int findLargest(const int values[], int size) {
    int largest = values[0];

    for (int i = 0; i < size; ++i) {
        if (values[i] > largest) {
            largest = values[i];
        }
    }

    return largest;
}
