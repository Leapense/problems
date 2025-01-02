import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine().trim());
        int[] counts = new int[m];
        String line;
        while ((line = br.readLine()) != null) {
            if(line.trim().isEmpty()) continue;
            String[] tokens = line.trim().split("\\s+");
            for(String token : tokens){
                double a = Double.parseDouble(token);
                int index = (int)(a * m);
                if(index >=m) index=m-1;
                counts[index]++;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<m;i++){
            sb.append(counts[i]);
            if(i !=m-1) sb.append(" ");
        }
        System.out.println(sb);
    }
}