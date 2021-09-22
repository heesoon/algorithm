import java.util.ArrayList;

public class Main{
	final static int N = 12;
	final static int K = 1;
	static int ans = 87654321;
	static ArrayList<Integer[]> path;
	static int v[] = new int[N];

	static void initialize(){
		path = new ArrayList<Integer[]>();
		path.add(new Integer[]{0, 0});
		path.add(new Integer[]{10, 1000});
		path.add(new Integer[]{20, 1000});
		path.add(new Integer[]{30, 1000});
		path.add(new Integer[]{40, 1000});
		path.add(new Integer[]{5000, 5000});
		path.add(new Integer[]{1000, 60});
		path.add(new Integer[]{1000, 70});
		path.add(new Integer[]{1000, 80});
		path.add(new Integer[]{1000, 90});
		path.add(new Integer[]{7000, 7000});
		path.add(new Integer[]{10000, 10000});
	}

	/*
	static double calc(Integer[] a, Integer[] b){
		double x = Math.pow(a[0] - b[0], 2) + Math.pow(a[1] - b[1], 2);
		return Math.sqrt(x);
	}
	*/

	static double calc(int a, int b){
		double x = Math.pow(path.get(a)[0] - path.get(b)[0], 2) + Math.pow(path.get(a)[1] - path.get(b)[1], 2);
		return Math.sqrt(x);
	}

	static void solve(int idx, int c, double d){
		if(c == K){
			//d = Math.max(d, calc(path.get(idx), path.get(11)));
			d = Math.max(d, calc(idx, 11));
			int x = (int) Math.ceil(d/10);
			if(ans > x){
				ans = x;
			}

			return;
		}

		for(int i = 0; i < N; i++){
			if(v[i] == 0){
				v[i] = 1;
				//solve(i, c+1, Math.max(d, calc(path.get(idx), path.get(i))));
				solve(i, c+1, Math.max(d, calc(idx, i)));
				v[i] = 0;
			}
		}
	}

	public static void main(String[] args){
		initialize();
		v[0] = 1;
		solve(0, 0, 0);
		System.out.println(ans);
	}
}