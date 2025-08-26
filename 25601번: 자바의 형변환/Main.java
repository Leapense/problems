import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public final class Main {
    private Main() {}
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            Map<String, String> parentMap = new HashMap<>();
            for (int i = 0; i < n - 1; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String childClass = st.nextToken();
                String parentClass = st.nextToken();
                parentMap.put(childClass, parentClass);
            }
            StringTokenizer st = new StringTokenizer(br.readLine());
            String classToCheck1 = st.nextToken();
            String classToCheck2 = st.nextToken();
            if (isAncestor(parentMap, classToCheck1, classToCheck2) || isAncestor(parentMap, classToCheck2, classToCheck1)) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean isAncestor(Map<String, String> parentMap, String potentialAncestor, String descendant) {
        String current = descendant;
        while (parentMap.containsKey(current)) {
            current = parentMap.get(current);
            if (current.equals(potentialAncestor)) {
                return true;
            }
        }
        return false;
    }
}