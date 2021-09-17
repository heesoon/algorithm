public class Main{
    final static int N = 3;
    final static int[][] table = {
        {1, 5, 3},
        {2, 4, 7},
        {5, 3, 5}
    };

    static boolean[] row_visited = new boolean[3];
    static int minv = 87654321;

    static void f(int r, int s){
        if(r == N){
            if(minv > s){
                minv = s;
            }
            return;
        }

        for(int i = 0; i < N; i++){
            if(row_visited[i] == false){
                row_visited[i] = true;
                f(r+1, s+table[r][i]);
                row_visited[i] = false;
            }
        }
    }

    public static void main(String[] args){
        f(0, 0);
        System.out.println(minv);
    }
}