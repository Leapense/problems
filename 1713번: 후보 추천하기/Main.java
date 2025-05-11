import java.util.*;
import java.io.*;

public class Main {
    static class Candidate {
        int number;
        int count;
        int time;

        Candidate(int number, int count, int time) {
            this.number = number;
            this.count = count;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int total = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        List<Candidate> frames = new ArrayList<>(N);
        Map<Integer, Candidate> inFrame = new HashMap<>();

        int time = 0;
        for (int i = 0; i < total; i++) {
            int student = Integer.parseInt(st.nextToken());
            time++;

            if (inFrame.containsKey(student)) {
                inFrame.get(student).count++;
            } else {
                if (frames.size() < N) {
                    Candidate c = new Candidate(student, 1, time);
                    frames.add(c);
                    inFrame.put(student, c);
                } else {
                    Candidate toRemove = frames.get(0);
                    for (Candidate c : frames) {
                        if (c.count < toRemove.count || (c.count == toRemove.count && c.time < toRemove.time)) {
                            toRemove = c;
                        }
                    }

                    inFrame.remove(toRemove.number);
                    frames.remove(toRemove);

                    Candidate c = new Candidate(student, 1, time);
                    frames.add(c);
                    inFrame.put(student, c);
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (Candidate c : frames) {
            result.add(c.number);
        }
        Collections.sort(result);

        StringBuilder sb = new StringBuilder();
        for (int num : result) {
            sb.append(num).append(' ');
        }

        System.out.println(sb.toString().trim());
    }
}