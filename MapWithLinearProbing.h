#ifndef MAP_WITH_LINEAR_PROBING_H
#define MAP_WITH_LINEAR_PROBING_H

#include<string>
#include <utility>

class KVPair {
public:
    KVPair() = default;

    KVPair(int k, std::string v) : key{k}, value{std::move(v)} {}

    int key{};
    std::string value;
};

class MapWithLinearProbing {
public:
    explicit MapWithLinearProbing(std::size_t capacity) : capacity{capacity} {
        entries = new KVPair[capacity]{};
        tracker = new bool[capacity]{false};
    };

    ~MapWithLinearProbing() { delete entries; }

    void put(int k, const std::string &v) {
        std::size_t index = hash(k);
        if (tracker[index] == false) insertKvPair(k, v, index);
        else findSlotAndInsertKVPair(k, v, index);
    }

    void print() const {
        for (int i = 0; i < capacity; ++i) {
            if (tracker[i] != false)
                std::cout << "(" << entries[i].key << ", " << entries[i].value << ")" << std::endl;
        }
    }


private:

    std::size_t capacity;
    KVPair *entries;
    bool *tracker;

private:

    std::size_t hash(int &k) const { return k % capacity; }

    void insertKvPair(int &k, const std::string &v, const std::size_t &index) {
        KVPair kvPair{k, v};
        entries[index] = kvPair;
        tracker[index] = true;
    }

    void findSlotAndInsertKVPair(int &k, const std::string &v, std::size_t &index) {
        int i{};
        while (++i) {
            if (tracker[index + i] == false) {
                insertKvPair(k, v, index + i);
                return;
            }
        }
    }
};

#endif