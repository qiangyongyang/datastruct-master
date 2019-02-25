import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/*
 *							5
 *						   / \
                          4   8
                         /   / \
                        3   7   9
                       /   /
                      1   6
                       \
                        2
*/
public class BSTree {
	Node root;

	public BSTree() {
		root = null;
	}

	public void insert(int data) {
		/*Node newNode = new Node(data);
		if (root == null) {
			root = newNode;
		} else {
			Node current = root;
			Node parent;
			while (true) {
				parent = current;
				if (data < current.data) {
					current = current.lchild;
					if (current == null) {
						parent.lchild = newNode;
						return;
					}
				} else {
					current = current.rchild;
					if (current == null) {
						parent.rchild = newNode;
						return;
					}
				}
			}
		}*/
		Node newNode =new Node(data);
		if(root == null){
			root = newNode;
		}else{
			Node current = root;
			Node parent;
			while(true){
				parent = current;
				if(data <current.data){
					current = current.lchild;
					if(current == null){
						parent.lchild = newNode;
						return ;
					}
				}else{
					current = current.rchild;
					if(current == null){
						parent.rchild = newNode;
						return ;
					}
				}
			}
		}
	}

	public void buildBSTree(int[] data) {
		for (int i = 0; i < data.length; i++) {
			insert(data[i]);
		}
	}

	public void PreOrder(Node root) {
		if (root != null) {
			System.out.print(root.data + " ");
			PreOrder(root.lchild);
			PreOrder(root.rchild);
		}
	}

	public void PreOrderWithoutDigui(Node root) {
		Stack<Node> s = new Stack<>();
		Node p = root;
		while (p != null || s.size() > 0) {
			while (p != null) {
				System.out.print(p.data + " ");
				s.push(p);
				p = p.lchild;
			}
			if (s.size() > 0) {
				p = s.peek();
				s.pop();
				p = p.rchild;
			}
		}
	}

	public void InOrder(Node root) {
		if (root != null) {
			InOrder(root.lchild);
			System.out.print(root.data + " ");
			InOrder(root.rchild);
		}
	}

	public void InorderWithoutDigui(Node root) {
		Stack<Node> s = new Stack<>();
		Node p = root;
		while (p != null || s.size() > 0) {
			while (p != null) {
				s.push(p);
				p = p.lchild;
			}
			if (s.size() > 0) {
				p = s.peek();
				System.out.print(p.data + " ");
				s.pop();
				p = p.rchild;
			}
		}
	}

	public void PostOrder(Node root) {
		if (root != null) {
			PostOrder(root.lchild);
			PostOrder(root.rchild);
			System.out.print(root.data + " ");
		}
	}

	public void PostOrderWithoutDigui(Node root) {
		Stack<Node> s = new Stack<>();
		Node cur;
		Node pre = null;
		s.push(root);
		while (!s.empty()) {
			cur = s.peek();
			if ((cur.lchild == null && cur.rchild == null)
					|| (pre != null && (pre == cur.lchild || pre == cur.rchild))) {
				// 如果当前结点没有孩子结点或者孩子节点都已被访问过
				System.out.print(cur.data + " ");
				s.pop();
				pre = cur;
			} else {
				if (cur.rchild != null) {
					s.push(cur.rchild);
				}
				if (cur.lchild != null) {
					s.push(cur.lchild);
				}
			}
		}
	}

	public void transLevel(Node root) {
		Queue<Node> q = new LinkedList<>();
		Node p;
		if (root != null) {
			System.out.print(root.data + " ");
		}
		q.add(root);
		while (!q.isEmpty()) {
			p = q.peek();
			q.poll();
			if (p.lchild != null) {
				System.out.print(p.lchild.data + " ");
				q.add(p.lchild);
			}
			if (p.rchild != null) {
				System.out.print(p.rchild.data + " ");
				q.add(p.rchild);
			}
		}
	}

	public int AllNode(Node root) {
		if (root == null) {
			return 0;
		}
		return 1 + AllNode(root.lchild) + AllNode(root.rchild);
	}

	public int LeafNode(Node root) {
		if (root == null)
			return 0;
		else if (root.lchild == null && root.rchild == null)
			return 1;
		else
			return LeafNode(root.lchild) + LeafNode(root.rchild);
	}

	public int heigh(Node root) {
		if (root == null) {
			return 0;
		}
		return 1 + Math.max(heigh(root.lchild), heigh(root.rchild));
	}

	public static void main(String[] args) {
		BSTree bst = new BSTree();
		int[] data = { 5, 8, 7, 4, 9, 3, 1, 6, 2 };
		bst.buildBSTree(data);
		Node root = bst.root;

		System.out.println("二叉树前序遍历：");
		bst.PreOrder(root);
		System.out.println();

		System.out.println("二叉树前序遍历无递归：");
		bst.PreOrderWithoutDigui(root);
		System.out.println();

		System.out.println("二叉树中序遍历：");
		bst.InOrder(root);
		System.out.println();

		System.out.println("二叉树中序遍历无递归：");
		bst.InorderWithoutDigui(root);
		System.out.println();

		System.out.println("二叉树后序遍历：");
		bst.PostOrder(root);
		System.out.println();

		System.out.println("二叉树后序遍历无递归：");
		bst.PostOrderWithoutDigui(root);
		System.out.println();

		System.out.println("二叉树层次遍历：");
		bst.transLevel(root);
		System.out.println();

		System.out.println("二叉树总结点为：");
		System.out.println(bst.AllNode(root));

		System.out.println("二叉树叶子结点为：");
		System.out.println(bst.LeafNode(root));

		System.out.println("二叉树深度为：");
		System.out.println(bst.heigh(root));
	}

}
