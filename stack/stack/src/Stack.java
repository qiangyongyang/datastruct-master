public class Stack {
	Node  top =null;
	
	public boolean isEmpty(){
		return top == null;
	}
	
	public void push(int data){
		Node  newNode = new Node(data);
		newNode.next = top;
		top = newNode;
	}
	
	public void pop (){
		if(this.isEmpty()){
			return ;
		}
		
		top = top.next;
	}
	
	public int numTop(){
		if(isEmpty()){
			return -1;
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
		 Stack s = new Stack();
		 s.push(1);
		 s.push(2);
		 s.push(3);
		 s.push(4);
		
		 System.out.println("栈顶元素是："+s.numTop());
		 s.print();
	}
}













































