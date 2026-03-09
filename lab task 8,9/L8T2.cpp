#include <iostream>
using namespace std;

class FolderNode
{
public:
    int fileSize;        
    FolderNode* child;   
    FolderNode* sibling;   

    FolderNode(int size)
    {
        fileSize = size;
        child = NULL;
        sibling = NULL;
    }
};

int getTotalSize(FolderNode* root)
{
    if (root == NULL)
        return 0;

    int total = root->fileSize;

    total = total + getTotalSize(root->child);

    total = total + getTotalSize(root->sibling);

    return total;
}

int main()
{
    FolderNode* root = new FolderNode(20);

    FolderNode* sub1 = new FolderNode(10);
    root->child = sub1;

    FolderNode* sub2 = new FolderNode(50);
    sub1->sibling = sub2;

    FolderNode* sub1child = new FolderNode(5);
    sub1->child = sub1child;

    FolderNode* sub2child = new FolderNode(100);
    sub2->child = sub2child;

    cout << "Total storage: " << getTotalSize(root) << endl;

    return 0;
}
