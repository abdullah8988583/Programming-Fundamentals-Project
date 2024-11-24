# Programming-Fundamentals-Project
Tic Tac Toe
 
 Introduction:
 The "Tic Tac Toe Game" project aims to create a feature-rich implementation of the 
classic Tic Tac Toe game using the C programming language. This project provides a 
user-friendly, interactive experience for players, offering both Player vs. Player (PvP) 
and Player vs. Computer (PvC) modes with adjustable difficulty levels. The motivation 
for this project stems from the desire to explore modular programming, file handling, and
 AI strategies in C while delivering an engaging gaming experience
 Background:
 Tic Tac Toe is a simple, yet strategic game widely used for educational purposes in 
programming. This project was selected to:
  Understand game mechanics and logic.
  Implement player interaction and input handling in C.
  Incorporate AI-based decision-making at varying difficulty levels.
  Persist game results using file handling for post-game review.
 Research Focus:
  Efficient implementation of game rules and state updates.
  Designing algorithms for computers moves across difficulty levels.
  Handling input/output for smooth user interaction.
 Project Specifications:
 The project provides the following specifications:
 1. Modes:
 o Player vs. Player (PvP).
 o Player vs. Computer (PvC).
 2. Difficulty Levels (PvC Mode) : Easy, Medium, and Hard.
 3. Game Board: A dynamic 3x3 grid updated in real time.
 4. Draw Condition : Display draw if there is no winner in the game.
Problem Analysis:
 Key problems identified in the project include:
  Game Board Representation : Representing the game board in a way that is 
easy to update and display.
  User Input Validation : Ensuring that inputs are within bounds and positions are 
not already occupied and if user input invalid position give errors.
  AI In Game: Implementing an AI algorithm that adapts to difficulty levels.
  Winning Logic : Implementing logic to evaluate all possible winning combinations
 in hard mode for computer vs player to make it hard.
  Draw Condition : Detecting a stalemate when the board is full.
 Solution Design:
 Game Details:
 The game was designed to deliver a seamless experience with the following features:
 Key Features:
  PvP mode for two-player interaction.
  PvC mode with AI opponent, adjustable to Easy, Medium, and Hard levels.
  Real-time board display and turn-by-turn updates.
  Persistent result storage in results.txt.
  A visually enhanced logo and organized menu system.
 Functionality and Design:
 1. Board Setup: The board is initialized as a 3x3 grid, with positions 1–9 for player 
moves.
 2. Player Input Handling : Validates input to prevent overwriting and ensure moves 
are within the grid.
 3. AI Algorithm :
 o Easy: Random moves.
 o Medium: Random moves with basic blocking logic.
 o Hard: Advanced decision-making with win-block prioritization.
4. Winner Determination : Checks rows, columns, and diagonals for three matching 
symbols.
 5. Result Persistence : Outcomes are written to a file, including player names, 
winner, mode, and difficulty.
 Implementation & Testing:
 The program was implemented using modular functions for tasks such as resetting the 
board, validating inputs, updating the game state, and determining the winner.
 Key modules include:
 1. Game Modes: Switches between PvP and PvC modes based on user input.
 2. AI Logic: AI difficulty levels with increasing strategic complexity.
 3. File Handling : Records game outcomes in results.txt.
 Testing Scenarios:
  Valid Moves: Ensuring moves update the board correctly.
  Invalid Inputs : Detecting and prompting for re-entry.
  Winning Logic : Validating winning combinations across rows, columns, and 
diagonals.
  AI Decisions: Testing moves selection across difficulty levels.
  File Handling : Verifying accurate result logging
Conclusion (Summary & Discussion):
 The console-based Tic Tac Toe Game successfully provides an engaging experience. 
In this we use loops, functions, arrays, conditional statements, etc, to make efficient 
console input/output handling, and algorithmic problem-solving in C.
Key Outcomes:
  Delivered a functional, interactive console game.
  Enhanced understanding of AI decision-making and difficulty scaling.
  Gained hands-on experience with file operations for result persistence
