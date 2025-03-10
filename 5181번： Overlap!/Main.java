import java.io.*;
import java.util.*;

public class Main {
    static class Exam implements Comparable<Exam> {
        int start;
        int end;

        Exam(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int compareTo(Exam other) {
            return this.start - other.start;
        }
    }

    static class CourseInfo {
        String day;
        int start;
        int end;

        CourseInfo(String day, int start, int end) {
            this.day = day;
            this.start = start;
            this.end = end;
        }
    }

    public static int timeToMinutes(String time) {
        String[] parts = time.split(":");
        int hour = Integer.parseInt(parts[0]);
        int minute = Integer.parseInt(parts[1]);
        return hour * 60 + minute;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine().trim());
        for (int dataset = 1; dataset <= K; dataset++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            Map<String, CourseInfo> courseMap = new HashMap<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                String course = st.nextToken();
                String day = st.nextToken();
                String timeRange = st.nextToken();
                String[] times = timeRange.split("-");
                int start = timeToMinutes(times[0]);
                int end = timeToMinutes(times[1]);
                courseMap.put(course, new CourseInfo(day, start, end));
            }

            int overlapCount = 0;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                Map<String, List<Exam>> dayExams = new HashMap<>();
                while (st.hasMoreTokens()) {
                    String course = st.nextToken();
                    CourseInfo info = courseMap.get(course);
                    dayExams.putIfAbsent(info.day, new ArrayList<>());
                    dayExams.get(info.day).add(new Exam(info.start, info.end));
                }

                boolean hasOverlap = false;
                for (List<Exam> exams : dayExams.values()) {
                    Collections.sort(exams);
                    for (int j = 1; j < exams.size(); j++) {
                        if (exams.get(j - 1).end > exams.get(j).start) {
                            hasOverlap = true;
                            break;
                        }
                    }

                    if (hasOverlap)
                        break;
                }

                if (hasOverlap)
                    overlapCount++;
            }

            System.out.println("Data Set " + dataset + ":");
            System.out.println(overlapCount);
        }
    }
}