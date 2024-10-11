## Практикум №1 по Структури от данни, Информационни системи, 4 група

## Сложности

Изчислете сложностите по време и по памет на следните алгоритми:

```c++
int f(int n) {
	int result = 0;
	for (size_t i = 0; i < 32; i++) {
		result += n;
	}
	return result;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(1)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
int f(int n) {
	int arr[INT_MAX];
 	arr[1] = 1;
	arr[2] = 2;
	return 1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(1)
	
  Space Complexity: O(1)
  
  Защо? Но на практика правилно ли е да го правим?
</details>


```c++
int f(int n) {
	int result = 1;
	for(size_t i = 0; i < INT_MAX; i++) {
		result += i;
	}
	return 1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(1)
	
  Space Complexity: O(1)
  
  Защо? Но на практика правилно ли е да го правим?
</details>


```c++
int f(int n) {
	int result = 1;
	for(size_t i = 1; i < n; i*=2) {
		result += i;
	}
	return 1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(log N)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
bool find(int target, int maxCycles) {
    for(int i = 0; i < maxCycles; i++) {
        for(int j = 0; j < maxCycles; j++) {
            for(int k = 0;k < maxCycles; k++) {
                if(x + y + z == target) {
                    return true;
                }
            }
        }
    }
    return false;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(N ^ 3)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
void print(const int* arr, int n)
for(int i = 0; i < n; i++) {
    for(int j = n + i - 5; j < n; j++) {
        std::cout<<arr[i]<<std::endl;
    }
}
```
<details>
  <summary>Отговор</summary>
  Time Complexity: O(N)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
void selectionSort(int* arr, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;

		// first i numbers are already ordered
		for (size_t j = i + 1; j < length; j++) {
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}

		if (minIndex != i) // if minIndex changed - swap
			swap(arr[i], arr[minIndex]);
	}
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(N ^ 2)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
int binarySearch(const std::vector<int>& v, int target) {
	int left = 0;
	int right = v.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2; // why?
		if (v[mid] == target) {
			return mid;
		}
		else if (v[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(logN)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
void printIndexes(const std::vector<int>& v)  {
    for (int i = 0; i < v.size(); i++)  {
        std::cout << binarySearch(arr, v.size(), arr[i], 0, size - 1);
    }
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(N*logN)
	
  Space Complexity: O(1)
  
  Защо?
</details>


## Функцията std::sort
`std::sort` е стандартна функция в C++, която се използва за сортиране на елементи от дадена колекция от данни. Тя е част от стандартната библиотека `<algorithm>`, която съдържа различни алгоритми за обработка на колекции от данни.

Най-често е имплементирана или чрез `Quick Sort`, или чрез алгоритъм, комбиниращ `Quick Sort`, `Heap Sort` (за който ще научите по-натам в курса) и `Insertion Sort`. 

Декларация на функцията:
```c++
#include <algorithm>

template <class RandomIt>
void sort(RandomIt first, RandomIt last);

template <class RandomIt, class Compare>
void sort(RandomIt first, RandomIt last, Compare comp);

```

- `Параметри`:
  - first: Итератор, указващ началото на колекцията елементи, които трябва да бъдат сортирани.
  - last: Итератор, указващ края на колекцията елементи, които трябва да бъдат сортирани (сочи елементът след последния елемент в диапазона).
  - comp (по избор): критерий за сортиране (по default се използва operator<).

- `Сложност`: std::sort има средна времева сложност O(n*log n), където n е броят на елементите, които искаме да бъдат сортирани.
- `In-Place`: std::sort е in-place алгоритъм.
- `Stable`: std::sort не е стабилен алгоритъм.

```c++
#include <iostream>
#include <algorithm>

int main() {
    int arrSize = 5;
    int arr[] = {25, 42, 33, 14, 56};

    std::sort(arr, arr + arrSize);

    for (const int& n : v) {
        std::cout << n << ' ';
    }
    return 0;
}
```

```c++
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {25, 42, 33, 14, 56};

    std::sort(v.begin(), v.end());

    for (const int& n : v) {
        std::cout << n << ' ';
    }
    return 0;
}
```

```c++
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {25, 42, 33, , -5, , 0, 14, 56};

    std::sort(v.begin(), v.begin() + 3);

    for (const auto& n : v) {
        std::cout << n << ' ';
    }
    return 0;
}
```


- Пример с функция:
```c++
#include <iostream>
#include <algorithm>
#include <vector>

bool compareLastDigit(int a, int b) {
    return (a % 10) < (b % 10); 
}

int main() {
    std::vector<int> v = {25, 42, 33, 14, 56};

    std::sort(v.begin(), v.end(), compareLastDigit);

    for (const int& n : v) {
        std::cout << n << ' ';
    }
    return 0;
}

```

- Пример с **ламбда** функция:
```c++
#include <iostream>
#include <algorithm>
#include <vector>

struct PairOfInt {
    int first;
    int second;
};

int main() {
    std::vector<PairOfInt> v = { {1, 2}, {2, 1}, {5, 7}, {3, 3}, {4, 3} };

    std::sort(v.begin(), v.end(), [](const PairOfInt& lhs, const PairOfInt& rhs) { return lhs.second < rhs.second; });

    for (const auto& n : v) {
        std::cout << n.first << ' ' << n.second << std::endl;
    }
    return 0;
}

```

## Задачи и линк към методите на `std::vector`
- [**std::vector**](https://cplusplus.com/reference/vector/vector/)
- [**std::vector**](https://en.cppreference.com/w/cpp/container/vector)
- [**Линк към задачите**](https://leetcode.com/problem-list/an1phfb2/)
- [Линк към таблица с leetcode акаунти](https://docs.google.com/spreadsheets/d/1BEdu9Ui3cWt0AYsXJqb1Aoon9njWxHLXnWS-3-feorw/edit?gid=0#gid=0)