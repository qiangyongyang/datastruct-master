/*	
   希尔排序又称为缩小增量排序，基本思想是分组的直接插入排序。:
  1.将一个数据序列分成若干组，每组由若干相隔一段距离（称为增量）的元素组成.
        在一个组内采用直接插入排序算法进行排序。
  2.增量初值通常为数据序列长度的一半，以后每趟增量减半，最后值为1。
 	随着增量逐渐减小，组数也减小，组内元素个数增加，数据序列接近有序。
*/
public class ShellSort {

	public static void sort(int data[]) {
		if (data.length == 0) {
			return;
		}
		int j;
		for (int d = data.length / 2; d > 0; d = d / 2) {
			System.out.println("d= " + d);
			
			for (int i = d; i < data.length; i++) {
				int temp = data[i];
				
				for (j = i - d; j >= 0; j = j - d) {
					if (temp < data[j]){
						data[j + d] = data[j];
					}else{
						break;
					}
						
				}
				data[j + d] = temp;
			}
		}
	}
	/*（1）最外层循环for语句以增量d变化控制进行若干趟扫描，d的初值为序列长度的一半，以后每趟减半，直至为1；

	（2）中间for循环进行一趟扫描，序列分为d组，每组由相距为d远的n/d个元素组成，每组元素分别进行直接插入排序；

	（3）最内层循环for语句进行一组直接插入排序，将一个data[i]插入到其所在组前面的排序子序列中。*/


	
	public static void main(String[] args) {
		int data[] = { 3, 4, 0, 1, 2, 5 };
		sort(data);
		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
		System.out.println();
	}
}
