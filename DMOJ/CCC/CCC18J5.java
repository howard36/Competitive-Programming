import java.util.*;

public class CCC18J5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        adj.add(new ArrayList<Integer>());
        for (int i = 1; i <= n; i++) {
            adj.add(new ArrayList<Integer>());
            int m = input.nextInt();
            for (int j = 0; j < m; j++) {
                int x = input.nextInt();
                adj.get(i).add(x);
            }
        }
        Boolean[] visited = new Boolean[n + 1];
        for (int i = 0; i<visited.length; i++){
            visited[i] = false;
        }
        visited[1] = true;

        ArrayList<ArrayList<Integer>> level = new ArrayList<ArrayList<Integer>>();
        level.add(new ArrayList<Integer>());
        level.add(new ArrayList<Integer>());
        level.get(1).add(1);
        int shortest = -1;
        for (int l = 1; l <= n; l++) {
            level.add(new ArrayList<Integer>());
            for (int page : level.get(l)) {
                if (adj.get(page).size() == 0 && shortest == -1) {
                    shortest = l;
                }
                for (int next : adj.get(page)) {
                    if (!visited[next]) {
                        visited[next] = true;
                        level.get(l+1).add(next);
                    }
                }
            }
        }
        Boolean allVisited = true;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == false)
                allVisited = false;
        }
        if (allVisited) {
            System.out.println("Y");
        } else {
            System.out.println("N");
        }
        System.out.println(shortest);
    }
}