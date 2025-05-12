import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        
        int P = 2 * (W + H);
        int N = Integer.parseInt(br.readLine().trim());
        
        int[] shops = new int[N];
        for (int i = 0; i < N; i++)
        {
            st = new StringTokenizer(br.readLine());
            int dir = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            shops[i] = mapToPerimeter(dir, dist, W, H);
        }
        
        st = new StringTokenizer(br.readLine());
        int guardDir = Integer.parseInt(st.nextToken());
        int guardDist = Integer.parseInt(st.nextToken());
        int guardPos = mapToPerimeter(guardDir, guardDist, W, H);
        
        int total = 0;
        for (int shopPos : shops) {
            int diff = Math.abs(shopPos - guardPos);
            total += Math.min(diff, P - diff);
        }
        
        System.out.println(total);
    }
    
    private static int mapToPerimeter(int direction, int distance, int W, int H) {
        switch (direction) {
            case 1:
                return distance;
            case 2:
                return W + H + (W - distance);
            case 3:
                return W + H + W + (H - distance);
            case 4:
                return W + distance;
            default:
                throw new IllegalArgumentException("Invalid direction: " + direction);
        }
    }
}