public class Main {
    static int N = 4;
    static int maxWeight = 5;
    static int[] W = {2, 1, 3, 2};
    static int[] V = {3, 2, 3, 2};

    public static int solve(int idx, int rw) {
        if(idx == N) {
            return 0;
        }

        if(W[idx] > rw) {
            return solve(idx+1, rw);
        }
        else {
            return Math.max(solve(idx+1, rw-W[idx]) + V[idx], solve(idx+1, rw));
        }
    }

    public static void main(String[] args) {
        Main t = new Main();
        System.out.println(t.solve(0, t.maxWeight));
    }
}