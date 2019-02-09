
public class BubbleSort {

	public static void sort(int data[]) {
		if (data.length == 0) {
			return;
		}
		for (int i = 0; i < data.length; i++) {
			int swap = 0; // 设置未发生交换标志
			for (int j = i; j <data.length - i - 1; j++) {
				if (data[j] > data[j+1]) {
					int temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
					swap = 1;			 // 有交换发生
				}
			}
			if (swap == 0) {			// 本次未出现交换 
				break;
			}
		}

	}

	public static void main(String[] args) {
		int data[] = { 1, 2, 3, 5, 4 };
		sort(data);
		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
