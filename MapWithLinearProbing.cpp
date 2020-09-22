
#include "MapWithLinearProbing.h"

MapWithLinearProbing::MapWithLinearProbing(std::size_t capacity) : capacity{capacity} {
    entries = new KVPair[capacity]{};
    tracker = new bool[capacity]{false};
};


MapWithLinearProbing::~MapWithLinearProbing() { delete entries; }

void MapWithLinearProbing::put(int k, const std::string &v) {
    std::size_t index = hash(k);
    if (tracker[index] == false) insertKvPair(k, v, index);
    else findSlotAndInsertKVPair(k, v, index);
}

void MapWithLinearProbing::print() const {
    for (int i = 0; i < capacity; ++i) {
        if (tracker[i] != false)
            std::cout << "(" << entries[i].key << ", " << entries[i].value << ")" << std::endl;
    }
}

std::size_t MapWithLinearProbing::hash(int &k) const { return k % capacity; }

void MapWithLinearProbing::insertKvPair(int &k, const std::string &v, const size_t &index) {
    KVPair kvPair{k, v};
    entries[index] = kvPair;
    tracker[index] = true;
}

void MapWithLinearProbing::findSlotAndInsertKVPair(int &k, const std::string &v, size_t &index) {
    int i{};
    while (++i) {
        if (tracker[index + i] == false) {
            insertKvPair(k, v, index + i);
            return;
        }
    }
}