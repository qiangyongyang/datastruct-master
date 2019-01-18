package findData_erfen;

import java.util.Scanner;

public class findLikeDataIndex {
	static int data[] = { 1, 2, 3, 5, 5, 5, 7, 8 };

	
	public static int findIndexR(int left, int right, int num) {
		int mid;
		while (left <= right) {
			int middle = (left + right) / 2;
			if (data[middle] > num)
				right = middle - 1;
			else
				left = middle + 1;
		}
		return right + 1;
	}
	

	public static int findIndexL(int left, int right, int num) {
		int mid;
		while (left <= right) {
			int middle = (left + right) / 2;
			if (data[middle] < num)
				left = middle + 1;
			else
				right = middle - 1;
		}
		return left - 1 ;
	}

	
	
	public static void main(String[] args) {
		while (true) {

			System.out.print("请输入查找的值：");
			Scanner cin = new Scanner(System.in);
			int num = cin.nextInt();
			if(num == data[data.length-1]){
				int index2 = findIndexL(0, data.length - 1, num);
				System.out.println("小于且最接近" + num + "的位置是：" + index2);
			}else if(num == data[0]){
				int index1 = findIndexR(0, data.length - 1, num);
				System.out.println("大于且最接近" + num + "的位置是：" + index1);

			}else if (num < data[0] || num > data[data.length - 1]) {
				System.out.println("查询无果");
			}else {
				int index1 = findIndexR(0, data.length - 1, num);
				System.out.println("大于且最接近" + num + "的位置是：" + index1);

				int index2 = findIndexL(0, data.length - 1, num);
				System.out.println("小于且最接近" + num + "的位置是：" + index2);
			}
		}

	}
}
