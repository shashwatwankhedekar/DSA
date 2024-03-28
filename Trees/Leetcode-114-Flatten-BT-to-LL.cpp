// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                TreeNode *prev = curr->left;
                while (prev->right != NULL)
                    prev = prev->right;

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
