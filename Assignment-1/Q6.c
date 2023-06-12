#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *p;
    struct node *left;
    struct node *right;
    int level;
};

struct node *buildTree(struct node *root)
{
    struct node *temp = NULL;
    char *input;
    input = (char *)malloc(1 * sizeof(char));
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
            // important thing in the building of the bst from parenthesis

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

// Fucntion to print the required result of numbers inclusive of x and y
void printOrder(struct node *root, int x, int y)
{
    if (root != NULL)
    {
        printOrder(root->left, x, y);
        if (x <= root->val && root->val <= y)
            printf("%d ", root->val);
        printOrder(root->right, x, y);
    }
}


int main()
{
    struct node *a = NULL;
    a = buildTree(a);
    int x, y;
    scanf("%d %d", &x, &y);
    printOrder(a, x, y);// Printing the numbers in the tree inclusive of both x and y

    return 0;
}
