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
    explicit MapWithLinearProbing(std::size_t capacity);
    ~MapWithLinearProbing();

    void put(int k, const std::string &v);
    void print() const;


private:

    std::size_t capacity;
    KVPair *entries;
    bool *tracker;

private:

    std::size_t hash(int &k) const;

    void insertKvPair(int &k, const std::string &v, const std::size_t &index);
    void findSlotAndInsertKVPair(int &k, const std::string &v, std::size_t &index);
};

#endif