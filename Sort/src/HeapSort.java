import sun.security.util.Length;

/*
 * 构建大顶堆，实现升序排列
 */
public class HeapSort {


	private static void createHeap(int[] data, int i, int len) {
		int left, right, j;
		while ((left = i * 2 + 1) <= len) {
			right = left + 1;
			j = left;
			if (j < len && data[left] < data[right]) {
				j = right;
			}
			if (data[i] < data[j]) {
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			} else {
				break;
			}
			i = j;
		}
	}

	private static void sort(int[] data) {
		if (data.length == 0) {
			return;
		}
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
