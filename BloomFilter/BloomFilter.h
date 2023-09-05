#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <stdbool.h>
#include <windows.h>

using namespace std;

namespace Jeffrey
{
    struct HashBKDR
    {
        size_t operator()(const string &key)
        {
            size_t val = 0;
            for (auto ch : key)
            {
                val *= 131;
                val += ch;
            }
            return val;
        }
    };

    struct HashAP
    {
        size_t operator()(const string &key)
        {
            size_t hash = 0;
            for (size_t i = 0; i < key.size(); i++)
            {
                if ((i & 1) == 0)
                    hash ^= ((hash << 7) ^ key[i] ^ (hash >> 3));
                else
                    hash ^= (~((hash << 11) ^ key[i] ^ (hash >> 5)));
            }
            return hash;
        }
    };
    struct HashDJB
    {
        size_t operator()(const string &key)
        {
            size_t hash = 5381;
            for (auto ch : key)
            {
                hash += (hash << 5) + ch;
            }
            return hash;
        }
    };

    template <size_t N, class K = string,
              class HashFunc1 = HashBKDR,
              class HashFunc2 = HashAP,
              class HashFunc3 = HashDJB>
    class BloomFilter
    {
    public:
        void set(const K &key)
        {
            size_t hashi1 = HashFunc1()(key) % (N * _ratio);
            size_t hashi2 = HashFunc2()(key) % (N * _ratio);
            size_t hashi3 = HashFunc3()(key) % (N * _ratio);
            _bt->set(hashi1);
            _bt->set(hashi2);
            _bt->set(hashi3);
        }
        bool test(const K &key)
        {
            size_t hashi1 = HashFunc1()(key) % (N * _ratio);
            size_t hashi2 = HashFunc2()(key) % (N * _ratio);
            size_t hashi3 = HashFunc3()(key) % (N * _ratio);

            // 可能存在误判
            if (_bt->test(hashi1) && _bt->test(hashi2) && _bt->test(hashi3))
                return true;
            else
                return false;
        }

    private:
        static const size_t _ratio = 10;
        bitset<N *_ratio> *_bt = new bitset<N * _ratio>;
    };
};