#include<iostream>
#include<vector>

void greaterElementsCount(int n, const std::vector<int>& v){
    //example 1
    //for each element, find the number of greater elements than it
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[j] > v[i]){
                cnt++;
            }
        }
    }
     std::cout<< cnt << std::endl;
    // Time : O(n^2)
}

void greaterElementsCount2(int n, const std::vector<int>& v){
    //example 2
    //for each element, find the number greater elemnts after it
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[j] > v[i]){
                cnt++;
            }
        }
    }
    std::cout<< cnt << std::endl;
    //Time: O(n^2)
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    greaterElementsCount(n, v);
    greaterElementsCount2(n, v);
}