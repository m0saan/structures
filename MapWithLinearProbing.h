#ifndef MAP_WITH_LINEAR_PROBING_H
#define MAP_WITH_LINEAR_PROBING_H

#include<string>

class KVPair {
  public:
    KVPair(int k, std::string& v) : key { k }, value { v } {}
  private:
      int key;
      std::string value;
};

class MapWithLinearProbing {
  public:
  MapWithLinearProbing(std::size_t capacity) : capacity { capacity } {
    entries = new KVPair[capacity]{};
  };

  ~MapWithLinearProbing() { delete entries; }

  void put(int k, std::string& value){
    KVPair kvPair{k, v};
    std::size_t index = hash(k);
    if (entries[index] == nullptr)
      entries[index] = kvPair;
    else{
      int i {};
      while(i++){
        if (entries[index + i] == nullptr)
          entries[index + i] = kvPair;
        return;
      }
    }
  }

  private:
  std::size_t capacity;
  KVPair *entries;

  private:
  std::size_t hash(int &k) { return k % capacity; }
};
