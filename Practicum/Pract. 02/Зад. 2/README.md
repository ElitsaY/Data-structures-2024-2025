# Задача 2 - Quickselect algorithm

Този алгоритъм се използва за решение на една доста известна задача, а именно намиране на k-ти по големина елемент или k-th largest element

## Идея:

Използваме идеята от `QuickSort`, където функцията partition ни връща индекса на елемент, който се намира на правилното място, ако масивът беше изцяло сортиран и всички по-малки елементи са наляво от него, а всички по-големи надясно.
Съответно ако функцията `partition` ни даде индекс равен на търсенето `k`, то връщаме елемента на позиция `k`. Иначе, ако `k` е по-голямо, повтаряме процедурата надясно, ако не наляво. 
