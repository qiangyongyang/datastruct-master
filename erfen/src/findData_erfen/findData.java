package findData_erfen;

import java.util.Scanner;

public class findData {
	static int[] data = { 1, 2, 2, 2, 2, 6, 7, 8 };

	public static int findData(int left, int right, int num) {
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num == data[mid]) {
				return mid;
			} else if (num > data[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}

	public static int erfen(int left, int right, int num) {
		int mid = (left + right) / 2;
		if (left > right) {
			return -1;
		}

		if (num == data[mid]) {
			return mid;
		} else if (num < data[mid]) {
			return erfen(left, mid - 1, num);
		} else if (num > data[mid]) {
			return erfen(mid + 1, right, num);
		}
		return -1;
	}

	public static void main(String[] args) {
		while (true) {
			Scanner cin = new Scanner(System.in);
			System.out.print("输入查找的值：");
			int num = cin.nextInt();
			if (num < data[0] || num > data[data.length - 1]) {
				System.out.println("查询无果");
			} else {
				int index1 = findData(0, data.length - 1, num);
				System.out.println("（无递归）" + "位置在：" + index1);

				int index2 = erfen(0, data.length, num);
				System.out.println("（递归）" + "位置在：" + index2);
			}
		}

	}
}
