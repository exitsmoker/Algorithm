import java.io.*;
import java.util.Map;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class Main {
	public static void main(String[] args) throws Exception {
        boolean check = false;

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();
      	String tempS = sc.nextLine();
		String[] tempSS = tempS.split(" ");
		
        Map<String, Integer> map = new HashMap<>();

        for (String a : tempSS) {
            if (map.containsKey(a)) {
                map.replace(a, map.get(a) + 1);
            } else {
                map.put(a, 1);
            }
        }

        for (Map.Entry<String,Integer> entry : map.entrySet()) {
            int temp = 1 << entry.getValue();
            for (Map.Entry<String,Integer> entry2 : map.entrySet()) {
                if (entry2.getKey() == entry.getKey()){
                    continue;
                }
                temp = temp & (1 << (entry2.getValue() - 1));
            }
            if (temp > 0){
                check = true;
                map.replace(entry.getKey(), entry.getValue()+1);
                n += 1;
                break;
            }
        }
        if (check){
            System.out.println("Y");
        }
        else {
            System.out.println("N");
        }
        System.out.println(n);
        System.out.println(map.size());
	}
}