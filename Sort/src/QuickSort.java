
public class QuickSort {

	public static void sort(int data[], int left, int right) {
		if (left < right) {
			int i = left;
			int j = right;
			int key = data[left];
			while (i < j) {
				while (i < j && data[j] > key) {
					j--;
				}

				data[i] = data[j];
				while (i < j && data[i] <= key) {
					i++;
				}
				data[j] = data[i];
			}
			data[i] = key;
			sort(data, left, i - 1);
			sort(data, i + 1, right);
		}

	}

	public static void main(String[] args) {
		int data[] = { 38, 65, 27, 15, 13, 97, 49 };
		sort(data, 0, data.length - 1);

		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
