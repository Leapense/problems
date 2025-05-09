import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int R1 = Integer.parseInt(st.nextToken());
        int C1 = Integer.parseInt(st.nextToken());
        int R2 = Integer.parseInt(st.nextToken());
        int C2 = Integer.parseInt(st.nextToken());

        int diamondTileSideLength = 2 * N - 1;

        int centerInTile = N - 1;

        for (int r = R1; r <= R2; r++) {
            StringBuilder currentRowBuilder = new StringBuilder(C2 - C1 + 1);
            for (int c = C1; c <= C2; c++) {
                int rInTile = r % diamondTileSideLength;
                int cInTile = c % diamondTileSideLength;
                int manhattanDistance = Math.abs(rInTile - centerInTile) + Math.abs(cInTile - centerInTile);

                if (manhattanDistance >= N) {
                    currentRowBuilder.append('.');
                } else {
                    char ch = (char) ('a' + (manhattanDistance % 26));
                    currentRowBuilder.append(ch);
                }
            }

            System.out.println(currentRowBuilder.toString());
        }
    }
}