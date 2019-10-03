import java.util.ArrayList;
import java.util.Collections;

class findDwarf{
	public static void main(String[] args){
		// Time and Memory check
		System.gc();
		long start = System.currentTimeMillis();

		int[] dwarfs = {
			20,
			7,
			23,
			19,
			10,
			15,
			25,
			8,
			13
		};
		
		// summary of Heights
		int totalH = dwarfs[0]+dwarfs[1]+dwarfs[2]+dwarfs[3]+dwarfs[4]+dwarfs[5]+dwarfs[6]+dwarfs[7]+dwarfs[8];

		// check sum
		boolean[] check = new boolean[9];

		ArrayList<Integer> seven = new ArrayList<Integer>();
		int n=9;

		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if((totalH-dwarfs[i]-dwarfs[j])==100){
					check[i] = true;
					check[j] = true;
					break;
				}
			}
		}

		for(int i = 0; i < n; i++){
			if(!check[i]){
				seven.add(dwarfs[i]);
			}
		}

		Collections.sort(seven);

		for(int i = 0; i < n-2; i++){
			System.out.println(seven.get(i));
		}

		long end = System.currentTimeMillis();
		System.out.println((end-start)/1000.0);
		
		long next = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();

		System.out.println(next+"bytes");
	}
}

