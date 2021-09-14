import java.util.ArrayList;

class Coordinates{
    public int x;
    public int y;
    public int v;

    Coordinates(int y, int x, int v){
        this.y = y;
        this.x = x;
        this.v = v;
    }
}

public class Main{
    static int map[][];

    static void initialize(){
        ArrayList<Coordinates> data = new ArrayList<Coordinates>();
        data.add(new Coordinates(3, 2, 1));
        data.add(new Coordinates(3, 3, 2));
        data.add(new Coordinates(3, 6, 2));
        data.add(new Coordinates(3, 7, 2));
        data.add(new Coordinates(3, 8, 2));
        data.add(new Coordinates(3, 9, 1));
        data.add(new Coordinates(4, 3, 1));
        data.add(new Coordinates(4, 4, 2));
        data.add(new Coordinates(4, 9, 1));
        data.add(new Coordinates(5, 4, 1));
        data.add(new Coordinates(5, 5, 2));
        data.add(new Coordinates(6, 5, 1));
        data.add(new Coordinates(6, 6, 2));
        data.add(new Coordinates(6, 7, 2));
        data.add(new Coordinates(7, 3, 1));
        data.add(new Coordinates(7, 4, 1));
        data.add(new Coordinates(7, 6, 1));
        data.add(new Coordinates(8, 7, 2));
        data.add(new Coordinates(8, 8, 1));

        map = new int[20][20];

        for(Coordinates crd : data){
            int y = crd.y;
            int x = crd.x;
            int v = crd.v;

            map[y][x] = v;
        }
/*
        for(int y= 0; y < 20; y++){
            for(int x = 0; x < 20; x++){
                System.out.print(map[y][x] + " ");
            }
            System.out.println();
        }
*/
    }

    static boolean is_in_map(int y, int x){
       	if( (x >= 0 && x < 20) && (y >= 0 && y < 20) )
		return true;
	
	    return false;
    }

    static boolean check_right(int y, int x){
        int cnt = 0;

        if(is_in_map(y, x-1) == true && map[y][x-1] == map[y][x]){
            return false;
        }

        for(int i = x; i < 20; i++){
            if(map[y][x] == map[y][i]){
                cnt++;
            }
        }

        if(cnt == 5){
            return true;
        }

        return false;
    }

    static boolean check_right_down(int y, int x){
        int cnt = 0;
        int i = 0;

        if(is_in_map(y-1, x-1) == true && map[y-1][x-1] == map[y][x]){
            return false;
        }

        while((x+i < 20) && (y+i < 20)){
            if(map[y][x] == map[y+i][x+i]){
                cnt++;
            }
            i++;
        }

        if(cnt == 5){
            return true;
        }

        return false;
    }

    static boolean check_right_up(int y, int x){
        int cnt = 0;
        int i = 0;

        if(is_in_map(y+1, x-1) == true && map[y+1][x-1] == map[y][x]){
            return false;
        }

        while((x+i < 20) && (y-i > 0)){
            if(map[y][x] == map[y-i][x+i]){
                cnt++;
            }
            i++;
        }

        if(cnt == 5){
            return true;
        }

        return false;        
    }

    static boolean check_down(int y, int x){
        int cnt = 0;

        if(is_in_map(y-1, x) == true && map[y-1][x] == map[y][x]){
            return false;
        }

        for(int i = y; i < 20; i++){
            if(map[y][x] == map[i][x]){
                cnt++;
            }
        }

        if(cnt == 5){
            return true;
        }

        return false;          
    }

    static boolean solve(int y, int x){
        if(check_right(y, x) == true)
            return true;

        if(check_right_down(y, x) == true)
            return true;

        if(check_right_up(y, x) == true)
            return true;

        if(check_down(y, x) == true)
            return true;

        return false;
    }

    public static void main(String[] args){
        initialize();

        for(int y = 0; y < 20; y++)
        {
            for(int x = 0; x < 20; x++)
            {
                if(map[y][x] != 0)
                {
                    if(solve(y, x) == true)
                    {
                        System.out.println(map[y][x]);
                        System.out.println(y + " " + x);
                    }
                }
            }
        }        
    }
}