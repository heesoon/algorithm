import java.util.ArrayList;

public class Main{
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

    static void solve(int digit){
        int start = (int)Math.pow(10, digit-1);
        int end = (int)Math.pow(10, digit);

        for(int x = start; x < end; x++){
            if(check_right_cut_prime(x) == true){
                list.add(x);
            }
        }
    }

    public static void main(String[] args){
        list = new ArrayList<>();
        solve(2);
        System.out.println(list);
        System.out.println(list.size());
    }
}