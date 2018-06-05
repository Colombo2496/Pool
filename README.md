 The Final Implementation of the assignment INFO3220

********
Branches
********

Branches: The branches are used to implement different extensions of the code.
Once they are complete/ready to run they will be merged with the master.

*100% COMPLETE* | PrevShot Branch: <- Need to merge with master
	- press 'r' at any point to revert the game to last time shot
	- If no opportunities are given yet. Revert game to read json File again

Extension Branches: "Contains various branches"

*85% COMPLETE* | resetCue Branch:
  - If cueBall enters one of the pockets, it is automatically placed on the
  table again for taking more shots.
  - Extensions:
    1. Place the cueBall behind the kitchen line. Click on the position that is desired
    to drop the ball in-order to play. COMPLETE
    2. If it's not behind the line send a box to the user to place behind the
      line. TODO
*0% COMPLETE* | Statistics Branch:
  - Press the 's' button to pop up a statistics window.
  - **Statistics WINDOW** includes:
    - Pocket statistics:
      1. How many balls fell into the Pocket
      2. Luckiest Pocket:
        - Which pocket/s have the maximum balls inside (display tied pockets too)
      3. Dodgy pocket:
        - Which pocket/s have the minimum balls inside
    - Cue Ball Statistics:
      1. Accuracy
        - How often the ball collides against another ball.
      2. Unlucky Shot/s:
        - Number of times it fell into a pocket (Don't be a Noob)
   - ***DEV tips***
      1. Use pointers only (maybe sharedPointers?)
      2. Connect to the Dialog (using the m_game inside)


*********
Requirements
*********

1. Use Memento Design (DONE)
2. Use additional Pattern: Cannot be already present within the assignment even
if it's a seperate instance.
