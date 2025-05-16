import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final Map<String, String> CODON = new HashMap<>();
    private static final Set<String> STOP = Set.of("UAA", "UAG", "UGA");
    static {
        String[][] data = {
                { "UUU", "Phe" }, { "UUC", "Phe" }, { "UUA", "Leu" }, { "UUG", "Leu" },
                { "UCU", "Ser" }, { "UCC", "Ser" }, { "UCA", "Ser" }, { "UCG", "Ser" },
                { "UAU", "Tyr" }, { "UAC", "Tyr" },
                { "UGU", "Cys" }, { "UGC", "Cys" }, { "UGG", "Trp" },
                { "CUU", "Leu" }, { "CUC", "Leu" }, { "CUA", "Leu" }, { "CUG", "Leu" },
                { "CCU", "Pro" }, { "CCC", "Pro" }, { "CCA", "Pro" }, { "CCG", "Pro" },
                { "CAU", "His" }, { "CAC", "His" }, { "CAA", "Gln" }, { "CAG", "Gln" },
                { "CGU", "Arg" }, { "CGC", "Arg" }, { "CGA", "Arg" }, { "CGG", "Arg" },
                { "AUU", "Ile" }, { "AUC", "Ile" }, { "AUA", "Ile" }, { "AUG", "Met" },
                { "ACU", "Thr" }, { "ACC", "Thr" }, { "ACA", "Thr" }, { "ACG", "Thr" },
                { "AAU", "Asn" }, { "AAC", "Asn" }, { "AAA", "Lys" }, { "AAG", "Lys" },
                { "AGU", "Ser" }, { "AGC", "Ser" }, { "AGA", "Arg" }, { "AGG", "Arg" },
                { "GUU", "Val" }, { "GUC", "Val" }, { "GUA", "Val" }, { "GUG", "Val" },
                { "GCU", "Ala" }, { "GCC", "Ala" }, { "GCA", "Ala" }, { "GCG", "Ala" },
                { "GAU", "Asp" }, { "GAC", "Asp" }, { "GAA", "Glu" }, { "GAG", "Glu" },
                { "GGU", "Gly" }, { "GGC", "Gly" }, { "GGA", "Gly" }, { "GGG", "Gly" }
        };
        for (String[] d : data)
            CODON.put(d[0], d[1]);
    }

    private static class Candidate {
        final int frame, start, seqIdx;
        final String protein;

        Candidate(int frame, int start, int seqIdx, String protein) {
            this.frame = frame;
            this.start = start;
            this.seqIdx = seqIdx;
            this.protein = protein;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.equals("*"))
                break;
            String result = translate(line);
            out.append(result != null ? result : "*** No translatable DNA found ***").append('\n');
        }
        System.out.print(out.toString());
    }

    private static String translate(String dna) {
        List<String> rnas = generateRNAs(dna);
        List<Candidate> list = new ArrayList<>();
        for (int s = 0; s < rnas.size(); s++) {
            String rna = rnas.get(s);
            int n = rna.length();
            for (int f = 0; f < 3; f++) {
                for (int i = f; i + 3 <= n; i += 3) {
                    if (!rna.startsWith("AUG", i))
                        continue;
                    List<String> aa = new ArrayList<>();
                    for (int j = i + 3; j + 3 <= n; j += 3) {
                        String codon = rna.substring(j, j + 3);
                        if (STOP.contains(codon)) {
                            if (!aa.isEmpty())
                                list.add(new Candidate(f, i, s, String.join("-", aa)));
                            break;
                        }
                        String acid = CODON.get(codon);
                        if (acid == null)
                            break;
                        aa.add(acid);
                    }
                }
            }
        }
        if (list.isEmpty())
            return null;
        list.sort(Comparator.comparingInt((Candidate c) -> c.frame)
                .thenComparingInt(c -> c.start)
                .thenComparingInt(c -> c.seqIdx));
        return list.get(0).protein;
    }

    private static List<String> generateRNAs(String dna) {
        StringBuilder comp = new StringBuilder(dna.length());
        for (char ch : dna.toCharArray())
            comp.append(ch == 'A' ? 'T' : ch == 'T' ? 'A' : ch == 'C' ? 'G' : 'C');
        String compStr = comp.toString();
        String rev = new StringBuilder(dna).reverse().toString();
        String revComp = comp.reverse().toString();
        return List.of(
                dna.replace('T', 'U'),
                compStr.replace('T', 'U'),
                rev.replace('T', 'U'),
                revComp.replace('T', 'U'));
    }
}
