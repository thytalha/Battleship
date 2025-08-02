# Battleship Game (C++)
A two-player Battleship game written in C++ for the terminal. Players begin by placing their ships using coordinates and then take turns attacking each other’s grid until one player destroys all enemy ships.

## Author: Talha Pasha
## How to Run

Use any C++ compiler (e.g., g++) to compile and run the game:

g++ -o battleship game.cpp  
./battleship

Replace `game.cpp` with your actual filename if it’s different.

## How to Play

- Each player places 5 ships on a 10x10 grid:
  - Carrier (5 cells)
  - Battleship (4 cells)
  - Cruiser (3 cells)
  - Submarine (3 cells)
  - Destroyer (2 cells)
- For each ship, players enter:
  - Starting row (A–J)
  - Starting column (1–10)
  - Direction: U (up), D (down), L (left), R (right)
- Ships cannot overlap or go out of bounds.
- After placement, players take turns attacking by entering a target coordinate.
- Hits are marked with `H`, misses with `M`.
- The game continues until all 5 ships of one player are destroyed and the winner is announced.

## Features

- Two-player terminal-based gameplay  
- Full ship placement with directional logic  
- Real-time attack handling with hit/miss detection  
- Input validation for row, column, and direction  
- Clear turn-by-turn flow and ship destruction messages  

## Example Output

Battleship Game:  
Enter name of Player Blue: Talha  
Enter name of Player Red: Pasha  

Talha places ships using starting coordinates and directions.  
Pasha places ships after Talha.  

Game begins...  

Talha's turn:  
Enter row (A-J): B  
Enter column (1-10): 4  
Result: It's a miss! :(
<br>
i.e., In case if there was no ship on these coordinates

Pasha's turn:  
Enter row (A-J): E  
Enter column (1-10): 7  
Result: It's a hit! :)
<br>
i.e., In case if there was any ship on these coordinates.

...and so on, until one player wins by destroying all five enemy ships.

## License

This project was created for learning purposes. Feel free to use, improve, or share it.
