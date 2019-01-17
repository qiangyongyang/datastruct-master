package findData_erfen;

import java.util.Scanner;

public class findData {
	static int count = 0;

	public static int findData(int data[], int num) {

		int mid;
		int left = 0;
		int right = data.length - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			
			if (num == data[mid]) {
				return mid;
			} else if (num > data[mid]) {
				left = left + 1;
			} else if (num < data[mid]) {
				right = right - 1;
			}
			
		}

		return -1;
	}
	
	p
	public static void main(String[] args) {
		int[] data = { 1, 2, 3, 4, 5, 6, 7, 8 };
		while (true) {
			Scanner cin = new Scanner(System.in);
			System.out.print("输入查找的值：");
			int num = cin.nextInt();
			int index = findData(data, num);
			System.out.println("位置在：" + index);
			System.out.println("查找次数为：" + count);
		}

	}
}
