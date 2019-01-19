
public class QuickSort {

	public static void sort(int data[], int left, int right) {
		if (left > right) {
			return;
		}
		int i = left;
		int j = right;
		int key = data[left];
		while (i < j) {
			while (i < j && data[j] > key) {
				j--;
			}
			data[i] = data[j];
			while (i < j && data[i] < key) {
				i++;
			}
			data[j] = data[i];
		}
		data[j] = key;

		
		sort(data, left, j - 1);
		sort(data, j + 1, right);
	}

	public static void main(String[] args) {
		int data[] = { 38, 65, 97, 76, 13, 27, 49 };
		sort(data, 0, data.length - 1);

		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
