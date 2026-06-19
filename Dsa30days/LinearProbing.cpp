#include <vector>
#include <iostream>
#include "LinearProbing.h"

LinearProbing::LinearProbing(int size) {
    bucketsize = size;
    buckets.resize(bucketsize); // Automatically uses default HashNode (empty)
    data_count = 0;
    load_factor = 0.0;
}

// C++ vectors manage their own heap memory. No manual deletion needed!
LinearProbing::~LinearProbing() {}

int LinearProbing::hashFucntion(int value) {
    // value % bucketsize can be negative in C++! 
    // This ensures the index is always positive.
    int index = value % bucketsize;
    if (index < 0) index += bucketsize;
    return index;
}

bool LinearProbing::isEmpty() const {
    return data_count == 0;
}

void LinearProbing::reshape() {
    std::vector<HashNode> tempVector = buckets; // Make a copy of old data

    bucketsize = bucketsize * 2;
    buckets.clear(); // Empty the old vector
    buckets.resize(bucketsize); // Create new larger vector filled with empty nodes

    data_count = 0; // Reset count before re-inserting

    // Re-insert only valid (not empty, not deleted) nodes
    for (const HashNode& node : tempVector) {
        if (!node.is_empty && !node.is_deleted) {
            insert(node.value);
        }
    }
    std::cout << "--> Reshape successfully done! New Capacity: " << bucketsize << "\n";
}

void LinearProbing::reshape_caller() {
    // FIX: Cast data_count to float FIRST to prevent integer division
    load_factor = (float)data_count / bucketsize;
    if (load_factor > 0.5) {
        std::cout << "\n[!] Triggered reshape because load factor is > 0.5\n";
        reshape();
    }
}

void LinearProbing::insert(int value) {
    int index = hashFucntion(value);

    // Keep probing as long as the spot is NOT empty and NOT a deleted tombstone
    while (!buckets[index].is_empty && !buckets[index].is_deleted) {
        if (buckets[index].value == value) {
            std::cout << "Value:" << value << " already exists!! Duplicates not allowed\n";
            return;
        }
        index++;
        if (index >= bucketsize) index = 0;
    }

    // We found an empty spot or a tombstone! Overwrite it.
    buckets[index].value = value;
    buckets[index].is_empty = false;
    buckets[index].is_deleted = false;

    data_count++;
    std::cout << "Value:" << value << " successfully inserted at index " << index << "\n";
    reshape_caller();
}

bool LinearProbing::search(int value) {
    int index = hashFucntion(value);

    // Keep searching as long as the bucket is NOT empty.
    // Notice we DO NOT stop for tombstones (is_deleted == true)!
    while (!buckets[index].is_empty) {
        if (!buckets[index].is_deleted && buckets[index].value == value) {
            return true;
        }
        index++;
        if (index >= bucketsize) index = 0;
    }
    return false;
}

void LinearProbing::remove(int value) {
    int index = hashFucntion(value);

    // Probe to find the value
    while (!buckets[index].is_empty) {
        if (!buckets[index].is_deleted && buckets[index].value == value) {
            // FOUND IT! Mark it as deleted (Create Tombstone)
            buckets[index].is_deleted = true;
            data_count--;
            std::cout << "Value:" << value << " successfully removed from index " << index << "\n";
            return;
        }
        index++;
        if (index >= bucketsize) index = 0;
    }
    std::cout << "Value:" << value << " doesn't exist\n";
}

void LinearProbing::traver() const {
    if (isEmpty()) {
        std::cout << "Can't traverse!! There is no data\n";
        return;
    }
    for (int i = 0; i < bucketsize; i++) {
        if (buckets[i].is_empty) {
            std::cout << "Bucket " << i << ": [EMPTY]\n";
        }
        else if (buckets[i].is_deleted) {
            std::cout << "Bucket " << i << ": [TOMBSTONE]\n";
        }
        else {
            std::cout << "Bucket " << i << ": " << buckets[i].value << "\n";
        }
    }
}