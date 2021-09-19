public class Main{
    final static int Y = 8;
    final static int X = 9;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[][] arr = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    static boolean inside(int y, int x){
        if((x >= 0 && x < X) && (y >= 0 && y < Y)){
            return true;
        }

        return false;
    }

    static void printA1(){
        for(int y = 0; y < Y; y++){
            for(int x = 0; x < X; x++){
                System.out.print(arr[y][x] + " ");
            }
            System.out.println();
        }
    }

    static void solve(int y, int x){
        arr[y][x] = -1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(inside(ny, nx) == true){
                if(arr[ny][nx] == 0){
                    solve(ny, nx);
                }
                else if(arr[ny][nx] > 0){
                    arr[ny][nx]++;
                }
            }
        }
    }

    public static void main(String[] args){
        solve(0, 0);
        printA1();
    }
}