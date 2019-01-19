public class HeapSort {

	public static void createHeap(int data[], int i, int len) {
		int left, right, j;
		while ((left = 2 * i + 1) <= len) { // 判断当前父节点有无左节点（即有无孩子节点，left为左节点）
			right = left + 1; // 右节点
			
			j = left; // j"指针指向左节点"
			if (j < len && data[left] < data[right]) // 左节点大于右节点
				j++; // 当前把"指针"指向右节点
			if (data[i] < data[j]) { // 将父节点与孩子节点交换（如果上面if为真，则data[j]为右节点，如果为假data[j]则为左节点）
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			} else // 说明比孩子节点都大，直接跳出循环语句
				break;
			i = j;
		}
	}

	public static void sort(int data[]) {
		for (int i = data.length / 2 - 1; i >= 0; i--) {
			createHeap(data, i, data.length - 1);
		}

		for (int i = data.length - 1; i >= 0; i--) {
			int temp = data[0];
			data[0] = data[i];
			data[i] = temp;
			createHeap(data, 0, i - 1);
		}
	}

	public static void main(String[] args) {
		int data[] = { 38, 65, 97, 76, 13, 27, 49 };
		sort(data);

		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
