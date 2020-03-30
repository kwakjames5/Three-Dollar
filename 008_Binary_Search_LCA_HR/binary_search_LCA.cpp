#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) 
    {
		// Write your code here.
        if(root == NULL)
        {
            return NULL;
        }
        
        while((v1 < root->data && v2 < root->data) || (v1 > root->data && v2 > root->data))
        {
            if(v1 < root->data && v2 < root->data)
            {
                root = root-> left;
            }
            else
            {
                root = root-> right;
            }
        }

        return root;
    }
}; //End of Solution

int main() {
  
    ifstream ifile("input.txt", std::ifstream::in);

    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    ifile >> t;

    while(t-- > 0) {
        ifile >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	ifile >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << "The Least Common Ancestor is: " << ans->data << std::endl;

    return 0;
}