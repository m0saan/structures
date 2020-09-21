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

class KVPair {
public:
    KVPair(int k, std::string v) : key{k}, value{std::move(v)} {}
    bool operator==(const KVPair& rhs) { return key = rhs.key && value == rhs.value; }

    int key;
    std::string value;
};

class Map {
public:
    explicit Map(std::size_t initial_capacity) : init_capacity{initial_capacity} {
        table = new std::vector<std::list<KVPair>>(initial_capacity, std::list<KVPair>{});
        //buckets->resize(initial_capacity);
    };

    void put(int k, const std::string &v) {
        if (!(isValidKey(k))) throw std::runtime_error{"Invalid key"};
        std::size_t index = hash(k);
        for (const auto &iter : table->at(index))
            if (iter.key == k) return;
        table->at(index).push_back(KVPair{k, v});
    }

    std::string get(int k) {
        if (!(isValidKey(k))) throw std::runtime_error{"Invalid key"};
        return getBucket(k).value;
        throw std::logic_error{ "No such element" };
    }

    void remove(int k){
        if (!(isValidKey(k))) throw std::runtime_error{"Invalid key"};
        auto bucket = getBucket(k);
        table->at(hash(k)).remove(bucket);
    }

private:
    std::size_t init_capacity;
    std::vector<std::list<KVPair>> *table;
private:
    std::size_t hash(int key) const { return key % table->capacity(); }
    static bool isValidKey(int &k) { return k >= 0; }
    KVPair getBucket(int &k){
        auto bucket = table->at(hash(k));
        for (auto iterator = bucket.cbegin(); iterator != bucket.end(); ++iterator)
            if (iterator->key == k) return KVPair{ k, iterator->value };
        throw std::logic_error{ "No such element" };
    }
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_MAP_H
