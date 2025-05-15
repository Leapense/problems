import java.util.*;
import java.io.*;

public class Main
{
    static class Program
    {
        int size;
        List<Integer> dlls;

        Program(int size, List<Integer> dlls) {
            this.size = size;
            this.dlls = dlls;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0")) {
            String[] first = line.trim().split("\\s+");
            int N = Integer.parseInt(first[0]);
            int P = Integer.parseInt(first[1]);
            int S = Integer.parseInt(first[2]);

            int[] dllSizes = new int[N];
            String[] dlls = br.readLine().trim().split("\\s+");
            for (int i = 0; i < N; i++) {
                dllSizes[i] = Integer.parseInt(dlls[i]);
            }

            Program[] programs = new Program[P];

            for (int i = 0; i < P; i++)
            {
                String progLine = br.readLine().trim();
                int spaceIdx = progLine.indexOf(' ');
                int progSize = Integer.parseInt(progLine.substring(0, spaceIdx));
                List<Integer> requiredDlls = new ArrayList<>();
                for (char c : progLine.substring(spaceIdx + 1).toCharArray()) {
                    requiredDlls.add(c - 'A');
                }
                programs[i] = new Program(progSize, requiredDlls);
            }

            String[] transitions = br.readLine().trim().split("\\s+");
            int[] progCount = new int[P];
            int[] dllUsed = new int[N];

            int currMem = 0;
            int maxMem = 0;

            for (String tStr : transitions)
            {
                int t = Integer.parseInt(tStr);
                int idx = Math.abs(t) - 1;
                Program prog = programs[idx];
                if (t > 0)
                {
                    progCount[idx]++;
                    currMem += prog.size;

                    for (int d : prog.dlls) {
                        if (dllUsed[d] == 0) {
                            currMem += dllSizes[d];
                        }

                        dllUsed[d]++;
                    }
                } else {
                    progCount[idx]--;
                    currMem -= prog.size;

                    for (int d : prog.dlls) {
                        dllUsed[d]--;
                        if (dllUsed[d] == 0) {
                            currMem -= dllSizes[d];
                        }
                    }
                }

                if (currMem > maxMem) maxMem = currMem;
            }

            System.out.println(maxMem);
        }
    }
}