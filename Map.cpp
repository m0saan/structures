//
// Created by one for all on 21/09/2020.
//

#include "Map.h"

template<typename KEY, typename VALUE>
Map<KEY, VALUE>::Map(std::size_t initial_capacity) {
    table = new std::vector<std::list<KVPAIR>>(initial_capacity, std::list<KVPAIR>{});
}

template<typename KEY, typename VALUE>
Map<KEY, VALUE>::~Map() {
    delete table;
    table = nullptr;
}

template<typename KEY, typename VALUE>
void Map<KEY, VALUE>::put(const KEY k, const VALUE v) {
    std::size_t index = hash(k);
    for (const auto &iter : table->at(index))
        if (iter.key == k) return;
    table->at(index).push_back(KVPAIR { k, v });
}

template<typename KEY, typename VALUE>
std::string Map<KEY, VALUE>::get(KEY k) {
    return getBucket(k).value;
}

template<typename KEY, typename VALUE>
void Map<KEY, VALUE>::remove(KEY k) {
    table->at(hash(k)).remove( getBucket(k));
}

template<typename KEY, typename VALUE>
std::size_t Map<KEY, VALUE>::hash(KEY key) const {
    std::hash<KEY> hash;
    return hash(key) % table->capacity();
}

template<typename KEY, typename VALUE>
bool Map<KEY, VALUE>::isValidIndex(size_t &k) { return k >= 0; }

template<typename KEY, typename VALUE>
typename Map<KEY, VALUE>::KVPAIR Map<KEY, VALUE>::getBucket(KEY &k) {
    auto bucket = table->at(hash(k));
    for (auto iterator = bucket.cbegin(); iterator != bucket.end(); ++iterator)
        if (iterator->key == k) return KVPAIR { k, iterator->value };
    throw std::logic_error{ "No such element" };
}

template<typename MAP>
KVPair<MAP>::KVPair(KeyType k, ValueType v) : key{ k }, value{ v } {}

template<typename MAP>
bool KVPair<MAP>::operator==(const KVPair &rhs) const { return key == rhs.key && value == rhs.value; }