#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


class BinaryTree{
    private:
    struct Node{
        int data{};
        Node*left{};
        Node*right{};
        Node(int data) : data(data) { }
    };
    Node* root { };
    void print_inorder(Node*current){
        if(!current)
        return ;
        print_inorder(current->left);
       cout<<current->data<<" ";
        print_inorder(current->right);
    }
    int tree_max(Node* root){
        if(!root)
        return;
        int left_max=tree_max(root->left);
        int right_max=tree_max(root->right);
        return max(root->data,max(left_max,right_max));
    }
    int tree_height(Node* root){
        if(!root)
        return;
        int left_height = tree_height(root->left);
        int right_height= tree_height(root->right);
        return max(left_height,right_height)+1;
    }
    int total_nodes(Node*root){
        if(!root)
        return;
        int left_nodes= total_nodes(root->left);
        int right_nodes = total_nodes(root->right);
        return (left_nodes+right_nodes)+1;
    }
    int total_nodes_of_leaves (Node* root){
        if(!root)
        return 0;
        if(!root->left&&root->right)
        return 1;
        int left_leaves = total_nodes_of_leaves(root->left);
        int right_leaves = total_nodes_of_leaves(root->right);

        return left_leaves + right_leaves;
    }
    bool is_exists(int value){
        if(!root)
        return;
        if(root->data==value)
        return true;
        if(is_exists(root->right->data)||is_exists(root->right->data)) 
        return true;
    }
    bool is_perfect(Node* root){
        if(!root)
        return true;// empty => perfect
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if(left_height==left_height)
        return false;
   
        return is_perfect(root->left) && is_perfect(root->right);        
    }
};

int main(){

}