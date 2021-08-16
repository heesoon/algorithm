public class Main {

	int H = 3;
	int W = 4;
	int cnt = 0;
	
	public void solve(int h, int w){
		if(h > H || w > W+1){
			return;
		}
		
		if(h == H && w == W+1){
			cnt++;
			return;
		}

		solve(h+1, w);
		
		if((double)H/W <= (double)h/w){
			solve(h, w+1);
		}
	}

	public static void main(String[] args){
		Main test = new Main();
		
		test.solve(0, 1);
		System.out.println(test.cnt);
	}
}