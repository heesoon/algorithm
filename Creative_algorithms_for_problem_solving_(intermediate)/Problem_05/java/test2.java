package com.company;

import java.util.LinkedList;
import java.util.Collection;

class Coordinates{
    public int x;
    public int y;
    public Coordinates(int y, int x){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    final static int N = 5;
    final static int dx[] = {1, 0, -1, 0};
    final static int dy[] = {0, 1, 0, -1};
    final static char map[][] = {
            {'#', 'S', '#', '#', '#'},
            {'#', '.', '.', '.', '#'},
            {'#', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '.'},
            {'#', '#', '#', 'G', '#'}
    };

    static int visited[][];

    static boolean is_in_map(int y, int x){
        if( (y >= 0 && y < N) && (x >= 0 && x < N) ){
            return true;
        }

        return false;
    }

    static int bfs(int y, int x){
        int result = 87654321;
        LinkedList<Coordinates> queue = new LinkedList<Coordinates>();
        visited[y][x] = 0;
        queue.add(new Coordinates(y, x));

        while(queue.size() != 0){
            Coordinates xy = queue.getFirst();
            queue.removeFirst();

            if(map[xy.y][xy.x] == 'G'){
                result = visited[xy.y][xy.x];
            }

            for(int i = 0; i < 4; i++){
                int ny = xy.y + dy[i];
                int nx = xy.x + dx[i];

                if(is_in_map(ny, nx) == true && visited[ny][nx] == 0 && (map[ny][nx] == 'G' || map[ny][nx] == '.')){
                    visited[ny][nx] = visited[xy.y][xy.x] + 1;
                    queue.addLast(new Coordinates(ny, nx));
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        visited = new int[N][N];

        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(map[y][x] == 'S'){
                    System.out.println(bfs(y, x));
                }
            }
        }
    }
}
