import java.util.ArrayList;

public class Main{
	final static int N = 8;
	static ArrayList<Integer[]> path;

	static void initialize(){
		path = new ArrayList<Integer[]>();
		path.add(new Integer[] {0, 7, 1});
		path.add(new Integer[] {3, 4, 1});
		path.add(new Integer[] {6, 8, 1});
		path.add(new Integer[] {8, 6, 1});
		path.add(new Integer[] {12, 2, 0});
		path.add(new Integer[] {13, 2, 1});
		path.add(new Integer[] {14, 2, 1});
		path.add(new Integer[] {15, 7, 1});
	}

	static boolean ca(int a, int k){
		int pk = path.get(k)[0];
		int pa = path.get(a)[0] + path.get(a)[1];

		if(pk <= pa) 	return true;
		else			return false;
	}

	static boolean cb(int b, int k){
		int pk = path.get(k)[0];
		int pb = path.get(b)[0] + path.get(b)[1];
		int g  = path.get(k)[2];

		if(pk <= pb && g > 0) 	return true;
		else					return false;
	}

	static int solve(int a, int b, int k){
		int c = 0;
		if(k == N-1){
			if(ca(a, k) == true && cb(b, k) == true){
				c = 1;
			}
			else{
				c = 0;
			}
		}
		else{
			if(ca(a, k) == true){
				c += solve(k, b, k+1)%1000;
			}
			if(cb(b, k) == true){
				c += solve(a, k, k+1)%1000;
			}
			c += solve(a, b, k+1)%1000;
		}

		return c;
	}

	public static void main(String[] args){
		initialize();
		System.out.println(solve(0, 0, 1));
	}
}