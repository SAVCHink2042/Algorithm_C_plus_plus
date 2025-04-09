/*УСЛОВИЕ: Написать функцию, которая удаляет из бинарного дерева поиска узел со значением key. В ре-
зультате должно получиться правильное бинарное дерево поиска.

Программа должна считать последовательность чисел произвольной длины и число key с кла-
виатуры, построить из последовательности бинарное дерево поиска и вывести на экран результат
работы функции.
Результат работы функции (дерево) следует вывести по слоям при помощи обхода в ширину. Если
соответствующего узла нет в дереве, то вместо него следует вывести NULL.

*/

#include <iostream>
#include <queue>
 
struct TreeNode {
    int value;
    TreeNode *right;
    TreeNode *left;
};
 
TreeNode *Push(TreeNode *tree, int val) {
    if (!tree) {
        return new TreeNode{val, NULL, NULL};
    }
    if (val < tree->value) {
        tree->left = Push(tree->left, val);
    }
    else {
        tree->right = Push(tree->right, val);
    }
    return tree;
}
 
 void printTree(TreeNode *root) {
	std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty() ) {
        TreeNode *node = queue.front();
        queue.pop();
        if (node) {
            std::cout << node->value << std::endl;
            queue.push(node->left);
            queue.push(node->right);
        }
        else {
            std::cout << "nullptr" << std::endl;
        }
    }
}

void Delltree(TreeNode *tree) {
    TreeNode  *Now=tree, *Right=NULL, *Left=NULL ;
    Right=Now->right;
    Left=Now->left;
    if( Right!=NULL ) {
        Delltree(Right);
    }
    if( Left!=NULL ) {
        Delltree(Left);
    }
    delete Now;
}

TreeNode* Process(TreeNode* tree, int key) {
    TreeNode  *dang=tree, *buf, *buf1, *buf2,* curr, *last;
    if(tree->right!=NULL) {
        if(tree->right->value==key) {
    	    if(tree->right->right==NULL && tree->right->left==NULL) {
    			buf=tree->right;
    			tree->right=NULL;
    			buf->left=NULL;
    			buf->right=NULL;
    			delete buf;
    	    }
        }
    }
    if(tree->left!=NULL) {
        if(tree->left->value==key) {
    	    if(tree->left->right==NULL && tree->left->left==NULL) {
    			buf=tree->left;
    			tree->left=NULL;
    			buf->left=NULL;
    			buf->right=NULL;
    			delete buf;
    	    }
        }
    }
    if(tree->value==key) {
        if(tree->right==NULL  && tree->left!=NULL) {
        	buf=dang;
        	dang=dang->left;
            buf->left=NULL;
			delete buf;
          	tree=dang;
            printTree(dang);
        } 
        else {
            if(tree->right!=NULL  && tree->left==NULL) {
            	buf=dang;
            	dang=dang->right;
            	buf->right=NULL;
            	delete buf;
          		tree=dang;
            } 
            else { 
                if(tree->right==NULL  && tree->left==NULL ) {
                    delete dang;
                    dang=NULL;            
                }
                else {
                    dang=tree;
                    buf1=tree->left;
                    buf2=tree->right;
                    curr=tree->right;
                    last=tree;
                    if(curr->left==NULL) {
                    	curr->left=buf1;
                    	dang->left=NULL;
                    	dang->right=NULL;
                    	delete dang;
                    	dang=curr;
                    }
                    else {
                    	while(curr->left!=NULL) {
                    	    last=curr;
                    	    curr=curr->left;
                    	}
                    	last->left=NULL;
                    	curr->left=buf1;
                    	curr->right=buf2;
                    	dang->left=NULL;
                    	dang->right=NULL;
                    	delete dang;
                    	dang=curr;
                    }
                }
            }
        }
	}
	while(dang->value==key) {
	    dang=Process(dang, key);
	}
	tree=dang;
    if(tree->right!=NULL) {
	    dang->right=Process(dang->right, key);
	}
	if(dang->left) {
	    dang->left=Process(dang->left, key);
	}
	
	return dang;
}

int main() {
    TreeNode *tree = NULL;
    int k, value, i, key;
    std::cout << "Введите количество элементов дерева: ";
    std::cin >> k;
    std::cout << "Введите элементы дерева: ";
    for ( i = 0; i < k; i++) {
        std::cin >> value;
        tree = Push(tree, value);
    }
    std::cout << "Введите значение key ";
    std::cin>>key;
    std::cout<<"дерево до функции process:  ";
    printTree(tree);
    tree=Process(tree, key);
    if(tree!=NULL) {
        std::cout<<"\n";
        std::cout<<"дерево после функции process: ";
        printTree(tree);
   		Delltree(tree);
    }
    
    return 1;
}
