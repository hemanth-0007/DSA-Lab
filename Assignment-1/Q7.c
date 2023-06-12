#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct tree
{
    int val;
    struct tree *p;
    struct tree *left;
    struct tree *right;
    int level;
};


struct tree *create_node(int data)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->p = NULL;
    return temp;
}

struct tree *buildTree(struct tree *root, char input[])
{
    // Use gets() function for the input array
    struct tree *temp = NULL;
    char ch;
    int l = 0;
    int y = 0;
    int le;
    int num;
    l = strlen(input);

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
            struct tree *new = (struct tree *)malloc(sizeof(struct tree));
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
// search function returns a pointer to the node of key value val
struct tree  *search(struct tree  *root, int val)
{

    while (root != NULL)
    {

        if (root->val == val)
        {
            return root;
        }
        else if (root->val < val)
        {
            return search(root->right, val);
        }
        return search(root->left, val);
    }

    return NULL;
}

 
 

int main()
{
    struct tree *root = NULL;
    struct tree *temp = NULL;
    
    char input[100000];
    gets(input);
    root = buildTree(root, input);
    int x;
    scanf("%d",&x);
    temp = search(root,x);
    while(temp != NULL){
        temp = temp->p;
            if(temp != NULL)
                printf("%d ",temp->val);
    }


    return 0;
}