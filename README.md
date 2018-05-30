 The Final Implementation of the assignment INFO3220

********
Branches
********

Branches: The branches are used to implement different extensions of the code.
Once they are complete/ready to run they will be merged with the master.

PrevShot Branch: COMPLETE <- Need to merge with master
	- press 'r' at any point to revert the game to last time shot
	- If no opportunities are given yet. Revert game to read json File again

Extension Branches: "Contains various branches"

resetCue Branch:
  - If cueBall enters one of the pockets, it is automatically placed on the
  table again for taking more shots.
  - Extensions:
    1. Place the cueBall behind the kitchen line. Click on the position that is desired
    to drop the ball in-order to play.
    2. If it's not behind the line send a box to the user to place behind the
      line



*********
Requirements
*********

1. Use Memento Design (DONE)
2. Use additional Pattern: Cannot be already present within the assignment even
if it's a seperate instance.
