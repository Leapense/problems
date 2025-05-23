import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static final double EARTH_RADIUS_KM = 6378.0;

    private static class Point3D {
        final double x;
        final double y;
        final double z;

        public Point3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    private static Point3D convertToCartesian(double latDegrees, double lonDegrees, double radius) {
        double latRad = Math.toRadians(latDegrees);
        double lonRad = Math.toRadians(lonDegrees);

        double cartesianX = radius * Math.cos(latRad) * Math.cos(lonRad);
        double cartesianY = radius * Math.cos(latRad) * Math.sin(lonRad);
        double cartesianZ = radius * Math.sin(latRad);
        return new Point3D(cartesianX, cartesianY, cartesianZ);
    }

    private static double calculateDotProduct(Point3D vector1, Point3D vector2) {
        return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
    }

    public static void main(String[] args) {
        try (Scanner inputScanner = new Scanner(System.in)) {
            int testCaseCounter = 1;

            while (true) {
                int numberOfLocations = inputScanner.nextInt();
                if (numberOfLocations == 0) {
                    break;
                }

                double satelliteLatitude = inputScanner.nextDouble();
                double satelliteLongitude = inputScanner.nextDouble();
                double satelliteAltitudeKm = inputScanner.nextDouble();

                Point3D satellitePosition = convertToCartesian(satelliteLatitude, satelliteLongitude,
                        EARTH_RADIUS_KM + satelliteAltitudeKm);

                System.out.println("Test case " + testCaseCounter + ":");

                List<String> visibleLocationLabelsList = new ArrayList<>();

                for (int i = 0; i < numberOfLocations; i++) {
                    String locationLabel = inputScanner.next();
                    double locationLatitude = inputScanner.nextDouble();
                    double locationLongitude = inputScanner.nextDouble();

                    Point3D locationPosition = convertToCartesian(locationLatitude, locationLongitude,
                            EARTH_RADIUS_KM);

                    double sDotL = calculateDotProduct(satellitePosition, locationPosition);

                    double earthRadiusSquared = EARTH_RADIUS_KM * EARTH_RADIUS_KM;

                    if (sDotL > earthRadiusSquared) {
                        visibleLocationLabelsList.add(locationLabel);
                    }
                }

                for (String label : visibleLocationLabelsList) {
                    System.out.println(label);
                }
                System.out.println();

                testCaseCounter++;
            }
        }
    }
}