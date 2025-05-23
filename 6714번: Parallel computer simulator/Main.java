import java.io.*;
import java.util.*;

public class Main {
    static class Program {
        int id, pc;
        ArrayList<String> lines;

        Program(int id, ArrayList<String> lines) {
            this.id = id;
            this.pc = 0;
            this.lines = lines;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int timeAssign = Integer.parseInt(st.nextToken());
        int timePrint = Integer.parseInt(st.nextToken());
        int timeLock = Integer.parseInt(st.nextToken());
        int timeUnlock = Integer.parseInt(st.nextToken());
        int timeEnd = Integer.parseInt(st.nextToken());
        int quantum = Integer.parseInt(st.nextToken());
        Program[] programs = new Program[n];
        for (int i = 0; i < n; i++) {
            ArrayList<String> lines = new ArrayList<>();
            String line;
            while ((line = br.readLine()) != null) {
                if (line.equals(""))
                    continue;
                line = line.trim();
                lines.add(line);
                if (line.equals("end"))
                    break;
            }
            programs[i] = new Program(i + 1, lines);
        }
        int[] variables = new int[26];
        Deque<Program> ready = new ArrayDeque<>();
        for (int i = 0; i < n; i++)
            ready.offer(programs[i]);
        Queue<Program> blocked = new LinkedList<>();
        boolean lockHeld = false;
        StringBuilder output = new StringBuilder();
        while (!ready.isEmpty()) {
            Program cur = ready.poll();
            int timeLeft = quantum;
            boolean terminated = false;
            boolean blockedFlag = false;
            while (timeLeft > 0) {
                String instr = cur.lines.get(cur.pc);
                if (instr.startsWith("print")) {
                    char var = instr.charAt(instr.length() - 1);
                    output.append(cur.id).append(": ").append(variables[var - 'a']).append("\n");
                    timeLeft -= timePrint;
                } else if (instr.contains("=")) {
                    instr = instr.replaceAll(" ", "");
                    String[] parts = instr.split("=");
                    char var = parts[0].charAt(0);
                    int val = Integer.parseInt(parts[1]);
                    variables[var - 'a'] = val;
                    timeLeft -= timeAssign;
                } else if (instr.equals("lock")) {
                    if (!lockHeld) {
                        lockHeld = true;
                        timeLeft -= timeLock;
                    } else {
                        blocked.offer(cur);
                        blockedFlag = true;
                        break;
                    }
                } else if (instr.equals("unlock")) {
                    lockHeld = false;
                    if (!blocked.isEmpty())
                        ready.addFirst(blocked.poll());
                    timeLeft -= timeUnlock;
                } else if (instr.equals("end")) {
                    timeLeft -= timeEnd;
                    cur.pc++;
                    terminated = true;
                    break;
                }
                cur.pc++;
                if (cur.pc >= cur.lines.size())
                    break;
            }
            if (!terminated && !blockedFlag)
                ready.offer(cur);
        }
        System.out.print(output);
    }
}
