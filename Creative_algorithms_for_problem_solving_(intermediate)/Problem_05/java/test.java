public class Main{
	final static int N = 5;
	final static int dx[] = {1, 0, -1, 0};
	final static int dy[] = {0, 1, 0, -1};
	final static char map[][] = {
		{'#', 'S', '#', '#', '#'},
		{'#', '.', '.', '.', '#'},
		{'#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.'},
		{'#', '#', '#', 'G', '#'}
	};

	static int minDistance = 987654321;
	static boolean visited[][];

	static boolean is_in_map(int y, int x){
		if( (y >= 0 && y < N) && (x >= 0 && x < N) ){
			return true;
		}

		return false;
	}

	static void dfs(int y, int x, int d){
	    
	    //System.out.println("1 : " + x + ", " + y + ", " + d + ", " + map[y][x]);
		if(map[y][x] == 'G'){
		    //System.out.println("G : " + x + ", " + y + ", " + d);
			if(minDistance > d){
				minDistance = d;
				return;
			}
		}

	    //System.out.println( x + ", " + y + ", " + d);
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(is_in_map(ny, nx) == true && (map[ny][nx] == '.' || map[ny][nx] == 'G') && visited[ny][nx] == false){
                visited[ny][nx] = true;
				dfs(ny, nx, d+1);
				visited[ny][nx] = false;
			}
		}
	}

	public static void main(String[] args){
	    visited = new boolean[N][N];
	    
		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
				if(map[y][x] == 'S'){
					dfs(y, x, 0);
				}
			}
		}

		System.out.println(minDistance);
	}
}