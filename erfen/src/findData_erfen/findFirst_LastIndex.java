package findData_erfen;

import java.util.Scanner;

public class findFirst_LastIndex {
	static int data[] = { 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4 };

	public static int FirstIndex_erfen(int left, int right, int num) {
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;

			if (num > data[mid]) {
				left = mid + 1;
			} else if (num < data[mid]) {
				right = mid - 1;
			} else {
				
				while (mid - 1 >= 0 && num == data[mid - 1]) {
					mid--;
				}
				return mid;
			}
		}
		return -1;
	}

	public static int LastIndex_erfen(int left, int right, int num) {
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num > data[mid]) {
				left = mid + 1;
			} else if (num < data[mid]) {
				right = mid - 1;
			} else {
				while (mid + 1 <= data.length - 1 && num == data[mid + 1]) {
					mid++;
				}
				return mid;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		while (true) {
			System.out.print("请输入查找的值：");
			Scanner cin = new Scanner(System.in);
			int num = cin.nextInt();
			if (num < data[0] || num > data[data.length - 1]) {
				System.out.println("查询无果");
			} else {
				int FirstIndex = FirstIndex_erfen(0, data.length - 1, num);
				System.out.println("*******第一次出现的位置是：" + FirstIndex);

				int LasttIndex = LastIndex_erfen(0, data.length - 1, num);
				System.out.println("*******最后一次出现的位置是：" + LasttIndex);
			}
		}

	}
}
