public class Main{
    final static int N = 8;
    static int ans = 87654321;
    static int end = 0;
    static int[] num = new int[N];

    static boolean same(int a, int b){
        //System.out.println("yy" + a + ", " + b);
        int i;
        for(i = a; i < b; i++){
            if(num[i] != num[b - a + i]){
                break;
            }
        }

        return (a == b ? false : i == b);
    }

    static int good(int idx){
        int i, j;
        //System.out.println(idx + ", " + num[idx]);
        for(i = idx-1, j = idx; i > 0; i -= 2, j -= 1){
            //System.out.println("-> " + i + ", " + j);
            if(same(i, j) == true){
                //System.out.println("yy" + idx + ", " + num[idx]);
                return 0;
            }
        }

        return 1;
    }

    static void solve(int idx){
        if(end == 1){
            return;
        }

        if(idx >= N){
            end = 1;
            for(int i = 1; i < N; i++){
                System.out.print(num[i]);
            }
            System.out.println();
            return;
        }

        for(int i = 1; i <= 3; i++){
            num[idx] = i;
            if(good(idx) == 1) solve(idx+1);
        }
    }

    public static void main(String[] args){
        solve(1);
        //System.out.println(ans);
    }
}