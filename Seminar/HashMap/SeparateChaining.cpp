#include<iostream>
#include<forward_list>
#include<vector>
#include<string>
#include<list>
#include <stdexcept>
#include <algorithm>

int getHash(const std::string& str){
    return str.size();
}

class Dictionary{
private:
    typedef std::pair<std::string, int> element;

    std::list<element> data;
    std::vector<std::forward_list<std::list<element>::iterator>> hashTable;

public:

    Dictionary(){
        hashTable.resize(10);
    }

    void add(const std::string& key, int value){
        int hashCode = getHash(key) % hashTable.size();
        auto& bucket = hashTable[hashCode];
        auto iter = std::find_if(bucket.begin(), bucket.end(), 
            [&key](const std::list<element>::iterator& currIter){
                return currIter->first == key;
            });

        if(iter != bucket.end()){
            return;
        }

        data.push_back({key, value});
        bucket.push_front(--data.end());
        
    }

    void remove(const std::string& key){
        int hashCode = getHash(key) % hashTable.size();
        auto& bucket = hashTable[hashCode];
        bucket.remove_if([this, key](const std::list<element>::iterator& currIter){
            if(key == currIter->first){
                data.erase(currIter);
                return true;
            }
            return false;
        });
    }

    int getValue(const std::string& key) const{
        int hashCode = getHash(key) % hashTable.size();
        auto& bucket = hashTable[hashCode];
        auto iter = std::find_if(bucket.begin(), bucket.end(), 
            [&key](const std::list<element>::iterator& currIter){
                return currIter->first == key;
            });

        if(iter == bucket.end()){
            throw std::out_of_range("Element not found");
        }

        return (*iter)->second;
    }

    void print() const{
        for(auto iter = data.begin(); iter != data.end(); ++iter){
            std::cout << iter->first <<' ' << iter->second << std::endl; 
        }
    }

};

int main(){
    Dictionary myDict;
    myDict.add("ellie", 22);
    myDict.add("ellie", 25);
    myDict.add("Lubo", 23);
    myDict.add("Ivan", 21);
    myDict.print();
    myDict.remove("Ivan");
    myDict.print();
    std::cout << myDict.getValue("ellie") << std::endl;
}