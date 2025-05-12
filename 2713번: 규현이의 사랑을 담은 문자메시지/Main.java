import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main
{
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    
    public static void main(String ... args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder output = new StringBuilder();
        
        while (T-- > 0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ", false);
            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            String msg = st.nextToken("");
            if (msg.startsWith(" "))
            {
                msg = msg.substring(1);
            }
            
            StringBuilder bits = new StringBuilder();
            for (char ch : msg.toCharArray())
            {
                int val = (ch == ' ' ? 0 : ch - 'A' + 1);
                for (int b = 4; b >= 0; b--)
                {
                    bits.append(((val >> b) & 1) == 1 ? '1' : '0');
                }
            }
            
            int total = R * C;
            while (bits.length() < total)
            {
                bits.append('0');
            }
            
            char[][] mat = new char[R][C];
            boolean[][] used = new boolean[R][C];
            
            int x = 0, y = 0, dir = 0, idx = 0;
            for (int i = 0; i < total; i++)
            {
                mat[x][y] = bits.charAt(idx++);
                used[x][y] = true;
                
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || used[nx][ny])
                {
                    dir = (dir + 1) & 3;
                    nx = x + dx[dir];
                    ny = y + dy[dir];
                }
                
                x = nx;
                y = ny;
            }
            
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    output.append(mat[i][j]);
                }
            }
            
            output.append("\n");
        }
        
        System.out.println(output);
    }
}