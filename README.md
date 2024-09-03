# Nim-to-Win Game

## Overview
The Nim-to-Win Game is a classic mathematical strategy game where two players take turns removing objects from distinct heaps or piles. The goal of the game is to avoid being the player who has to take the last object. This implementation of the Nim game provides a command-line interface for gameplay between two human players or a human and a computer opponent.

## Features
- **Two-Player Mode**: Allows two human players to play against each other.
- **Human vs. Computer Mode**: Play against an AI that uses a winning strategy based on game theory.
- **Customizable Game Settings**: Players can set the initial number of heaps and the number of objects in each heap.
- **Turn-based Gameplay**: The game provides a clear indication of whose turn it is and prompts the player for their move.
- **Error Handling**: Ensures players make valid moves by enforcing the rules of the game.
- **Winning Strategy**: The computer opponent is programmed with a strategy to maximize its chances of winning, making the game challenging.

## Key Concepts Demonstrated
- **Game Theory**: The implementation showcases the application of combinatorial game theory, specifically the winning strategy for the game of Nim.
- **Object-Oriented Programming**: The game structure is designed using object-oriented principles, with clear separation of concerns between game logic and user interaction.
- **AI and Algorithm Design**: The AI opponent uses a mathematical strategy to determine the optimal move at each turn, demonstrating basic AI implementation.
- **Input Validation**: The game ensures that all player inputs are valid and prompts for correction if necessary, highlighting robust error handling.
- **Control Flow and Looping Constructs**: The game flow is controlled using loops and conditional statements, ensuring smooth and continuous gameplay until a winner is determined.

## How to Play
1. Run the program and select the mode: Player vs. Player or Player vs. Computer.
2. Players take turns to remove any number of objects from a single heap.
3. The player forced to take the last object loses the game.
4. The game ends when one player is declared the winner.

## Future Improvements
- **Graphical User Interface (GUI)**: Expanding the game to include a GUI for a more interactive experience.
- **Online Multiplayer**: Allowing players to compete against others online.
- **Advanced AI**: Implementing different levels of AI difficulty to cater to a range of player skills.
