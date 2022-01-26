
#include "MapWithLinearProbing.h"

MapWithLinearProbing::MapWithLinearProbing(std::size_t capacity) : nPairsInserted {}, capacity{capacity} {
    entries = new KVPair[capacity]{};
    tracker = new bool[capacity]{false};
};


MapWithLinearProbing::~MapWithLinearProbing() { delete entries; }

void MapWithLinearProbing::put(int k, const std::string &v) {
    std::size_t index = hash(k);
    if (tracker[index] == false) insertKvPair(k, v, index);
    else findSlotAndInsertKVPair(k, v, index);
    nPairsInserted++;
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

std::string MapWithLinearProbing::get(int key) {
    return entries[getKVPairIndex(key)].value;
}

void MapWithLinearProbing::remove(int key) {
    tracker[getKVPairIndex(key)] = false;
}

std::size_t MapWithLinearProbing::size() const {
    return nPairsInserted;
}

std::size_t MapWithLinearProbing::getKVPairIndex(int key) const {
    std::size_t index = hash(key);
    int i {};
    while (true){
        if (tracker[index + i] == true && key == entries[index + i].key){
            return index + i;
        }
        i++;
    }
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
