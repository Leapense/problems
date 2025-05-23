import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, ArrayList<String>> groupToMembers = new HashMap<>();
        HashMap<String, String> memberToGroup = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String groupName = br.readLine();
            int memberCount = Integer.parseInt(br.readLine());
            ArrayList<String> members = new ArrayList<>();

            for (int j = 0; j < memberCount; j++) {
                String memberName = br.readLine();
                members.add(memberName);
                memberToGroup.put(memberName, groupName);
            }
            groupToMembers.put(groupName, members);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            String query = br.readLine();
            int type = Integer.parseInt(br.readLine());

            if (type == 0) {
                ArrayList<String> members = groupToMembers.get(query);
                Collections.sort(members);
                for (String member : members) {
                    sb.append(member).append("\n");
                }
            } else if (type == 1) {
                String group = memberToGroup.get(query);
                sb.append(group).append("\n");
            }
        }

        System.out.print(sb);
    }
}