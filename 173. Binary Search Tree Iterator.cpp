/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(1)time, O(N)space, 9.09%, ok
class BSTIterator {
private:
    stack<int> ret;
public:
    BSTIterator(TreeNode *root) {
        priority_queue<int> max_heap;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(q.size()){
            TreeNode* temp = q.front();
            q.pop();
            max_heap.push(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        while(max_heap.size()){
            ret.push(max_heap.top());
            max_heap.pop();
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !ret.empty();
    }

    /** @return the next smallest number */
    int next() {
        int num = ret.top();
        ret.pop();
        return num;
    }
};

// O(1)time, O(h)space, 79.17%, ok
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    // brilliant idea that only keeps O(height) space
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
        return top->val;
    }

    /** put all the left child() of root */
    void find_left(TreeNode* root){
        TreeNode* p = root;
        while(p != NULL){
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
