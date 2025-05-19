import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Die {
    int top, bottom, front, back, left, right;

    public Die() {
        this.top = 1;
        this.bottom = 6;
        this.front = 2;
        this.back = 5;
        this.left = 4;
        this.right = 3;
    }

    void rollEast() {
        int oldTop = this.top;
        int oldBottom = this.bottom;
        int oldLeft = this.left;
        int oldRight = this.right;

        this.top = oldRight;
        this.bottom = oldLeft;
        this.left = oldTop;
        this.right = oldBottom;
    }

    void rollWest() {
        int oldTop = this.top;
        int oldBottom = this.bottom;
        int oldLeft = this.left;
        int oldRight = this.right;

        this.top = oldLeft;
        this.bottom = oldRight;
        this.left = oldBottom;
        this.right = oldTop;
    }

    void rollNorth() {
        int oldTop = this.top;
        int oldBottom = this.bottom;
        int oldFront = this.front;
        int oldBack = this.back;

        this.top = oldFront;
        this.bottom = oldBack;
        this.front = oldBottom;
        this.back = oldTop;
    }

    void rollSouth() {
        int oldTop = this.top;
        int oldBottom = this.bottom;
        int oldFront = this.front;
        int oldBack = this.back;

        this.top = oldBack;
        this.bottom = oldFront;
        this.front = oldTop;
        this.back = oldBottom;
    }

    public int getTop() {
        return this.top;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numTestCases = Integer.parseInt(br.readLine());
        StringBuilder resultOutput = new StringBuilder();

        for (int t = 0; t < numTestCases; t++) {
            String sequence = br.readLine();
            processSequence(sequence, resultOutput);
        }

        System.out.print(resultOutput.toString());
    }

    private static void processSequence(String sequence, StringBuilder resultOutput) {
        int x = 0;
        int y = 0;
        Die die = new Die();
        int dirMultiplier = 1;

        int ptr = 0;
        while (ptr < sequence.length()) {
            char currentChar = sequence.charAt(ptr);

            if (Character.isDigit(currentChar)) {
                StringBuilder numStr = new StringBuilder();
                while (ptr < sequence.length() && Character.isDigit(sequence.charAt(ptr))) {
                    numStr.append(sequence.charAt(ptr));
                    ptr++;
                }

                int count = Integer.parseInt(numStr.toString());
                char moveChar = sequence.charAt(ptr);

                int actualRolls = count % 4;

                if (moveChar == 'X') {
                    if (dirMultiplier == 1) {
                        x += count;
                        for (int k = 0; k < actualRolls; k++)
                            die.rollEast();
                    } else {
                        x -= count;
                        for (int k = 0; k < actualRolls; k++)
                            die.rollWest();
                    }
                } else {
                    if (dirMultiplier == 1) {
                        y += count;
                        for (int k = 0; k < actualRolls; k++)
                            die.rollNorth();
                    } else {
                        y -= count;
                        for (int k = 0; k < actualRolls; k++)
                            die.rollSouth();
                    }
                }

                ptr++;
            } else if (currentChar == 'X') {
                if (dirMultiplier == 1) {
                    x++;
                    die.rollEast();
                } else {
                    x--;
                    die.rollWest();
                }
                ptr++;
            } else if (currentChar == 'Y') {
                if (dirMultiplier == 1) {
                    y++;
                    die.rollNorth();
                } else {
                    y--;
                    die.rollSouth();
                }
                ptr++;
            } else if (currentChar == '-') {
                dirMultiplier = -1;
                ptr++;
            } else if (currentChar == '+') {
                dirMultiplier = 1;
                ptr++;
            } else if (currentChar == '.') {
                break;
            }
        }

        resultOutput.append("position (")
                .append(x)
                .append(",")
                .append(y)
                .append("), ")
                .append(die.getTop())
                .append(" dots\n");
    }
}