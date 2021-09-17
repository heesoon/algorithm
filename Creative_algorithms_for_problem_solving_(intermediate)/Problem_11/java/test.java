import java.util.LinkedList;

class Pair{
    public int v;
    public int c;

    Pair(int v, int c){
        this.v = v;
        this.c = c;
    }
}

public class Main{
    final static int target = 34;
    static int solve(int v, int c){
        int retval = 0;
        LinkedList<Pair> queue = new LinkedList<>();
        queue.add(new Pair(v, c));

        while(queue.size() > 0){
            Pair p = queue.getFirst();
            queue.removeFirst();

            if(p.v == target){
                retval = p.c;
                break;
            }
            else if(p.v < target){
                queue.addLast(new Pair(p.v + 10, p.c + 1));
                queue.addLast(new Pair(p.v + 5, p.c + 1));
                queue.addLast(new Pair(p.v + 1, p.c + 1));
            }
            else{
                queue.addLast(new Pair(p.v - 10, p.c + 1));
                queue.addLast(new Pair(p.v - 5, p.c + 1));
                queue.addLast(new Pair(p.v - 1, p.c + 1));                
            }
        }

        return retval;
    }

    public static void main(String[] args){
        System.out.println(solve(7, 0));
    }
}