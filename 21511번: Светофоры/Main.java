import java.util.Scanner;

class TrafficLightSolver {
    private final double greenDuration;
    private final double redDuration;
    private final double distance;

    public TrafficLightSolver(double a, double b, double x) {
        this.greenDuration = a;
        this.redDuration = b;
        this.distance = x;
    }

    public double findMaxSpeed() {
        final double maxAllowedSpeed = 1000.0;
        double minTravelTime = this.distance / maxAllowedSpeed;

        double totalCycle = this.greenDuration + this.redDuration;

        if (totalCycle == 0) {
            return maxAllowedSpeed;
        }

        long numCycles = (long) (minTravelTime / totalCycle);
        double timeInCycle = minTravelTime - numCycles * totalCycle;

        double actualTravelTime;

        if (timeInCycle > this.greenDuration && timeInCycle < totalCycle) {
            actualTravelTime = (double) numCycles * totalCycle + totalCycle;
        } else {
            actualTravelTime = minTravelTime;
        }
        
        double speedBasedOnGreenStart = this.distance / actualTravelTime;

        if (this.greenDuration >= this.redDuration) {
            return maxAllowedSpeed;
        }

        double timeInCycleForFlexibleStart = minTravelTime % totalCycle;

        if (timeInCycleForFlexibleStart > this.greenDuration && timeInCycleForFlexibleStart < this.redDuration) {
             double adjustedTravelTime = (double) numCycles * totalCycle + this.redDuration;
             return this.distance / adjustedTravelTime;
        } else {
             return maxAllowedSpeed;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            double a = scanner.nextDouble();
            double b = scanner.nextDouble();
            double x = scanner.nextDouble();

            TrafficLightSolver solver = new TrafficLightSolver(a, b, x);
            double result = solver.findMaxSpeed();

            System.out.printf("%.10f%n", result);
        }
    }
}