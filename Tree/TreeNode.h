#ifndef NODET_H
#define NODET_H


template <class myType>
class TreeNode
{
    public:
        myType A;
        int FB;
        TreeNode<myType>  *Right;
        TreeNode<myType>  *Left;

    public:
        static TreeNode<myType> *montaNo(myType X)
        {
            TreeNode<myType> *p;
            p = new TreeNode<myType>;
            if(!p) return p;
            p->A = X;
            p->Right = NULL;
            p->Left = NULL;
            p->FB = 0;

            return p;
        }

        static myType desmontaNo(TreeNode<myType> *P)
        {
            myType x = P->A;
            delete P;
            return x;
        }
};

#endif // NODET_H
