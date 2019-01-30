
public class Queue {
	Node head = null;
	Node tail = null;

	public boolean isEmpty() {
		return head == tail;
	}

	public void put(int data) {
		Node newNode = new Node(data);
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
	
	public int numHead(){
		if(isEmpty()){
			return -1;
		}
		return head.data;
	}
	
	public int size(){
		Node  temp = head;
		int n = 0;
		while(temp != null){
			n++;
			temp = temp.next;
		}
		return n;
	}
	
	public void print(){
		Node  temp =head;
		while(temp != null){
			System.out.println(temp.data);
			temp = temp.next;
		}
	}
	
	
	public static void main(String[] args) {
		Queue q =new Queue();
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
