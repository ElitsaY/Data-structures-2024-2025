// key-value от тип int
// capacity
// put(int key, int value)
// get 

#include<iostream>
#include<list>
#include<unordered_map>


class LRUcache{
private:
    int capacity;

    std::list<std::pair<int, int>> elem;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> elemMap;

public:
    LRUcache(int _capacity) : capacity(_capacity){}

    void put(int key, int value){

        if(elemMap.find(key) != elemMap.end()){
            //elemMap.count(key)
            elem.erase(elemMap[key]);
        }

        elem.push_front({key, value});
        elemMap[key] = elem.begin();

        if(elem.size() > capacity){
            elemMap.erase(elem.back().first);
            elem.pop_back();
        }
    }

    int get(int key){
        if(elemMap.find(key) == elemMap.end()){
            //elemMap.count(key)
            throw "No such element";
        }

        auto it = elemMap[key];
        elem.splice(elem.begin(), elem, it);
        return it->second;
    }
};

int main(){

}