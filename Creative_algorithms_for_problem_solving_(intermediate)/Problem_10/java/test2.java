import java.util.ArrayList;
import java.util.LinkedList;

class Coordinates{
    public int y;
    public int x;
    public int d;

    Coordinates(int y, int x, int d){
        this.y = y;
        this.x = x;
        this.d = d;
    }
}

public class Main{
    final static int N = 8;
    static int[][] distance;
    static long[][] calcDistance;
    static ArrayList<Integer>[] map = new ArrayList[N];
    static boolean[] visited;
    static long minDistance = 987654321;
    
    static void initialize(){
    
        distance = new int[N][N];
        calcDistance = new long[N][N];
        visited = new boolean[N];

        for(int i = 0; i < N; i++){
            map[i] = new ArrayList<Integer>();
        }
    
        ArrayList<Coordinates> data = new ArrayList<Coordinates>();
        data.add(new Coordinates(1, 2, 47));
        data.add(new Coordinates(1, 3, 69));
        data.add(new Coordinates(2, 4, 57));
        data.add(new Coordinates(2, 5, 124));
        data.add(new Coordinates(3, 4, 37));
        data.add(new Coordinates(3, 5, 59));
        data.add(new Coordinates(3, 6, 86));
        data.add(new Coordinates(4, 6, 27));
        data.add(new Coordinates(4, 7, 94));
        data.add(new Coordinates(5, 7, 21));
        data.add(new Coordinates(6, 7, 40));
        for(Coordinates v : data){
            int y = v.y;
            int x = v.x;
            int d = v.d;

            distance[y][x] = distance[x][y] = d;
            map[y].add(x);
        }
    }

    static void bfs(int node){
        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.add(node);
        visited[node] = true;
        
        int prev = 0;
        while(queue.size() > 0){
            int n = queue.getFirst();
            queue.removeFirst();

            if(n == 7){
                if(minDistance > calcDistance[prev][n]){
                    minDistance = calcDistance[prev][n];
                }
            }

            for(int nn : map[n]){
                if(visited[nn] == false){
                    visited[nn] = true;
                    calcDistance[n][nn] += distance[n][nn];
                    prev = n;
                    queue.addLast(nn);
                }
            }
        }
    }

    public static void main(String[] args){
        initialize();
        bfs(1);
        System.out.println(minDistance);
    }
}