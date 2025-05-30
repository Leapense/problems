import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.Optional;
import java.util.StringTokenizer;

public final class Main {
    // 유틸리티 클래스는 인스턴스화 가능한 public 생성자를 가져서는 안됨.
    private Main() {
        throw new IllegalStateException("Utility class");
    }

    static final class Ant {
        private final int id;
        private final int position;
        private final int velocity;
        private final boolean inTunnel;

        public Ant(int id, int position, int velocity, boolean inTunnel) {
            this.id = id;
            this.position = position;
            this.velocity = velocity;
            this.inTunnel = inTunnel;
        }

        public int id() {
            return id;
        }

        public int position() {
            return position;
        }

        public int velocity() {
            return velocity;
        }

        public boolean inTunnel() {
            return inTunnel;
        }

        public Ant move(int deltaTime) {
            return new Ant(this.id, this.position + this.velocity * deltaTime, this.velocity, this.inTunnel);
        }

        public Ant turnAround() {
            return new Ant(this.id, this.position, -this.velocity, this.inTunnel);
        }

        public Ant leaveTunnel() {
            return new Ant(this.id, this.position, this.velocity, false);
        }

        @Override
        public boolean equals(Object o)
        {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Ant ant = (Ant) o;
            return id == ant.id && position == ant.position && velocity == ant.velocity && inTunnel == ant.inTunnel;
        }

        @Override
        public int hashCode() {
            return Objects.hash(id, position, velocity, inTunnel);
        }

        @Override
        public String toString() {
            return "Ant{" +
                   "id=" + id +
                   ", position=" + position +
                   ", velocity=" + velocity +
                   ", inTunnel=" + inTunnel +
                   '}';
        }
    }

    static final class ExitInfo {
        private final int antId;
        private final int time;
        private final boolean exitedFromLeft;

        public ExitInfo(int antId, int time, boolean exitedFromLeft) {
            this.antId = antId;
            this.time = time;
            this.exitedFromLeft = exitedFromLeft;
        }

        public int antId() {
            return antId;
        }

        public int time() {
            return time;
        }

        public boolean exitedFromLeft() {
            return exitedFromLeft;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            ExitInfo exitInfo = (ExitInfo) o;
            return antId == exitInfo.antId && time == exitInfo.time && exitedFromLeft == exitInfo.exitedFromLeft;
        }

        @Override
        public int hashCode() {
            return Objects.hash(antId, time, exitedFromLeft);
        }

        @Override
        public String toString() {
            return "ExitInfo{" +
                   "antId=" + antId +
                   ", time=" + time +
                   ", exitedFromLeft=" + exitedFromLeft +
                   '}';
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder outputBuilder = new StringBuilder();

        while (true)
        {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(st.nextToken());
            int lOriginal = Integer.parseInt(st.nextToken());

            if (n == 0 && lOriginal == 0) break;

            List<Ant> ants = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(reader.readLine());
                char dirChar = st.nextToken().charAt(0);
                int posOriginal = Integer.parseInt(st.nextToken());

                int velocity = (dirChar == 'L') ? -1 : 1;
                ants.add(new Ant(i, posOriginal * 2, velocity, true));
            }

            solveDataset(n, lOriginal * 2, ants, outputBuilder);
        }
        
        System.out.print(outputBuilder.toString());
    }

    private static void solveDataset(int totalAnts, int tunnelLengthScaled, List<Ant> initialAnts, StringBuilder outputBuilder) {
        List<Ant> currentAnts = new ArrayList<>(initialAnts);
        int currentTimeScaled = 0;
        int antsInTunnelCount = totalAnts;
        List<ExitInfo> allExitInfos = new ArrayList<>();

        boolean[] turnedThisTimeStep = new boolean[totalAnts + 1];

        while (antsInTunnelCount > 0) {
            int minDeltaTime = Integer.MAX_VALUE;

            for (Ant ant : currentAnts) {
                if (!ant.inTunnel()) {
                    continue;
                }
                if (ant.velocity() < 0) {
                    minDeltaTime = Math.min(minDeltaTime, ant.position() > 0 ? ant.position() : 0);
                } else {
                    minDeltaTime = Math.min(minDeltaTime, ant.position() < tunnelLengthScaled ? tunnelLengthScaled - ant.position() : 0);
                }
            }

            for (int i = 0; i < currentAnts.size(); i++) {
                Ant ant1 = currentAnts.get(i);
                if (!ant1.inTunnel()) {
                    continue;
                }

                for (int j = i + 1; j < currentAnts.size(); j++) {
                    Ant ant2 = currentAnts.get(j);
                    if (!ant2.inTunnel()) {
                        continue;
                    }

                    if (ant1.velocity() != ant2.velocity()) {
                        if ((ant1.velocity() > 0 && ant1.position() < ant2.position()) || (ant1.velocity() < 0 && ant1.position() > ant2.position())) {
                            int distance = Math.abs(ant1.position() - ant2.position());
                            minDeltaTime = Math.min(minDeltaTime, distance > 0 ? distance / 2 : 0);
                        }
                    }
                }
            }

            if (minDeltaTime == Integer.MAX_VALUE) {
                break;
            }
            if (minDeltaTime == 0 && antsInTunnelCount == 0) {
                break;
            }

            currentTimeScaled += minDeltaTime;

            List<Ant> nextAntStates = new ArrayList<>();
            for (Ant ant : currentAnts) {
                if (ant.inTunnel()) {
                    nextAntStates.add(ant.move(minDeltaTime));
                } else {
                    nextAntStates.add(ant);
                }
            }

            currentAnts = nextAntStates;

            List<Ant> antsAfterExitProcessing = new ArrayList<>();
            for (Ant ant : currentAnts) {
                if (!ant.inTunnel()) {
                    antsAfterExitProcessing.add(ant);
                    continue;
                }

                boolean exitedThisStep = false;
                if (ant.velocity() < 0 && ant.position() <= 0) {
                    allExitInfos.add(new ExitInfo(ant.id(), currentTimeScaled, true));
                    antsAfterExitProcessing.add(ant.leaveTunnel());
                    antsInTunnelCount--;
                    exitedThisStep = true;
                } else if (ant.velocity() > 0 && ant.position() >= tunnelLengthScaled) {
                    allExitInfos.add(new ExitInfo(ant.id(), currentTimeScaled, false));
                    antsAfterExitProcessing.add(ant.leaveTunnel());
                    antsInTunnelCount--;
                    exitedThisStep = true;
                }

                if (!exitedThisStep) {
                    antsAfterExitProcessing.add(ant);
                }
            }

            currentAnts = antsAfterExitProcessing;

            if (antsInTunnelCount > 0) {
                java.util.Arrays.fill(turnedThisTimeStep, false);

                for (int i = 0; i < currentAnts.size(); i++)
                {
                    Ant ant1 = currentAnts.get(i);

                    if (!ant1.inTunnel() || turnedThisTimeStep[ant1.id()]) {
                        continue;
                    }

                    for (int j = i + 1; j < currentAnts.size(); j++) {
                        Ant ant2 = currentAnts.get(j);
                        if (!ant2.inTunnel() || turnedThisTimeStep[ant2.id()]) {
                            continue;
                        }

                        if (ant1.position() == ant2.position()) {
                            if (ant1.position() % 2 == 0) {
                                if (ant1.velocity() != ant2.velocity()) {
                                    currentAnts.set(i, ant1.turnAround());
                                    currentAnts.set(j, ant2.turnAround());
                                    turnedThisTimeStep[ant1.id()] = true;
                                    turnedThisTimeStep[ant2.id()] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (totalAnts == 0)
        {
            outputBuilder.append(0).append(" ").append(0).append("\n");
            return;
        }

        if (allExitInfos.isEmpty())
        {
            if (totalAnts > 0 && initialAnts.stream().anyMatch(a -> a.position() == 0 || a.position() == tunnelLengthScaled)) {

            }
        }

        int maxExitTimeScaled = 0;
        for (ExitInfo info : allExitInfos) {
            maxExitTimeScaled = Math.max(maxExitTimeScaled, info.time());
        }

        List<ExitInfo> lastMomentExits = new ArrayList<>();
        for (ExitInfo info : allExitInfos) {
            if (info.time() == maxExitTimeScaled) {
                lastMomentExits.add(info);
            }
        }

        Optional<ExitInfo> winner = lastMomentExits.stream().filter(ExitInfo::exitedFromLeft).min(Comparator.comparingInt(ExitInfo::antId));

        if (!winner.isPresent()) {
            winner = lastMomentExits.stream().min(Comparator.comparingInt(ExitInfo::antId));
        }

        outputBuilder.append(maxExitTimeScaled / 2).append(" ").append(winner.map(ExitInfo::antId).orElse(0)).append("\n");
    }
}