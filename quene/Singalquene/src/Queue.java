
public class Queue<E> {
	Node<E> head = null;
	Node<E> tail = null;

	public boolean isEmpty() {
		return head == tail;
	}

	public void put(E data) {
		Node<E> newNode = new Node<E>(data);
		if (head == null && tail == null) {
			System.out.println("队空");
			head = tail = newNode;
		} else {
			tail.next = newNode;
			tail = newNode;
		}
	}

	public void pop() {
		if(isEmpty()){
			return ;
		}
		head = head.next;
	}
	
	public E numHead(){
		if(isEmpty()){
			return null;
		}
		return head.data;
	}
	
	public int size(){
		Node <E> temp = head;
		int n = 0;
		while(temp != null){
			n++;
			temp = temp.next;
		}
		return n;
	}
	
	public void print(){
		Node <E> temp =head;
		while(temp != null){
			System.out.println(temp.data);
			temp = temp.next;
		}
	}
	
	
	public static void main(String[] args) {
		Queue<Integer> q =new Queue<>();
		q.put(1);
		q.put(2);
		q.put(3);
		q.put(4);
		q.put(5);
		
		System.out.println("队列大小："+q.size());
		System.out.println("队头元素："+q.numHead());
		q.print();
	}
	
	
	
	
	
	
	
	
	
	
	
}
