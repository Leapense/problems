use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let reader = stdin.lock();

    for line in reader.lines() {
        let line = line.unwrap();
        let nums: Vec<usize> = line.split_whitespace().map(|s| s.parse().unwrap()).collect();
        
        let n = nums[0];
        let k = nums[1];

        if n == 0 {
            break;
        }

        // Initialize wins and losses for each player
        let mut wins = vec![0; n + 1];
        let mut losses = vec![0; n + 1];

        let total_games = k * n * (n - 1) / 2;
        
        for _ in 0..total_games {
            let mut game_line = String::new();
            reader.read_line(&mut game_line).unwrap();
            let parts: Vec<&str> = game_line.split_whitespace().collect();

            let p1: usize = parts[0].parse().unwrap();
            let m1: &str = parts[1];
            let p2: usize = parts[2].parse().unwrap();
            let m2: &str = parts[3];

            // Determine the outcome of the game
            if m1 == m2 {
                // Draw
                continue;
            }

            if (m1 == "rock" && m2 == "scissors") ||
               (m1 == "scissors" && m2 == "paper") ||
               (m1 == "paper" && m2 == "rock") {
                // Player 1 wins
                wins[p1] += 1;
                losses[p2] += 1;
            } else {
                // Player 2 wins
                wins[p2] += 1;
                losses[p1] += 1;
            }
        }

        // Calculate and print win averages
        for i in 1..=n {
            let w = wins[i];
            let l = losses[i];
            if w + l == 0 {
                println!("-");
            } else {
                let average = w as f64 / (w + l) as f64;
                println!("{:.3}", average);
            }
        }
        println!(); // Blank line between test cases
    }
}
