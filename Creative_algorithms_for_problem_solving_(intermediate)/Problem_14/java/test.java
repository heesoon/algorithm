public class Main{
    final static int N = 5;
    final static int need_memory = 60;
    static int min_cost = 87654321;
    final static int[] memory = {30, 10, 20, 35, 40};
    final static int[] cost = {3, 0, 3, 5, 4};

    static int f(int idx, int m){
        System.out.println(idx + ", " + m);
        if(idx >= N){
            if(m >= need_memory){
                return 0;
            }
            else{
                return min_cost;
            }
        }

        if(m >= need_memory){
            return f(idx+1, m);
        }
        else{
            return Math.min(f(idx+1, m+memory[idx]) + cost[idx], f(idx+1, m));
        }
    }

    public static void main(String[] args){
        System.out.println(f(0, 0));
    }
}