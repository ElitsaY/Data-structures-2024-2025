# Дървета
[Дървета](https://github.com/IvanMakaveev/DS-IS-2024-2025/tree/main/Practicum/Pract-06/BinaryTree)

Задачи в час:   
[94](https://leetcode.com/problems/binary-tree-inorder-traversal/)
[145](https://leetcode.com/problems/binary-tree-postorder-traversal/)
[144](https://leetcode.com/problems/binary-tree-preorder-traversal/)
[104](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
[113](https://leetcode.com/problems/path-sum-ii/)



## Задачи
[Задачи за решаване от студенти](https://leetcode.com/problem-list/aw7zfjz1/)

# Зад 113
```c++
void helper (TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& path) {
      if(!root) {
          return;
      }  
      targetSum -= root->val;
        path.push_back(root->val);
        if(targetSum == 0 && !root->left && !root->right) {
            res.push_back(path);
        }
        
        helper(root->left, targetSum, res, path);
        helper(root->right, targetSum, res, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int>path;
        helper(root, targetSum, answer, path);
        return answer;
    }
```