#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* p;
    struct node* left;
    struct node* right;
};

typedef struct node *node;

struct bst
{
    node root;
};

typedef struct bst *bst;

node CREATE_NODE(int k)
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->val = k;
    temp->p = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void INSERT(bst T,node x)
{
    node temp = NULL;
    node root = T->root;
    while(root!=NULL)
    {
        temp = root;
        if(x->val<root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    x->p = temp;
    if(temp==NULL)
    {
        T->root = x;
    }
    else if(x->val<temp->val)
    {
        temp->left = x;
    }
    else
    {
        temp->right = x;
    }
}

node MINVALUE(node x)
{
    while(x->left!=NULL)
    {
        x = x->left;
    }
    return x;
}

node MAXVALUE(node x)
{
    while(x->right!=NULL)
    {
        x = x->right;
    }
    return x;
}

void TRANSPLANT(bst T,node a ,node b)
{
    if(a->p==NULL)
    {
        T->root = b;
    }
    else if(a==a->p->left)
    {
        a->p->left = b;
    }
    else
    {
        a->p->right = b;
    }
    if(b!=NULL)
    {
        b->p = a->p;
    }
}

void DELETE(bst T,node x)
{
    node temp = NULL;
    if(x->left==NULL)
    {
        TRANSPLANT(T, x, x->right);
    }
    else if(x->right==NULL)
    {
        TRANSPLANT(T, x, x->left);
    }
    else
    {
        temp = MINVALUE(x->right);
        if(temp->p!=x)
        {
            TRANSPLANT(T, temp, temp->right);
            temp->right = x->right;
            temp->right->p = temp;
        }
        TRANSPLANT(T, x, temp);
        temp->left = x->left;
        temp->left->p = temp;
    }
}

node SEARCH(node root,int k)
{
    if(root==NULL || k==root->val)
    {
        return root;
    }
    else if (k < root->val)
        return SEARCH(root->left, k);
    else
        return SEARCH(root->right, k);
}

int LEVEL(node root,int k,int level)
{
    if(root==NULL)
        return 0;
    if(root->val==k)
        return level;
    if(root->left==NULL && root->right==NULL)
        return 0;
    int Leftlevel = LEVEL(root->left, k, level + 1);
    int Rightlevel = LEVEL(root->right, k, level + 1);

    if(Leftlevel == 0)
        return Rightlevel;
    else
        return Leftlevel;
}

node PREDECESSOR(node x)
{
    if(x->left!=NULL)
    {
        return MAXVALUE(x->left);
    }
    node temp = x->p;
    while(temp!=NULL && x==temp->left)
    {
        x = temp;
        temp = temp->p;
    }
    return temp;
}

node SUCCESSOR(node x)
{
    if(x->right!=NULL)
    {
        return MINVALUE(x->right);
    }
    node temp = x->p;
    while(temp!=NULL && x==temp->right)
    {
        x = temp;
        temp = temp->p;
    }
    return temp;   
}

void INORDER(node root)
{
    if(root!=NULL)
    {
        INORDER(root->left);
        printf("%d ", root->val);
        INORDER(root->right);
    }
}

void PREORDER(node root)
{
    if(root!=NULL)
    {
        printf("%d ",root->val);
        PREORDER(root->left);
        PREORDER(root->right);
    }
}

void POSTORDER(node root)
{
    if(root!=NULL)
    {
        POSTORDER(root->left);
        POSTORDER(root->right);
        printf("%d ", root->val);
    }
}

int main()
{
    char C;
    int k;
    bst T;
    T = NULL;
    T = (bst)malloc(sizeof(struct bst));
    T->root = NULL;
    node x,temp;
    x = temp = NULL;
    while(1)
    {
        scanf("%c", &C);
        switch(C)
        {
            case 'a':
                scanf(" %d", &k);
                x = CREATE_NODE(k);
                INSERT(T, x);
                break;

            case 'd':
                scanf(" %d", &k);
                x = SEArightH(T->root, k);
                if(x==NULL)
                {
                    printf("-1\n");
                }
                else
                {
                    // printf("%d\n", k);
                    DELETE(T, x);
                }
                break;

            case 's':
                scanf(" %d", &k);
                x = SEARCH(T->root, k);
                if(x==NULL)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("1\n");
                }
                break;

            case 'l':
                scanf(" %d", &k);
                x = SEArightH(T->root, k);
                if(x==NULL)
                {
                    printf("-1\n");
                }
                else 
                {
                    printf("%d\n",LEVEL(T->root, k, 1));
                }
                break;

            case 'm':
                x = MINVALUE(T->root);
                printf("%d\n", x->val);
                break;

            case 'x':
                x = MAXVALUE(T->root);
                printf("%d\n", x->val);
                break;

            case 'u':
                scanf(" %d", &k);
                x = SEArightH(T->root, k);
                if(x==NULL)
                {
                    printf("-1\n");
                }
                else
                {
                    temp = SUCCESSOR(x);
                    if(temp==NULL)
                    {
                        printf("-1\n");
                    }
                    else
                        printf("%d\n", temp->val);
                }
                break;

            case 'r':
                scanf(" %d", &k);
                x = SEArightH(T->root, k);
                if(x==NULL)
                {
                    printf("-1\n");
                }
                else
                {
                    temp = PREDECESSOR(x);
                    if(temp==NULL)
                    {
                        printf("-1\n");
                    }
                    else
                        printf("%d\n", temp->val);
                }
                break;

            case 'i':
                INORDER(T->root);
                printf("\n");
                break;

            case 'p':
                PREORDER(T->root);
                printf("\n");
                break;

            case 't':
                POSTORDER(T->root);
                printf("\n");
                break;

            case 'e':
                return 0;
                break;
        }
    }
}