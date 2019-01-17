public class BinaryTree {
	Node root;

	public BinaryTree() {
		// TODO Auto-generated constructor stub
		root = null;
	}

	public void InOrder(Node root) {
		if (root != null) {
			InOrder(root.lchild);
			System.out.print(root.data + " ");
			InOrder(root.rchild);
		}
	}
	
	//核心代码
	public static boolean CheckIfSubTree2(Node root1, Node root2) {
		if (root2 == null) {
			return true;
		}

		if (root1 == null) {
			return false;
		}
		
		if (root1.data == root2.data) {
			return CheckIfSubTree2(root1.lchild, root2.lchild)
					&& CheckIfSubTree2(root1.rchild, root2.rchild);
		}else{
			return CheckIfSubTree2(root1.lchild, root2) || CheckIfSubTree2(root1.rchild, root2);
		}
	}
	
	
	
	public static void main(String[] args) {
		Node node1 = new Node(1);
		Node node2 = new Node(2);
		Node node3 = new Node(3);
		Node node4 = new Node(4);
		Node node5 = new Node(5);
		Node node6 = new Node(6);

		Node node7 = new Node(1);
		Node node8 = new Node(2);
		Node node9 = new Node(3);
		
		Node node10 = new Node(1);
		Node node11 = new Node(2);
		Node node12 = new Node(3);

		BinaryTree bt1 = new BinaryTree();
		BinaryTree bt2 = new BinaryTree();
		BinaryTree bt3 = new BinaryTree();

		bt1.root = node1;
		node1.lchild = node2;
		node1.rchild = node3;
		node2.lchild = node4;
		node2.rchild = node5;
		node3.lchild = node6;
		

		System.out.println("bt1中序遍历为：");
		bt1.InOrder(bt1.root);
		System.out.println();

		bt2.root = node7;
		node7.lchild = node8;
		node7.rchild = node9;

		System.out.println("bt2中序遍历为：");
		bt2.InOrder(bt2.root);
		System.out.println();
		
		bt3.root = node10;
		node10.lchild = node12;
		node10.rchild = node11;

		System.out.println("bt3中序遍历为：");
		bt3.InOrder(bt3.root);
		System.out.println();

		System.out.println("bt1与bt2相同吗：" + CheckIfSubTree2(bt1.root, bt2.root));
		System.out.println("bt1与bt3相同吗：" + CheckIfSubTree2(bt1.root, bt3.root));
	}
}
