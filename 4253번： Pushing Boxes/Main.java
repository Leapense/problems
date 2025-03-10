import java.util.*;

public class Main {
    static class Box {
        int r, c;

        Box(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static int H, W;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int dataSet = 1;
        while (true) {
            H = sc.nextInt();
            W = sc.nextInt();
            if (H == 0 && W == 0)
                break;
            int n = sc.nextInt();
            ArrayList<Box> boxes = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int r = sc.nextInt();
                int c = sc.nextInt();
                boxes.add(new Box(r, c));
            }
            sc.nextLine();
            while (true) {
                String line = sc.nextLine().trim();
                if (line.equals("done"))
                    break;
                String[] parts = line.split("\\s+");
                String dir = parts[0];
                int m = Integer.parseInt(parts[1]);
                int executed = 0;
                for (int step = 1; step <= m; step++) {
                    boolean success = false;
                    ArrayList<Box> backup = copyBoxes(boxes);
                    if (dir.equals("down")) {
                        int wall = step;
                        ArrayList<Integer> order = getOrder(boxes, "down");
                        success = true;
                        for (int idx : order) {
                            Box b = boxes.get(idx);
                            if (b.r < wall) {
                                if (!tryPush(idx, 1, 0, boxes)) {
                                    success = false;
                                    break;
                                }
                            }
                        }
                    } else if (dir.equals("up")) {
                        int wall = H - step;
                        ArrayList<Integer> order = getOrder(boxes, "up");
                        success = true;
                        for (int idx : order) {
                            Box b = boxes.get(idx);
                            if (b.r + 1 > wall) {
                                if (!tryPush(idx, -1, 0, boxes)) {
                                    success = false;
                                    break;
                                }
                            }
                        }
                    } else if (dir.equals("left")) {
                        int wall = W - step;
                        ArrayList<Integer> order = getOrder(boxes, "left");
                        success = true;
                        for (int idx : order) {
                            Box b = boxes.get(idx);
                            if (b.c + 1 > wall) {
                                if (!tryPush(idx, 0, -1, boxes)) {
                                    success = false;
                                    break;
                                }
                            }
                        }
                    } else if (dir.equals("right")) {
                        int wall = step;
                        ArrayList<Integer> order = getOrder(boxes, "right");
                        success = true;
                        for (int idx : order) {
                            Box b = boxes.get(idx);
                            if (b.c < wall) {
                                if (!tryPush(idx, 0, 1, boxes)) {
                                    success = false;
                                    break;
                                }
                            }
                        }
                    }
                    if (!success) {
                        boxes = backup;
                        break;
                    }
                    executed++;
                }
            }
            Collections.sort(boxes, new Comparator<Box>() {
                public int compare(Box a, Box b) {
                    if (a.r != b.r)
                        return a.r - b.r;
                    return a.c - b.c;
                }
            });
            System.out.print("Data set " + dataSet + " ends with boxes at locations");
            for (Box b : boxes) {
                System.out.print(" (" + b.r + "," + b.c + ")");
            }
            System.out.println(".");
            dataSet++;
        }
    }

    static ArrayList<Box> copyBoxes(ArrayList<Box> boxes) {
        ArrayList<Box> ret = new ArrayList<>();
        for (Box b : boxes) {
            ret.add(new Box(b.r, b.c));
        }
        return ret;
    }

    static ArrayList<Integer> getOrder(ArrayList<Box> boxes, String dir) {
        ArrayList<Integer> order = new ArrayList<>();
        for (int i = 0; i < boxes.size(); i++) {
            order.add(i);
        }
        if (dir.equals("down")) {
            Collections.sort(order, (a, b) -> boxes.get(a).r - boxes.get(b).r);
        } else if (dir.equals("up")) {
            Collections.sort(order, (a, b) -> boxes.get(b).r - boxes.get(a).r);
        } else if (dir.equals("left")) {
            Collections.sort(order, (a, b) -> boxes.get(b).c - boxes.get(a).c);
        } else if (dir.equals("right")) {
            Collections.sort(order, (a, b) -> boxes.get(a).c - boxes.get(b).c);
        }
        return order;
    }

    static boolean tryPush(int idx, int dr, int dc, ArrayList<Box> boxes) {
        Box b = boxes.get(idx);
        int nr = b.r + dr, nc = b.c + dc;
        if (nr < 0 || nr >= H || nc < 0 || nc >= W)
            return false;
        int occupant = findBox(nr, nc, boxes);
        if (occupant == -1) {
            b.r = nr;
            b.c = nc;
            return true;
        } else {
            if (!tryPush(occupant, dr, dc, boxes))
                return false;
            if (findBox(nr, nc, boxes) != -1)
                return false;
            b.r = nr;
            b.c = nc;
            return true;
        }
    }

    static int findBox(int r, int c, ArrayList<Box> boxes) {
        for (int i = 0; i < boxes.size(); i++) {
            Box b = boxes.get(i);
            if (b.r == r && b.c == c)
                return i;
        }
        return -1;
    }
}
