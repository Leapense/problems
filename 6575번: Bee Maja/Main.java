import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Main {

    /** Direction vectors when walking *backwards* around the hexagon. */
    private static final int[] SIDE_DX = { 0, -1, -1, 0, 1, 1 };
    private static final int[] SIDE_DY = { -1, 0, 1, 1, 0, -1 };

    private Main() {
        // utility class – no instances
    }

    /**
     * Translate Willi’s number into Maja’s axial coordinates.
     *
     * @param number cell number (1 ≤ number < 100 000)
     * @return array {x, y}
     */
    private static int[] toAxial(final int number) {
        if (number == 1) {
            return new int[] { 0, 0 };
        }

        // locate the ring that contains `number`
        int layer = 0;
        int max = 1; // largest number on current ring
        while (max < number) {
            layer++;
            max += 6 * layer; // each new ring adds 6·layer cells
        }

        final int diff = max - number; // steps to walk back from corner
        final int side = diff / layer; // 0‥5
        final int offset = diff % layer; // 0‥layer-1

        // start in south-east corner (layer,0) == max(layer)
        int x = layer;
        int y = 0;

        // walk whole sides already passed
        for (int i = 0; i < side; i++) {
            x += SIDE_DX[i] * layer;
            y += SIDE_DY[i] * layer;
        }

        // walk the remaining part of the current side
        x += SIDE_DX[side] * offset;
        y += SIDE_DY[side] * offset;

        return new int[] { x, y };
    }

    public static void main(final String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            final StringBuilder out = new StringBuilder();
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    continue; // ignore blank lines
                }
                final int n = Integer.parseInt(line);
                final int[] c = toAxial(n);
                out.append(c[0]).append(' ').append(c[1]).append('\n');
            }
            System.out.print(out.toString());
        }
    }
}
