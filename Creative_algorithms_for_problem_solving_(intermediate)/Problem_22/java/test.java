public class Main {

	static int[] W = {1, 3, 9, 27, 81, 243, 729};
	static int[] T = {25, 40};
	static int chk[];

    public static void solve(int idx, int l, int r, int t) {
		if(idx == W.length){
			if(l == r){
				//System.out.println(t + " ");
				System.out.printf(t + " ");
				for(int i = 0; i < W.length; i++){
					//if(chk[i] == 1) System.out.println(W[i] + " ");
					if(chk[i] == 1) System.out.printf(W[i] + " ");
				}
			
				//System.out.println(0 + " ");
				System.out.printf(0 + " ");
				for(int i = 0; i < W.length; i++){
					//if(chk[i] == 2) System.out.println(W[i] + " ");
					if(chk[i] == 2) System.out.printf(W[i] + " ");
				}
				
				System.out.println();
			}
			return;
		}
		
		chk[idx] = 1;
		solve(idx+1, l+W[idx], r, t);
		
		chk[idx] = 2;
		solve(idx+1, l, r+W[idx], t);

		chk[idx] = 0;
		solve(idx+1, l, r, t);
    }
	
	public static void initialize(){
		chk = new int[W.length];
	}

    public static void main(String[] args) {
		
		Main m = new Main();
		for(int i = 0; i < T.length; i++){
			m.initialize();
			m.solve(0, m.T[i], 0, m.T[i]);
		}
    }
}