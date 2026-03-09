#include <iostream>
using namespace std;

struct Node
{
    string code;
    Node* left;
    Node* right;

    Node(string c)
    {
        code = c;
        left = NULL;
		right = NULL;
    }
};

class BST
{
    public:
	    Node* root;
        BST()
        { 
		    root = NULL; 
		}
	    Node* insert(Node* node, string code)
        {
	        if(node == NULL){
	        	return new Node(code);
			}
	            
	        else if(code < node->code){
	        	 node->left = insert(node->left, code);
			}
	        
	        else{
	        	node->right = insert(node->right, code);
			}
	            
	        return node;
	    }
	
	    void inorder(Node* node)
        {
	        if(node == NULL)
            {
                return;
            }
	        inorder(node->left);
	        cout<<node->code<<" ";
	        inorder(node->right);
	    }
	    void insert(string code)
        {
	        root = insert(root, code);
	    }
	
	    void displayInorder(){
	        cout<<"\nCourses in Alphabetical Order:"<<endl;
	        inorder(root);
	        cout << endl;
	    }
};

int main(){
    BST tree;
    int n;
    string code;

    cout<<"Number of courses to insert : ";
    cin>>n;
    cout<<endl;

    for(int i = 0; i < n; i++)
    {
        cout<<"Enter course "<<i+1<<" Code : ";
        cin>>code;
        tree.insert(code);
    }

    tree.displayInorder();
    
    return 0;
}