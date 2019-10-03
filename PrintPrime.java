import java.util.Scanner;

class PrintPrime{	
	public static void main(String[] args){
		int m=3;
		int n=16;
		boolean[] check = new boolean[n+1];
		int[] prime = new int[n-1];
		int count = 0;

		for(int i=2; i<=n; i++){
			if(!check[i]){
				prime[count++]=i;

				for(int j=i*i; j<=n; j+=i){
					check[j]=true;
				}	
			}
		}
		
		for(int i=0; i<count; i++){
			if(prime[i] >= m){
				System.out.println(prime[i]);
			}
		}
	}
}
