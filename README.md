# ProjectStone
  - 2 = Paper
  - 3 = Scissors

A simple console-based Rock–Paper–Scissors game in C++ with round-by-round results and final score display.

README.md (suggested content)

# Rock Paper Scissors — Console Game (C++)

A simple, interactive console implementation of Rock–Paper–Scissors written in C++. The player plays against the computer for a configurable number of rounds; the program shows each round's choices and winner and displays final game results.

## Features
- Choose number of rounds (1–10)
- Player vs. computer rounds
- Round summary (player choice, computer choice, round winner)
- Final scoreboard with overall winner
- Simple, portable C++ code suitable for learning basic control flow and enums

## Requirements
- C++ compiler with C++11 support (g++, clang, MSVC)
- Standard library only

## Build & Run
Compile with g++:
g++ -std=c++11 -o rock_paper_scissors main.cpp

Run:
./rock_paper_scissors
(on Windows:)
rock_paper_scissors.exe

## Controls
- When prompted, enter the number of rounds (1–10).
- For each round, choose:
  - 1 = Stone
  - 2 = Paper
  - 3 = Scissors
- After the game, press Y to play again or N to exit.

## How it works (brief)
- Player input is read each round.
- Computer choice is generated randomly.
- The program uses enums to represent choices and determine round winners.
- Scores are tallied and the overall winner is announced.

## Notes & Improvements
- The code uses system calls (`system("cls")` / `system("clear")` and `system("color ...")`) which are platform-specific; you may want to conditionalize them for cross-platform behavior.
- Ensure you include <ctime> for srand(time(NULL)) if not already included.
- Consider adding input validation for non-numeric input and replacing `system()` calls with portable methods.

## File structure (example)
- main.cpp — game source code
- README.md — this file

## License
Choose a license (e.g., MIT) and add a LICENSE file if you want others to reuse your code.

Need this in a slightly different tone or a shorter GitHub About/README version? I can also produce the README.md file content ready to paste into your repository. 
