#ifndef CLIST_H
#define CLIST_H

typedef struct key_value {
    int key;
    int value;
} KEY_VALUE;

class cKeyValueList {
private:
    KEY_VALUE *keyValues;
    int listCapacity;
    int listCount;
    int first;
    int last;

    int virtualToPhysical(int virtualIndex) const;
    int physicalToVirtual(int physicalIndex) const;

public:
    cKeyValueList(int theCapacity = 100);
    ~cKeyValueList();

    bool insert(KEY_VALUE kv);
    bool add(KEY_VALUE kv);
    bool insertAt(int index, KEY_VALUE kv);
    bool deleteAt(int index, KEY_VALUE &kv);
    bool readAt(int index, KEY_VALUE &kv) const;
    bool deleteFirst(KEY_VALUE &kv);
    bool deleteLast(KEY_VALUE &kv);
    void clear();
    void printIt(int limit) const;
    void printItBackwards(int limit) const;
    int getIndex(int key) const;
    int getCount() const;
    int getCapacity() const;
    int size() const;
    bool isEmpty() const;

};

#define cListInc(x) (x = (x + 1) % listCapacity)
#define cListDec(x) (x = (x + listCapacity - 1) % listCapacity)

#endif
