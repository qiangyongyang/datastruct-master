/*
 *1.从第一个元素开始，该元素可以认为已经被排序
 *2.取出下一个元素，在已经排序的元素序列中从后向前扫描
 *3.如果该元素（已排序）大于新元素，将该元素移到下一位置
 *4.重复步骤 3，直到找到已排序的元素小于或者等于新元素的位置
 *5.将新元素插入到该位置后
 *6.重复步骤 2~5
*/
public class DirectlyInsert {
	public static void sort(int data[]) {
		if(data.length == 0 || data == null){
			return ;
		}

		int j;
		for (int i = 1; i < data.length; i++) {
			int temp = data[i]; // 每趟将data[i]插入到前面的排序子序列中
			for (j = i - 1; j >= 0 && data[j] > temp; j--) {
				// 将前面较大的元素向后移动
				data[j + 1] = data[j];
			}
			data[j + 1] = temp; // temp值到达插入位
		}
	}

	public static void main(String[] args) {
		int data[] = { 5, 8, 9, 6, 4, 2, 3, 1, 3, 2, 6, 0 };
		sort(data);
		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
