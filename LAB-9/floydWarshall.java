import java.util.Scanner;
import java.lang.Integer;

public class floydWarshall {
  public static final int INF = Integer.MAX_VALUE;

  static void print(Object obj){
    System.out.print(obj);
  }

  static void println(Object obj){
    System.out.println(obj);
  }

  static int add(int x, int y){
    if (x == INF || y == INF) return INF;
    return x + y;
  }

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    println("Total number of vertices: ");
    int v = sc.nextInt();
    int [][] dist = new int[v][v];
  
    for(int i = 0; i < v; i++){
      for(int j = 0; j < v; j++){
        if(i == j) dist[i][i] = 0;
        else dist[i][j] = INF;
      }
    }

    println("Total number of edges: ");
    int e = sc.nextInt();

    print("Enter the edges and their respective distances: (eg: a b 11)\n");
    for(int i = 0; i < e; i++){
      System.out.print("Edge " + (i + 1) + ": ");
      char firstV = Character.toLowerCase(sc.next().charAt(0)), secondV = Character.toLowerCase(sc.next().charAt(0));
      int w = sc.nextInt(), a = firstV - 'a', b = secondV - 'a';
      dist[a][b] = w;
    }

    for (int k = 0; k < v; k++) {
      for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
          int newDistance = add(dist[i][k], dist[k][j]);
          if(newDistance < dist[i][j]){
            dist[i][j] = newDistance;
          }
        }
      }
    }


    println("\nShortest distances between every pair of vertices:");
    for (int i = 0; i < v; i++) {
      char source = (char) ('a' + i);
      
      for (int j = 0; j < v; j++) {
        char destination = (char) ('a' + j);
        
        if (dist[i][j] == INF) println(source + " → " + destination + " : NO PATH (INF)");
        else println(source + " → " + destination + " : " + dist[i][j]);
      }
      println("─────────────────────────────");
    }

    sc.close();
  }
}
