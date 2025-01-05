import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] room = new int[N + 1];
        int[] studentToRoom = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            room[i] = i;
            studentToRoom[i] = i;
        }

        int totalGoodWeeks = 0;
        int maxConsecutiveGoodWeeks = 0;
        int currentConsecutiveGoodWeeks = 0;

        for (int week = 1; week <= M; week++) {
            if (week == 1) {
                if (isGoodWeek(room, studentToRoom, 1, A, B)) {
                    totalGoodWeeks++;
                    currentConsecutiveGoodWeeks++;
                    maxConsecutiveGoodWeeks = Math.max(maxConsecutiveGoodWeeks, currentConsecutiveGoodWeeks);
                } else {
                    currentConsecutiveGoodWeeks = 0;
                }
            }
            else {
                if (week <= M) {
                    int[] goodPoints = new int[N + 1];
                    st = new StringTokenizer(br.readLine());
                    for (int i = 1; i <= N; i++) {
                        goodPoints[i] = Integer.parseInt(st.nextToken());
                    }

                    int[] badPoints = new int[N + 1];
                    st = new StringTokenizer(br.readLine());
                    for (int i = 1; i <= N; i++) {
                        badPoints[i] = Integer.parseInt(st.nextToken());
                    }

                    int[] scores = new int[N + 1];
                    for (int i = 1; i <= N; i++) {
                        scores[i] = goodPoints[i] - badPoints[i];
                    }

                    for (int j = 1; j < N; j++) {
                        int studentGoodRoom = room[j];
                        int studentBadRoom = room[j + 1];
                        int scoreGood = scores[studentGoodRoom];
                        int scoreBad = scores[studentBadRoom];

                        boolean shouldSwap = false;

                        if (scoreGood >= 0 && scoreBad >= 0) {
                            if (scoreBad >= scoreGood + 2) {
                                shouldSwap = true;
                            }
                        }
                        else if (scoreGood >= 0 && scoreBad < 0) {
                            shouldSwap = false;
                        }
                        else if (scoreGood < 0 && scoreBad >= 0) {
                            shouldSwap = true;
                        }
                        else if (scoreGood < 0 && scoreBad < 0) {
                            if (scoreBad >= scoreGood + 4) {
                                shouldSwap = true;
                            }
                        }

                        if (shouldSwap) {
                            room[j] = studentBadRoom;
                            room[j + 1] = studentGoodRoom;

                            studentToRoom[studentGoodRoom] = j + 1;
                            studentToRoom[studentBadRoom] = j;

                            scores[studentGoodRoom] += 2;
                            scores[studentBadRoom] -= 2;
                        }
                    }

                    if (isGoodWeek(room, studentToRoom, 1, A, B)) {
                        totalGoodWeeks++;
                        currentConsecutiveGoodWeeks++;
                        maxConsecutiveGoodWeeks = Math.max(maxConsecutiveGoodWeeks, currentConsecutiveGoodWeeks);
                    } else {
                        currentConsecutiveGoodWeeks = 0;
                    }
                }
            }
        }

        System.out.println(totalGoodWeeks + " " + maxConsecutiveGoodWeeks);
    }

    private static boolean isGoodWeek(int[] room, int[] studentToRoom, int hong, int jo, int B) {
        int hongRoom = studentToRoom[hong];
        int joRoom = studentToRoom[jo];
        return Math.abs(hongRoom - joRoom) <= B;
    }
}