public class Stack <E> {
	Node <E> top =null;
	
	public boolean isEmpty(){
		return top == null;
	}
	
	public void push(E data){
		Node <E> newNode = new Node<E>(data);
		newNode.next = top;
		top = newNode;
	}
	
	public void pop (){
		if(this.isEmpty()){
			return ;
		}
		
		top = top.next;
	}
	
	public E numTop(){
		if(isEmpty()){
			return null;
		}
		return top.data;
	}
	
	public void print(){
		while(top != null){
			System.out.println(top.data);
			top = top.next;
		}
	}
	
	public static void main(String[] args) {
		 Stack<Integer> s = new Stack<Integer>();
		 s.push(1);
		 s.push(2);
		 s.push(3);
		 s.push(4);
		
		 System.out.println("栈顶元素是："+s.numTop());
		 s.print();
	}
}













































