#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int val;
    struct node *p;
    struct node *left;
    struct node *right;
    int level;
};
// Building the Binary tree from parenthesis
struct node *buildTree(struct node *root, char *input)
{
    struct node *temp = NULL;
    char ch;
    int l = strlen(input);
    int y = 0;
    int le;
    int num;

    for (int i = 0; i < l; i++)
    {
        if (input[i] >= 48 && input[i] <= 57)
        {
            num = 0;
            while (input[i] != ' ')
            {
                num += (input[i] - 48);
                num *= 10;
                i++;
            }
            num /= 10;
            struct node *new;
            new = (struct node *)malloc(sizeof(struct node));
            new->val = num;
            new->p = NULL;
            new->left = NULL;
            new->right = NULL;
            new->level = 0;
            if (root == NULL)
            {
                root = new;
                root->level = 1;
            }
            else
            {
                if (y == 0)
                    temp->left = new;
                else
                {
                    temp->right = new;
                    y = 0;
                }
            }
            new->p = temp;
            temp = new;
            le = 0;
            while (temp != NULL)
            {
                temp = temp->p;
                le++;
            }
            new->level = le;
            temp = new;
        }
        else if (input[i] == ')')
        {
            y++;
            if (y == 2)
                temp = temp->p;
            if (y > 2)
            {
                if (temp != NULL)
                {
                    if (temp->left != NULL && temp->right != NULL)
                        temp = temp->p;
                    else
                        y = 1;
                }
            }
        }
        else
            continue;
    }
    return root;
}
// printing the descendants at a depth d from rootnode
void print_dec(struct node *root, int d)
{

    if (root != NULL)
    {
        print_dec(root->left, d);
        if (root->level == d)
        {
            printf("%d ", root->val);
        }

        print_dec(root->right, d);
    }
}
//Function for binary Tree Search 
struct node *search(struct node *root, int key)
{
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;

    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == key)
    {
        return root;
    }
    temp1 = search(root->left, key);
    temp2 = search(root->right, key);
    return temp1 == NULL ? temp2 : temp1;
}

int main()
{
    int x, d;
    char inputString[100000];
    struct node *rootNode = NULL;
    struct node *temp = NULL;

    scanf("%[^\n]", inputString);
    scanf(" %d", &x);                            // x --> The key value of the node
    scanf("%d", &d);                             // d --> Denotes the distance of the descendents to be printed from node with key value x
    rootNode = buildTree(rootNode, inputString); // Returns a tree build
   
    temp = search(rootNode, x);
    if(temp == NULL){
        printf("No Found the key in the tree");
        return 0;
    }
    print_dec(rootNode, d + temp->level);       // Prints the decsendents from that x node
    return 0;
}
