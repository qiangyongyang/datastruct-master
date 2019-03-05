/*
* 折半查找比顺序查找快，所以折半插入排序就平均性能来说比直接插入排序要快，
* 它所需要的关键码比较次数与待排序记录的初始排列无关，仅依赖与记录个数，比较次数约等于nlogn次。
 * 当n较大时，总关键码比较次数比直接插入比较次数的最坏情况（n平方）/4要好很多，
* 但比其最好情况2（n-1）要差，所以在记录的初始排列已经接近有序时，直接插入排序比折半插入排序执行的关键码比较次数要少
*/
public class HalfInsert {
	public static void sort(int data[]) {
		if (data.length == 0) {
			return;
		}

		for (int i = 1; i < data.length; i++) {
			int left = 0;
			int right = i - 1; // 注意
			int temp = data[i];
			while (left <= right) {
				int mid = (left + right) / 2;
				if (temp < data[mid]) { // 插入值小于中点值
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
			// left即为找到的要插入的位置，所以下边的循环将left-(i-1)位置的元素依次向后移动
			for (int j = i - 1; j >= left; j--) {
				data[j + 1] = data[j];
			}
			data[left] = temp; // 将temp插入到left位置
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
