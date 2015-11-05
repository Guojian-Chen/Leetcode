#include<iostream>
#include<vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionTwo {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        if (e1 - s1 != e2 - s2) return NULL;
        
        int len = e1-s1 +1;
        int rootVal = postorder[e2];
        int index = -1;
        for (int i = s1; i <= e1; i++) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }
        if (index == -1) return NULL;
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(inorder, postorder, s1, index-1, s2, s2+index-s1-1);
        root->right = helper(inorder, postorder, index+1, e1, s2+index-s1, e2-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.size() == 0)
            return NULL;
            
        int len = inorder.size();
        return helper(inorder, postorder, 0, len-1, 0, len-1);
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.size() == 0)
            return NULL;

        if (inorder.size() == 1)
            return new TreeNode(inorder[0]);
            
        int len = postorder.size();
        int rootVal = postorder[len-1];
        int index = -1;
        for (int i = 0; i < len; i++) {
            if (inorder[i] == rootVal) {
                index = i;
				break;
			}
        }
		if (index == -1)
			return NULL;

        int lSize = index;
        int rSize = len - index -1;
		
		cout << "lSize = " << lSize << endl;        
		cout << "rSize = " << rSize << endl;        
        vector<int> inorder_left(inorder.begin(), inorder.begin()+lSize);
        vector<int> inorder_right(inorder.begin()+lSize+1, inorder.end());
        vector<int> postorder_left(postorder.begin(), postorder.begin()+lSize);
        vector<int> postorder_right(postorder.begin()+lSize, postorder.end()-1);
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(inorder_left, postorder_left);
        root->right = buildTree(inorder_right, postorder_right);
        return root;
    }
};
void printBST(TreeNode* root)
{
	if (root == NULL)
		return;
	cout<<root->val << " ";
	printBST(root->left);
	printBST(root->right);
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {1,3,2,5,7,6,4};
	vector<int> inorder(a, a+sizeof(a)/sizeof(int));
	vector<int> postorder(b, b+sizeof(b)/sizeof(int));
	Solution instance;
	SolutionTwo instanceTwo;
	TreeNode* root = instance.buildTree(inorder, postorder);
	printBST(root);
	cout<<endl;
	TreeNode* rootTwo = instanceTwo.buildTree(inorder, postorder);
	printBST(rootTwo);
	cout<<endl;
	
	return 0;
}
