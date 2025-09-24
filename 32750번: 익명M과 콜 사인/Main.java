import java.io.*;
import java.util.*;

public class Main {
    enum SetType { NONE, A, B, C, D }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) line = "";
        line = line.trim();

        if (line.isEmpty()) {
            System.out.println("0 0");
            return;
        }

        String[] tok = line.split(" ");
        String[] A_BASE = {"se","no","hai-","hai-","hai","hai","hai","hai"};
        String[] B_SEQ = {"mik-jjang", "kawaii!"};
        String[] C_SEQ = {"Are","you","ready","antena","senku","high!"};

        Set<String> FIRST = new HashSet<>(Arrays.asList("se","mik-jjang","Are","u-","hai"));

        int lead = 0;
        int end = 0;

        SetType cur = SetType.NONE;
        int idx = 0;
        int aPhase = 0;

        int i = 0;
        while (i < tok.length) {
            String t = tok[i];
            if (cur == SetType.NONE) {
                switch(t) {
                    case "se":
                        cur = SetType.A; idx = 1; aPhase = 0;
                        lead++;
                        break;
                    case "mik-jjang":
                        cur = SetType.B; idx = 1;
                        lead++;
                        break;
                    case "Are":
                        cur = SetType.C; idx = 1;
                        lead++;
                        break;
                    case "u-":
                        cur = SetType.D; idx = 1;
                        break;
                    case "hai":
                        end++;
                        break;
                    default:
                        break;
                }
                i++;
                continue;
            }

            if (cur == SetType.A) {
                if (aPhase == 0) {
                    if (idx < A_BASE.length && t.equals(A_BASE[idx])) {
                        idx++;
                        if (idx == A_BASE.length) {
                            aPhase = 1;
                        }
                    }
                    i++;
                } else if (aPhase == 1) {
                    if ("u-".equals(t)) {
                        aPhase = 2;
                        i++;
                    } else if (FIRST.contains(t) && !"u-".equals(t)) {
                        end++;
                        cur = SetType.NONE; idx = 0; aPhase = 0;
                    } else {
                        i++;
                    }
                } else {
                    if ("hai".equals(t)) {
                        aPhase = 1;
                    }
                    i++;
                }
            } else if (cur == SetType.B) {
                if (t.equals(B_SEQ[idx])) {
                    idx++;
                    if (idx == B_SEQ.length) {
                        end++;
                        cur = SetType.NONE; idx = 0;
                    }
                }
                i++;
            } else if (cur == SetType.C) {
                if (t.equals(C_SEQ[idx])) {
                    idx++;
                    if (idx == C_SEQ.length) {
                        end++;
                        cur = SetType.NONE; idx = 0;
                    }
                }
                i++;
            } else if (cur == SetType.D) {
                if ("hai".equals(t)) {
                    end++;
                    cur = SetType.NONE; idx = 0;
                }
                i++;
            }
        }

        if (cur == SetType.A && aPhase == 1) {
            end++;
        }

        System.out.println(lead + " " + end);
    }
}