import java.util.ArrayList;

class Pair{
	public int y;
	public int x;

	public Pair(int y, int x){
		this.y = y;
		this.x = x;
	}
}

public class Main{
	final static int N = 6;
	static int ans = 87654321;
	static ArrayList<Pair> affair;

	static void initialize(){
		affair = new ArrayList<Pair>();
		affair.add(new Pair(1, 1));
		affair.add(new Pair(6, 6));
		affair.add(new Pair(3, 5));
		affair.add(new Pair(5, 5));
		affair.add(new Pair(2, 3));
	}

	static int distance(Pair a, Pair b){
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}

	static void solve(int a, int b, int d){
		int next = (a > b ? a : b) + 1;
		if(next >= N-1){
			if(ans > d){
				ans = d;
			}

			return;
		}

		solve(next, b, d+distance(affair.get(a), affair.get(next)));
		solve(a, next, d+distance(affair.get(b), affair.get(next)));
	}

	public static void main(String[] args){
		initialize();
		solve(0, 1, 0);
		System.out.println(ans);
	}
}