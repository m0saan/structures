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
    KVPair(KeyType k, ValueType v);
    bool operator==(const KVPair& rhs) const;

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
    explicit Map(std::size_t initial_capacity=5);
    ~Map();
    void put(KEY k, VALUE v);
    std::string get(KEY k);
    void remove(KEY k);

private:
    std::vector<std::list<KVPAIR>> *table;
private:
    std::size_t hash(KEY key) const;
    static bool isValidIndex(std::size_t &index);
    KVPAIR getBucket(KEY &k);
};



#endif //DATA_STRUCTURES_AND_ALGORITHMS_MAP_H
