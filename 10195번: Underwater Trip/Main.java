import java.util.*;

public class Main {
    private static void tunnelTrip(int tunnelDepth, int tunnelLength, int stalagmites[][], char[][] actions) {
        int numStalagmites = stalagmites.length;
        int numActions = actions.length;
        for (int a = 0; a < numActions; a++) {
            int x = 0;
            int depth = 0;
            String outcome = "";
            boolean crashed = false;
            for (int i = 0; i < tunnelLength - 1; i++) {
                char act = actions[a][i];
                if (act == '^') {
                    depth--;
                } else if (act == 'v') {
                    depth++;
                }
                x++;
                if (depth < 0) {
                    outcome = "Crashed into tunnel ceiling";
                    crashed = true;
                    break;
                }
                if (depth >= tunnelDepth) {
                    outcome = "Crashed into tunnel floor";
                    crashed = true;
                    break;
                }
                for (int s = 0; s < numStalagmites; s++) {
                    if (stalagmites[s][1] == x) {
                        if (depth >= tunnelDepth - stalagmites[s][0]) {
                            outcome = "Crashed into stalagmite";
                            crashed = true;
                            break;
                        }
                    }
                }
                if (crashed)
                    break;
            }
            if (!crashed) {
                outcome = "Reached end of tunnel";
            }
            System.out.format("Sequence %s %s\n", new String(actions[a]), outcome);
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int numCases = scanner.nextInt();
        for (int t = 1; t <= numCases; t++) {
            scanner.next();
            scanner.next();
            int tunnelDepth = scanner.nextInt();
            scanner.next();
            int tunnelLength = scanner.nextInt();
            int nStalag = scanner.nextInt();
            scanner.next();
            int stalagmites[][] = new int[nStalag][2];
            for (int s = 0; s < nStalag; s++) {
                stalagmites[s][0] = scanner.nextInt();
                scanner.next();
                scanner.next();
                stalagmites[s][1] = scanner.nextInt();
                scanner.next();
                scanner.next();
            }
            int nActions = scanner.nextInt();
            scanner.next();
            char actions[][] = new char[nActions][tunnelLength - 1];
            for (int a = 0; a < nActions; a++) {
                String actionLine = scanner.next();
                for (int j = 0; j < tunnelLength - 1; j++)
                    actions[a][j] = actionLine.charAt(j);
            }
            System.out.println("Case: " + t);
            tunnelTrip(tunnelDepth, tunnelLength, stalagmites, actions);
        }
        scanner.close();
    }
}
