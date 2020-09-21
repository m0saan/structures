//
// Created by one for all on 21/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_MAP_H
#define DATA_STRUCTURES_AND_ALGORITHMS_MAP_H

#include <string>
#include <list>
#include <utility>
#include <vector>
#include <iostream>
#include <cstring>

template<typename MAP>
class KVPair {
public:

    using KeyType = typename MAP::KeyType;
    using ValueType = typename MAP::ValueType;
public:
    KVPair(KeyType k, ValueType v) : key{ k }, value{ v } {}
    bool operator==(const KVPair& rhs) { return key = rhs.key && value == rhs.value; }

    KeyType key;
    ValueType value;
};

template<typename KEY, typename VALUE>
class Map {
public:
    using KeyType = KEY;
    using ValueType = VALUE;
    using KVPAIR = KVPair<Map<KEY, VALUE>>;
public:
    explicit Map(std::size_t initial_capacity)  {
        table = new std::vector<std::list<KVPAIR>>(initial_capacity, std::list<KVPAIR>{});
        //buckets->resize(initial_capacity);
    };

    void put(KEY k, const VALUE v) {
        std::size_t index = hash(k);
        for (const auto &iter : table->at(index))
            if (iter.key == k) return;
        table->at(index).push_back(KVPAIR { k, v });
    }

    std::string get(KEY k) {
        return getBucket(k).value;
    }

    void remove(KEY k){
        auto bucket = getBucket(k);
        table->at(hash(k)).remove(bucket);
    }

private:
    std::vector<std::list<KVPAIR>> *table;
private:
    std::size_t sToi(KEY k){
        std::size_t out = 0;
        for (int i = 0; i < strlen(k); ++i)
            out += k[i];
        return out;
    }

    std::size_t hash(KEY key) const {
        std::hash<KEY> hash;
        return hash(key) % table->capacity();
    }

    static bool isValidKey(std::size_t &k) { return k >= 0; }

    KVPAIR getBucket(KEY &k) {
        auto bucket = table->at(hash(k));
        for (auto iterator = bucket.cbegin(); iterator != bucket.end(); ++iterator)
            if (iterator->key == k) return KVPAIR { k, iterator->value };
        throw std::logic_error{ "No such element" };
    }
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_MAP_H
