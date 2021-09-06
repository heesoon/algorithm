// refer : https://www.delftstack.com/ko/howto/java/how-to-add-new-elements-to-an-array-in-java/
// refer : https://djkeh.github.io/articles/Why-should-final-member-variables-be-conventionally-static-in-Java-kor/
import java.util.ArrayList;
import java.util.Collections;

public class Main{
	public static final int N = 7;
	public static final int[] dx = {1, 0, -1, 0};
	public static final int[] dy = {0, 1, 0, -1};
	public static final int[][] map = {
		{0, 1, 1, 0, 1, 0, 0},
		{0, 1, 1, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 1, 1},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 0, 0, 0}
	};

	public static int depth = 0;

	public static boolean is_in_map(int y, int x){
		if( (y >= 0 && y < N) && (x >= 0 && x < N)){
			return true;
		}

		return false;
	}

	public static void dfs(int y, int x, int c){
		map[y][x] = c;
		depth++;

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(is_in_map(ny, nx) == true && map[ny][nx] == 1){
				dfs(ny, nx, c);
			}
		}
	}

	public static void main(String[] args){
		int count = 1;
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
				if(map[y][x] == 1){
					count++;
					depth = 0;
					dfs(y, x, count);
					result.add(depth);
				}
			}
		}

		Collections.sort(result);

		System.out.println(count-1);
		for(int d : result){
			System.out.print(d + " ");
		}
	}
}