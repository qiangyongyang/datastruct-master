
public class MegerSort {
	static int data1[] = { 38, 65, 97, 76, 13, 27, 49 };
	static int data2[] = new int[data1.length];

	public static void Meger(int left, int mid, int right) {
		int i = left, j = mid + 1, k = left;
		while (i <= mid && j <= right) {
			if (data1[i] < data1[j]) {
				data2[k++] = data1[i++];
			} else {
				data2[k++] = data1[j++];
			}
		}
		if (i > mid) {
			for (int q = i; q <= right; q++) {
				data2[k++] = data1[q];
			}
		} else {
			for (int q = i; q <= mid; q++) {
				data2[k++] = data1[q];
			}
		}

	}

	public static void Copy(int left, int right) {
		for (int i = left; i <= right; i++) {
			data1[i] = data2[i];
		}
	}

	public static void sort(int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			sort(left, mid);
			sort(mid + 1, right);
			Meger(left, mid, right);
			Copy(left, right);
		}
	}

	public static void main(String[] args) {

		sort(0, data1.length - 1);

		for (int i = 0; i < data1.length; i++) {
			System.out.print(data1[i] + " ");
		}
		System.out.println();
	}
}
