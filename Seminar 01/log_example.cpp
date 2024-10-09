#include<iostream>

int main(){
    int sum = 0;
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i *= 3){
        sum += i;
    }
    std::cout << sum << std::endl;
    //Time: O(log n)
}