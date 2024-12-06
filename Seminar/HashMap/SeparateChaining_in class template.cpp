#include<iostream>
#include<list>
#include<forward_list>
#include<string>
#include<vector>
#include<algorithm>

int getHash(const std::string& str){
    return str.size();
}

class Dictionary{
private:
    typedef std::pair<std::string, int> element;

    std::list<element> elements;
    std::vector<std::forward_list<std::list<element>::iterator>> hashTable;

public:
    Dictionary(){
        hashTable.resize(10);
    }

    void add(const std::string& key, int value){
        //1. определяме позиция за key в hashTable чрез хеш функия
        int hashCode = getHash(key) % hashTable.size();
        auto& chain = hashTable[hashCode];

        auto iter = std::find_if(chain.begin(), chain.end(),
            [&key](const std::list<element>::iterator& currIter){
                return currIter->first == key;
            }
        );

        if(iter != chain.end()){
            return;
        }

        elements.push_back({key, value});
        chain.push_front(--elements.end());

    }

    void remove(const std::string& key){
        int hashCode = getHash(key) % hashTable.size();
        auto& chain = hashTable[hashCode];

        chain.remove_if( 
        [this, &key](const std::list<element>::iterator& currIter){
            if(currIter->first == key){
                elements.erase(currIter);
                return true;
            } 
            return false;
        });
    }

    int getValue(const std::string& key) const{
        int hashCode = getHash(key) % hashTable.size();
        auto& chain = hashTable[hashCode];

        auto iter = std::find_if(chain.begin(), chain.end(),
            [&key](const std::list<element>::iterator& currIter){
                return currIter->first == key;
            }
        );

        if(iter == chain.end()){
            throw "Not found!";
        }

        return (*iter)->second;
    }

    void print() const{
       for(auto it = elements.begin(); it != elements.end(); ++it){
            std::cout<< it->first <<" " << it->second << std::endl;
       }
    }

};

int main(){
    Dictionary myDict;
    myDict.add("ellie", 22);
    myDict.add("elena", 25);
    myDict.add("Lubo", 23);
    myDict.add("Ivan", 21);
    myDict.print();
    std::cout<< "------------\n";
    myDict.remove("Ivan");
    myDict.print();
    std::cout<< "value : \n";
    std::cout << myDict.getValue("ellie") << std::endl;
}