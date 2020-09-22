#ifndef MAP_WITH_LINEAR_PROBING_H
#define MAP_WITH_LINEAR_PROBING_H

#include<string>
#include <iostream>

class KVPair {
public:
    KVPair() = default;
    KVPair(int k, std::string v) : key{k}, value{std::move(v)} {}

    int key{};
    std::string value;
};

class MapWithLinearProbing {
public:
    explicit MapWithLinearProbing(std::size_t capacity);
    ~MapWithLinearProbing();

    void put(int k, const std::string &v);
    void remove(int key);
    std::string get(int key);
    std::size_t size() const;
    void print() const;

private:
    std::size_t capacity;
    KVPair *entries;
    bool *tracker;

private:
    std::size_t nPairsInserted;
    std::size_t hash(int &k) const;
    void insertKvPair(int &k, const std::string &v, const std::size_t &index);
    void findSlotAndInsertKVPair(int &k, const std::string &v, std::size_t &index);
    std::size_t getKVPairIndex(int key) const;
};

#endif