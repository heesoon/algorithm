import java.util.ArrayList;

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
    static int map[][];
    static boolean visited[];
    static long minDistance = 987654321;
    
    static void initialize(){
    
        map = new int[N][N];
        visited = new boolean[N];
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

            map[y][x] = map[x][y] = d;
        }

    }

    static void dfs(int node, long d){
        if(node == 7){
            if(d < minDistance){
                minDistance = d;
            }

            return;
        }

        for(int i = node+1; i < N; i++){
            if(visited[i] == false && map[node][i] != 0){
                visited[i] = true;
                dfs(i, d+map[node][i]);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args){
        initialize();
        dfs(1, 0);
        System.out.println(minDistance);
    }
}