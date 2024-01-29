#include <iostream>
#include "cList.h"

// Constructor
cKeyValueList::cKeyValueList(int theCapacity) {
    listCapacity = theCapacity;
    keyValues = new KEY_VALUE[listCapacity];
    listCount = 0;
    first = 0;
    last = 0;
}

// Destructor
cKeyValueList::~cKeyValueList() {
    delete[] keyValues;
}

// Inserts a value at the beginning of the list
bool cKeyValueList::insert(KEY_VALUE kv) {
    bool success = false;
    if (listCount < listCapacity) {
        keyValues[first] = kv;
        cListDec(first);
        listCount++;
        success = true;
    }
    return success;
}

// Inserts a value at the end of the list
bool cKeyValueList::add(KEY_VALUE kv) {
    bool success = false;
    if (listCount < listCapacity) {
        keyValues[last] = kv;
        cListInc(last);
        listCount++;
        success = true;
    }
    return success;
}

// Inserts a value at a specific index
bool cKeyValueList::insertAt(int index, KEY_VALUE kv) {
    bool success = false;
    if (index >= 0 && index <= listCount && listCount < listCapacity) {
        int physIndex = virtualToPhysical(index);
        for (int i = listCount; i > index; i--) {
            keyValues[virtualToPhysical(i)] = keyValues[virtualToPhysical(i - 1)];
        }
        keyValues[physIndex] = kv;
        cListInc(last);
        listCount++;
        success = true;
    }
    return success;
}

// Deletes a value at a specific index
bool cKeyValueList::deleteAt(int index, KEY_VALUE &kv) {
    bool success = false;
    if (index >= 0 && index < listCount) {
        int physIndex = virtualToPhysical(index);
        kv = keyValues[physIndex];
        for (int i = index; i < listCount - 1; i++) {
            keyValues[virtualToPhysical(i)] = keyValues[virtualToPhysical(i + 1)];
        }
        cListDec(last);
        listCount--;
        success = true;
    }
    return success;
}

// Reads a value at a specific index
bool cKeyValueList::readAt(int index, KEY_VALUE &kv) const {
    bool success = false;
    if (index >= 0 && index < listCount) {
        int physIndex = virtualToPhysical(index);
        kv = keyValues[physIndex];
        success = true;
    }
    return success;
}

// Deletes the first element in the list
bool cKeyValueList::deleteFirst(KEY_VALUE &kv) {
    bool success = false;
    if (listCount > 0) {
        kv = keyValues[first];
        cListInc(first);
        listCount--;
        success = true;
    }
    return success;
}

// Deletes the last element in the list
bool cKeyValueList::deleteLast(KEY_VALUE &kv) {
    bool success = false;
    if (listCount > 0) {
        kv = keyValues[last];
        cListDec(last);
        listCount--;
        success = true;
    }
    return success;
}

// Prints the list from start to end
void cKeyValueList::printIt(int limit) const {
    for (int i = 0; i < limit; i++) {
        KEY_VALUE kv = keyValues[physicalToVirtual(i)];
        std::cout << kv.key << " " << kv.value << std::endl;
    }
}

// Prints the list from end to start
void cKeyValueList::printItBackwards(int limit) const {
    for (int i = listCount - 1; i >= listCount - limit; i--) {
        KEY_VALUE kv = keyValues[physicalToVirtual(i)];
        std::cout << kv.key << " " << kv.value << std::endl;
    }
}

// Returns the index of the first occurrence of a key
int cKeyValueList::getIndex(int key) const {
    int index = -1;
    for (int i = 0; i < listCount; i++) {
        if (keyValues[physicalToVirtual(i)].key == key) {
            index = i;
            break;
        }
    }
    return index;
}

// Returns the current number of elements in the list
int cKeyValueList::size() const {
    return listCount;
}

// Checks if the list is empty
bool cKeyValueList::isEmpty() const {
    return listCount == 0;
}

// Returns the capacity of the list
int cKeyValueList::getCapacity() const {
    return listCapacity;
}

// Counts the list
int cKeyValueList::getCount() const {
    return listCount;
}

int cKeyValueList::virtualToPhysical(int virtualIndex) const {
    // Calculate the physical index corresponding to the virtual index
    return (first + virtualIndex) % listCapacity;
}

int cKeyValueList::physicalToVirtual(int physicalIndex) const {
    // Calculate the virtual index corresponding to the physical index
    int virtualIndex = physicalIndex - first;
    if (virtualIndex < 0) {
        virtualIndex += listCapacity;
    }
    return virtualIndex;
}

// Clears the list
void cKeyValueList::clear() {
    listCount = 0;
    first = 0;
    last = 0;
}
