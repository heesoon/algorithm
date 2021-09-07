//refer : https://www.geeksforgeeks.org/collections-sort-java-examples/

import java.util.LinkedList;
import java.util.Collections;

class Coordinate {
	public int x;
	public int y;

	Coordinate(int y, int x){
		this.y = y;
		this.x = x;
	}
};

public class Main{
	static final int N = 7;
	static final int[] dx = {1, 0, -1, 0};
	static final int[] dy = {0, 1, 0, -1};
	static final int[][] map = {
		{0, 1, 1, 0, 1, 0, 0},
		{0, 1, 1, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 1, 1},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 0, 0, 0}
	};

	static int roof = 1;
	static int count = 0;

	static boolean is_in_map(int y, int x){
		if( (y >= 0 && y < N) && (x >= 0 && x < N)){
			return true;
		}

		return false;
	}

	static void bfs(int y, int x, int c){
		LinkedList<Coordinate> queue = new LinkedList<Coordinate>();
		queue.add(new Coordinate(y, x));
        map[y][x] = c;
        
		while(queue.size() != 0){
			Coordinate xy = queue.getFirst();
			queue.removeFirst();
			count++;

			for(int i = 0; i < 4; i++){
				int ny = xy.y + dy[i];
				int nx = xy.x + dx[i];

				if(is_in_map(ny, nx) == true && map[ny][nx] == 1){
				    map[ny][nx] = c;
					queue.addLast(new Coordinate(ny, nx));
				}
			}
		}
	}

	public static void main(String[] args){
		LinkedList<Integer> result = new LinkedList<Integer>();

		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
				if(map[y][x] == 1){
					count = 0;
					roof++;
					bfs(y, x, roof);
					result.add(count);
				}
			}
		}

		Collections.sort(result, Collections.reverseOrder());

		System.out.println(roof - 1);
		for(int d : result){
			System.out.print(d + " ");
		}
		System.out.println();
		
		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
                    System.out.print(map[y][x] + " ");
			}
			System.out.println();
		}		
	}
}