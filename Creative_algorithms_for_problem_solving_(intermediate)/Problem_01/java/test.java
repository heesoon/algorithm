public class Main{
    public static int sumOfDivisor(int n){
        int sum = 0;

        for(int i = 1; i <= n; i++){
            if( (n % i) == 0 ){
                sum += i;
            }
        }

        return sum;
    }
    public static void main(String[] args){
        System.out.println(sumOfDivisor(10));
    }
}