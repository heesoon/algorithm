public class Main{
    static int cnt = 0;

/*
    static void solve(int n){
        for(int a = n; a >= 1; a--){
            for(int b = a; b >= 1; b--){
                for(int c = b; c >= 1; c--){
                    if(a < b + c){
                        cnt++;
                    }
                }
            }
        }
    }
*/
    static void solve(int n){
        for(int a = 1; a < n; a++){
            for(int b = a; b < n; b++){
                for(int c = b; c < n; c++){
                    if((c < a + b) && (a + b + c == n)){
                        System.out.println(a + ", " + b + ", " + c);
                        cnt++;
                    }
                }
            }
        }
    }

    public static void main(String[] args){
        solve(9);
        System.out.println(cnt);
    }
}