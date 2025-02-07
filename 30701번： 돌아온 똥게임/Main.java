import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        ArrayList<Integer> monsters = new ArrayList<>();
        ArrayList<Integer> equips = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            int power = Integer.parseInt(st.nextToken());

            if (type == 1)
                monsters.add(power);
            else
                equips.add(power);
        }

        Collections.sort(monsters);
        Collections.sort(equips);

        BigInteger cur = BigInteger.valueOf(D);

        long count = 0;
        int mIndex = 0, eIndex = 0;

        while (mIndex < monsters.size() || eIndex < equips.size()) {
            if (mIndex < monsters.size() && cur.compareTo(BigInteger.valueOf(monsters.get(monsters.size() - 1))) > 0) {
                count += (monsters.size() - mIndex) + (equips.size() - eIndex);
                break;
            }

            if (mIndex < monsters.size() && cur.compareTo(BigInteger.valueOf(monsters.get(mIndex))) > 0) {
                cur = cur.add(BigInteger.valueOf(monsters.get(mIndex)));
                count++;
                mIndex++;
                continue;
            }

            if (eIndex < equips.size()) {
                cur = cur.multiply(BigInteger.valueOf(equips.get(eIndex)));
                count++;
                eIndex++;
                continue;
            }

            break;
        }

        if (mIndex >= monsters.size() && eIndex < equips.size()) {
            count += (equips.size() - eIndex);
        }

        System.out.println(count);
    }
}