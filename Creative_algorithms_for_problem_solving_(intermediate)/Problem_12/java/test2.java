import java.util.ArrayList;

public class Main{
    final static int N = 2;
    static ArrayList<Integer> list;

    static boolean check_prime(int n){
        if(n == 1){
            return false;
        }

        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }

        return true;
    }

    static boolean check_right_cut_prime(int n){
        while(n > 0){
            if(check_prime(n) == false){
                return false;
            }
            n = n / 10;
        }

        return true;
    }

    static void solve(int num, int digit){
        if(digit == N){
            if(check_right_cut_prime(num) == true){
                list.add(num);
            }
            return;
        }

        for(int i = 1; i <= 9; i++){
            solve(num*10 + i, digit+1);
        }
    }

    public static void main(String[] args){
        list = new ArrayList<>();
        solve(0, 0);
        System.out.println(list);
        System.out.println(list.size());
    }
}