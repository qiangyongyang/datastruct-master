/*
插入方式	描述	                                            旋转方式
LL	       在a的左子树根节点的左子树上插入节点而破坏平衡	    右旋转
RR	       在a的右子树根节点的右子树上插入节点而破坏平衡	    左旋转
LR	       在a的左子树根节点的右子树上插入节点而破坏平衡	    先左旋后右旋
RL	       在a的右子树根节点的左子树上插入节点而破坏平衡	    先右旋后左旋
*/


/* 右旋
 * @root:以root为根的节点进行右旋
 *
 * 右旋即是将根降为根的左孩子的右孩子
        若是根的左孩子已经有右孩子，那就就将这个右孩子变成上面根的左孩子
 * */

Node * Left_Left_rotation(AVLTree k2){
    AVLTree k1;

    k1=k2->lChild;
    k2->rchild=k1->lchild;
    k1->right=k2;

    return k1;
}









 /* 左旋
 * @root:以root为根的节点进行左旋
 *
 * 左旋即是将根降为根的右孩子的左孩子
        若是根的右孩子已经有了左孩子，那就将这个左孩子变成上面根的右孩子
 * */


 Node * Right_Right_rotation(AVLTree k2){
        AVLTree k1;

        k1=k2->rchild;
        k2->rchild=k1->lchild;
        k1->lchild=k2;
 }




/* LR的旋转
    先左旋，后右旋
*/

Node* left_right_rotation(AVLTree k3){
    k3->left = right_right_rotation(k3->left);

    return left_left_rotation(k3);
}


/*
    RL的旋转
    先右旋，后左旋
*/

Node* right_left_rotation(AVLTree k1)
{
    k1->right = left_left_rotation(k1->right);

    return right_right_rotation(k1);
}


