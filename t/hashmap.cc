#include <bits/stdc++.h>
using namespace std;

#ifndef _HASHMAP_H_
#define _HASHMAP_H_

template <class Key, class Value>
class HashNode
{
   public:
    Key key_;
    Value value_;
    HashNode* next;

    HashNode(Key key, Value value) : key_(key), value_(value), next(NULL)
    {
    }
    ~HashNode()
    {
    }
    HashNode& operator=(const HashNode& node)
    {
        key_ = node.key_;
        value_ = node.value_;
        next = node.next;
        return *this;
    }
};

template <class Key, class Value, class HashFunc, class EqualKey>
class HashMap
{
   public:
    HashMap(int size);
    ~HashMap();
    bool insert(const Key& key, const Value& value);
    bool del(const Key& key);
    Value& find(const Key& key);
    Value& operator[](const Key& key);

   private:
    HashFunc hash_;
    EqualKey equal_;
    HashNode<Key, Value>** table_;
    unsigned int size_;
    Value ValueNULL;
};

template <class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::HashMap(int size) : size_(size), hash_(), equal_()
{
    table_ = new HashNode<Key, Value>*[size_];
    for (unsigned i = 0; i < size_; i++)
        table_[i] = NULL;
}

template <class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::~HashMap()
{
    for (unsigned i = 0; i < size_; i++) {
        HashNode<Key, Value>* currentNode = table_[i];
        while (currentNode) {
            HashNode<Key, Value>* temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
    delete table_;
}

template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& key, const Value& value)
{
    int index = hash_(key) % size_;
    HashNode<Key, Value>* node = new HashNode<Key, Value>(key, value);
    node->next = table_[index];  // 头插法
    table_[index] = node;
    return true;
}

template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::del(const Key& key)
{
    unsigned index = hash_(key) % size_;
    HashNode<Key, Value>* node = table_[index];
    HashNode<Key, Value>* prev = NULL;
    while (node) {
        if (node->key_ == key) {
            if (prev == NULL) {
                table_[index] = node->next;
            } else {
                prev->next = node->next;
            }
            delete node;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::find(const Key& key)
{
    unsigned index = hash_(key) % size_;
    if (table_[index] == NULL)
        return ValueNULL;
    else {
        HashNode<Key, Value>* node = table_[index];
        while (node) {
            if (node->key_ == key)
                return node->value_;
            node = node->next;
        }
        return node->value_;
    }
}

template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::operator[](const Key& key)
{
    return find(key);
}

#endif

// 首先要定义hash函数与比较函数
class HashFunc
{
   public:
    int operator()(const string& key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); ++i) {
            hash = hash << 7 ^ key[i];
        }
        return (hash & 0x7FFFFFFF);
    }
};

class EqualKey
{
   public:
    bool operator()(const string& A, const string& B)
    {
        if (A.compare(B) == 0)
            return true;
        else
            return false;
    }
};

// 测试用例
int main()
{
    HashMap<string, string, HashFunc, EqualKey> hashmap(100);

    hashmap.insert("hello", "world");
    assert(hashmap["hello"] == "world");
    hashmap.insert("why", "dream");
    assert(hashmap["why"] == "dream");
    hashmap.insert("c++", "good");
    assert(hashmap.find("c++") == "good");
    hashmap.insert("welcome", "haha");
    assert(hashmap.find("welcome") == "haha");

    assert(hashmap.del("hello"));
    assert(hashmap.find("hello") == "");  // not exist print NULL

    hashmap["why"] = "love";
    assert(hashmap["why"] == "love");
    return 0;
}
