import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static class Result {
        long p, q;

        Result(long p, long q) {
            this.p = p;
            this.q = q;
        }
    }

    static Result extendedGCD(long a, long b) {
        if (b == 0)
            return new Result(1, 0);
        Result r = extendedGCD(b, a % b);
        return new Result(r.q, r.p - (a / b) * r.q);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String line;
        while ((line = br.readLine()) != null) {
            if (line.trim().isEmpty())
                continue;
            StringTokenizer st = new StringTokenizer(line);
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long d = Long.parseLong(st.nextToken());
            if (a == 0 && b == 0 && d == 0)
                break;
            long g = gcd(a, b);
            long aPrime = a / g, bPrime = b / g;
            Result r = extendedGCD(a, b);
            long p0 = r.p * (d / g);
            long q0 = r.q * (d / g);
            // 일반해: p = p0 + bPrime * t, q = q0 - aPrime * t

            // 두 절환점(브레이크포인트)
            double t1 = -p0 / (double) bPrime;
            double t2 = q0 / (double) aPrime;
            // 후보 집합 구성 (절단점과 그 인접 정수, 그리고 0)
            HashSet<Long> candidates = new HashSet<>();
            addCandidate(candidates, Math.floor(t1));
            addCandidate(candidates, Math.ceil(t1));
            addCandidate(candidates, Math.floor(t2));
            addCandidate(candidates, Math.ceil(t2));
            candidates.add(0L);
            // 각 후보 주변 한 칸씩 추가
            HashSet<Long> extra = new HashSet<>();
            for (Long t : candidates) {
                extra.add(t - 1);
                extra.add(t + 1);
            }
            candidates.addAll(extra);

            long bestT = 0;
            long bestF = Long.MAX_VALUE, bestF2 = Long.MAX_VALUE;
            for (long t : candidates) {
                long p = p0 + bPrime * t;
                long q = q0 - aPrime * t;
                long F = Math.abs(p) + Math.abs(q);
                long F2 = a * Math.abs(p) + b * Math.abs(q);
                if (F < bestF || (F == bestF && F2 < bestF2)) {
                    bestF = F;
                    bestF2 = F2;
                    bestT = t;
                }
            }
            long p = p0 + bPrime * bestT;
            long q = q0 - aPrime * bestT;
            out.println(Math.abs(p) + " " + Math.abs(q));
        }
        out.flush();
    }

    static void addCandidate(HashSet<Long> set, double val) {
        set.add((long) val);
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
