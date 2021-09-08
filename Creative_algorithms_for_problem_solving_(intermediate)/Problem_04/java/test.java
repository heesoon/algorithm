
public class Main{
	final static int N = 4;
	static int col[];
	static int dec[];
	static int inc[];
	static int cnt = 0;

	static void initialize(){
		col = new int[N];
		inc = new int[2*N];
		dec = new int[2*N];
	}

	static void solve(int y){
		if(y == N){
			cnt++;
			return;
		}

		for(int x = 0; x < N; x++){
			if(col[x] == 0 && dec[3 + y - x] == 0 && inc[x + y] == 0){
				col[x] = dec[3 + y - x] = inc[x+y] = 1;
				solve(y+1);
				col[x] = dec[3 + y - x] = inc[x+y] = 0;			
			}
		}
	}

	public static void main(String[] args){
		initialize();
		solve(0);
		System.out.println(cnt);
	}
}