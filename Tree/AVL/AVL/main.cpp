/*
���뷽ʽ	����	                                            ��ת��ʽ
LL	       ��a�����������ڵ���������ϲ���ڵ���ƻ�ƽ��	    ����ת
RR	       ��a�����������ڵ���������ϲ���ڵ���ƻ�ƽ��	    ����ת
LR	       ��a�����������ڵ���������ϲ���ڵ���ƻ�ƽ��	    ������������
RL	       ��a�����������ڵ���������ϲ���ڵ���ƻ�ƽ��	    ������������
*/


/* ����
 * @root:��rootΪ���Ľڵ��������
 *
 * �������ǽ�����Ϊ�������ӵ��Һ���
        ���Ǹ��������Ѿ����Һ��ӣ��Ǿ;ͽ�����Һ��ӱ�������������
 * */

Node * Left_Left_rotation(AVLTree k2){
    AVLTree k1;

    k1=k2->lChild;
    k2->rchild=k1->lchild;
    k1->right=k2;

    return k1;
}









 /* ����
 * @root:��rootΪ���Ľڵ��������
 *
 * �������ǽ�����Ϊ�����Һ��ӵ�����
        ���Ǹ����Һ����Ѿ��������ӣ��Ǿͽ�������ӱ����������Һ���
 * */


 Node * Right_Right_rotation(AVLTree k2){
        AVLTree k1;

        k1=k2->rchild;
        k2->rchild=k1->lchild;
        k1->lchild=k2;
 }




/* LR����ת
    ��������������
*/

Node* left_right_rotation(AVLTree k3){
    k3->left = right_right_rotation(k3->left);

    return left_left_rotation(k3);
}


/*
    RL����ת
    ��������������
*/

Node* right_left_rotation(AVLTree k1)
{
    k1->right = left_left_rotation(k1->right);

    return right_right_rotation(k1);
}


