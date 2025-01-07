#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

static size_t getHash(const std::string& str)
{
    return str.size();
}

class DictionaryLP
{
    struct Node
    {
        std::string key = "";
        int value = 0;
        bool isTaken = false;
        bool isDeleted = false;

        Node() = default;
        Node(const std::string& key, int value, bool isTaken, bool isDeleted) : key(key), value(value), isTaken(isTaken), isDeleted(isDeleted) {};
    };

    size_t getHashCode(const std::string& key) const
    {
        return getHash(key) % data.size();
    }

    void resize()
    {
        std::vector<Node> newData(2 * data.size());
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->isTaken && !it->isDeleted) {
                size_t index = getHash(it->key) % newData.size();

                do {
                    if (!newData[index].isTaken) {
                        newData[index] = Node(std::move(it->key), std::move(it->value), true, false);
                        break;
                    }
                    index = (index + jumpStep) % newData.size();
                } while (true);
            }
        }

        data = std::move(newData);
    }

    std::vector<Node> data;
    size_t jumpStep;
    double maxLoadFactor = 0.5;
    size_t size = 0;

public:
    DictionaryLP()
    {
        data.resize(100);
        jumpStep = 3;
    }

    double loadFactor()
    {
        return (double)size / data.size();
    }

    void add(const std::string& key, int value)
    {
        if (loadFactor() > maxLoadFactor) {
            resize();
        }

        size_t index = getHashCode(key);
        size_t counter = 0;
        do {
            if (!data[index].isTaken || data[index].isDeleted) {
                data[index] = Node(key, value, true, false);
                size++;
                return;
            }
            else if (data[index].isTaken && data[index].key == key) {
                return;
            }
            index = (index + jumpStep) % data.size();
            counter++;

        } while (counter < size);
    }

    int getValue(const std::string& key)
    {
        size_t index = getHashCode(key);
        size_t counter = 0;

        do {
            if (!data[index].isTaken) {
                break;
            }
            else if (!data[index].isDeleted && data[index].key == key) {
                return index;
            }
            index = (index + jumpStep) % data.size();
            counter++;

        } while (counter < size);

        throw "Key not found";
    }

    void remove(const std::string& key)
    {
        size_t index = getHashCode(key);
        size_t counter = 0;

        do {
            if (!data[index].isTaken) {
                return;
            }
            else if (!data[index].isDeleted && data[index].key == key) {
                data[index].key.clear();
                data[index].value = 0;
                data[index].isDeleted = true;
                size--;
                return;
            }
            index = (index + jumpStep) % data.size();
            counter++;

        } while (counter < size);
    }
};