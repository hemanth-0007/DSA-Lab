#include <stdio.h>
#include <stdlib.h>
// Q3 Oriignal Code 
struct tree
{
    int val;
    struct tree *p;
    struct tree *left;
    struct tree *right;
    int level;
};
int sumT = 0;
void postOrder(struct tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->val);
    }
}

int calculateSum(struct tree *temp)
{
    int sum, sumLeft, sumRight;
    sum = sumRight = sumLeft = 0;

    // Check whether tree is empty
    if (temp == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }
    else
    {
        // Calculate the sum of nodes present in left subtree
        if (temp->left != NULL)
            sumLeft = calculateSum(temp->left);

        // Calculate the sum of nodes present in right subtree
        if (temp->right != NULL)
            sumRight = calculateSum(temp->right);

        // Calculate the sum of all nodes by adding sumLeft, sumRight and root node's data
        sum = temp->val + sumLeft + sumRight;
        return sum;
    }
}

int calculateNoOfTrees(struct tree *root, int sum)
{
    if (root != NULL)
    {
        calculateNoOfTrees(root->left, sum);
        if (calculateSum(root) == sum)
        {
            sumT++;
        }
        calculateNoOfTrees(root->right, sum);
    }
    return sumT;
}


struct tree *buildTree(struct tree *root)
{
    struct tree *temp = NULL;
    char *input = (char *)malloc(0 * sizeof(char));
    char ch;
    int l = 0;
    int y = 0;
    int le;
    int num;
    while (scanf("%c", &ch))
    {
        if (ch == '\n')
            break;
        l++;
        input = (char *)realloc(input, l * sizeof(char));
        input[l - 1] = ch;
    }

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

int main()
{
    struct tree *root = NULL;
    root = buildTree(root);
    int sum;
    scanf("%d", &sum);
    printf("%d", calculateNoOfTrees(root, sum));
    return 0;
}