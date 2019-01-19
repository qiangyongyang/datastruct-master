/*
 * 选择排序（Selection sort）是一种简单直观的排序算法。 它的工作原理如下: 
 * 首先在未排序序列中找到最小元素，与第一个元素进行交换位置
 * 然后，再从剩余未排序元素中继续寻找最小（大）元素，与第二个元素交换位置。 
 * 以此类推，直到所有元素均排序完毕。
 */
public class SelectSort {
	public static void sort(int data[]) {
		if (data.length == 0) {
			return;
		}

		int flag = 0;
		for (int i = 0; i < data.length; i++) {
			int temp = data[i];
			for (int j = i + 1; j < data.length; j++) {
				if (temp > data[j]) {
					temp = data[j];
					flag = j;
				}
			}
			
			//进行交换，如果位置发生变化，则进行交换
			if (flag != i) {
				data[flag] = data[i];
				data[i] = temp;
			}
		}

	}

	public static void main(String[] args) {
		int data[] = { 5, 8, 9, 6, 4, 2, 3, 1, 3, 2, 6 };
		sort(data);
		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
