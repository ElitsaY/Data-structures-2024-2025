
## Задача [797](https://leetcode.com/problems/all-paths-from-source-to-target/);

```c++
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(0,graph,result,current);
        return result;
    }
  
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& current) {
        
        current.push_back(node);
        if (node == graph.size() - 1) allPaths.push_back(current);
        
        for (int i = 0; i < graph[node].size(); i++) {
            dfs(graph[node][i], graph, allPaths, current);
        }
        current.pop_back();
    }
};
```

## Препоръчителни задачи за упражнение:
- [210](https://leetcode.com/problems/course-schedule-ii/)
- [547](https://leetcode.com/problems/number-of-provinces/description/?envType=problem-list-v2&envId=ayzskyot)
- [207](https://leetcode.com/problems/course-schedule/)

## Задачи
[Задачи за решаване от студенти](https://leetcode.com/problem-list/awk20xji/);
