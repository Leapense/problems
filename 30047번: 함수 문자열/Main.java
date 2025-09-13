import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedInputStream bis = new BufferedInputStream(System.in);
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        byte[] buf = new byte[1 << 15];
        int len;
        while ((len = bis.read(buf)) != -1) baos.write(buf, 0, len);
        String s = new String(baos.toByteArray()).trim();
        if (s.isEmpty()) { System.out.println(-1); return; }

        char[] a = s.toCharArray();
        int n = a.length;
        int[] st = new int[n];
        int top = 0;
        boolean ok = true;
        for (int i = n - 1; i >= 0 && ok; i--) {
            char c = a[i];
            if (c == 'x') {
                st[top++] = 0;
            } else if (c == 'g') {
                if (top < 1) { ok = false; break; }
                st[top - 1] = st[top - 1] + 1;
            } else if (c == 'f') {
                if (top < 2) { ok = false; break; }
                int v = Math.min(st[top - 1], st[top - 2]);
                top -= 2;
                st[top++] = v;
            } else {
                ok = false;
            }
        }
        if (!ok || top != 1) System.out.println(-1);
        else System.out.println(st[0]);
    }
}