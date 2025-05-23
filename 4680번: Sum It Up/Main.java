import java.util.*;

public class Main {
    static int target;
    static int n;
    static int[] nums;
    static List<List<Integer>> resultList;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            target = sc.nextInt();
            n = sc.nextInt();
            if (n == 0)
                break;
            nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = sc.nextInt();
            }
            resultList = new ArrayList<>();
            Set<String> used = new HashSet<>();
            backtrack(0, 0, new ArrayList<>(), used);
            Collections.sort(resultList, new Comparator<List<Integer>>() {
                public int compare(List<Integer> a, List<Integer> b) {
                    int minSize = Math.min(a.size(), b.size());
                    for (int i = 0; i < minSize; i++) {
                        int cmp = b.get(i).compareTo(a.get(i));
                        if (cmp != 0)
                            return cmp;
                    }
                    return b.size() - a.size();
                }
            });
            System.out.println("Sums of " + target + ":");
            if (resultList.isEmpty()) {
                System.out.println("NONE");
            } else {
                for (List<Integer> list : resultList) {
                    StringBuilder sb = new StringBuilder();
                    for (int i = 0; i < list.size(); i++) {
                        sb.append(list.get(i));
                        if (i != list.size() - 1)
                            sb.append("+");
                    }
                    System.out.println(sb.toString());
                }
            }
        }
    }

    static void backtrack(int index, int currentSum, ArrayList<Integer> current, Set<String> used) {
        if (currentSum == target) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < current.size(); i++) {
                sb.append(current.get(i));
                if (i != current.size() - 1)
                    sb.append("+");
            }
            String combination = sb.toString();
            if (!used.contains(combination)) {
                used.add(combination);
                resultList.add(new ArrayList<>(current));
            }
            return;
        }
        if (currentSum > target)
            return;
        for (int i = index; i < n; i++) {
            current.add(nums[i]);
            backtrack(i + 1, currentSum + nums[i], current, used);
            current.remove(current.size() - 1);
        }
    }
}
