# Stone-Paper-Scissors-Game
A console-based Stone, Paper, Scissors game written in C++. Includes multiple rounds, a scoring system, colorful UI feedback, and a final winner summary.

# ✊✋✌️ Stone-Paper-Scissors Game (C++)

This is a fun console-based implementation of the classic **Stone-Paper-Scissors** game written in **C++**. It allows a human player to play against the computer for 1 to 10 rounds, with score tracking and a visual color-based winner indicator.

---

## 🎮 How It Works

- The player chooses the number of rounds (1–10).
- In each round:
  - The player chooses: `Stone`, `Paper`, or `Scissors`.
  - The computer randomly chooses its move.
  - The round winner is determined.
  - The result is displayed with a color:
    - 🟢 Green → Player wins
    - 🔴 Red → Computer wins
    - 🟡 Yellow → Draw
- After all rounds, the game displays the final results.

---

## 🔧 Features

- Multi-round gameplay (up to 10 rounds).
- Tracks wins for player, computer, and draws.
- Declares a final winner.
- Uses terminal colors to show round outcomes.
- Easy-to-understand input/output.
- Uses `enum`, `struct`, `functions`, and random number generation.

---

## 🧠 Technical Concepts Used

- **Enumerations (`enum`)**: For game choices and winners.
- **Structures (`struct`)**: To organize round info and game results.
- **Random number generation**: To simulate computer choices.
- **Functions**: For modular game logic (play rounds, check winner, show results, etc.).
- **Console color formatting**: For user-friendly output feedback using `system("color")`.

---

## 🖥️ How to Compile and Run

1. Make sure you have a C++ compiler installed (e.g. `g++`).
2. Save the file as `Game-stone-paper-scissors.cpp`.
3. Compile and run:

```bash
g++ Game-stone-paper-scissors.cpp -o Game
./Game

