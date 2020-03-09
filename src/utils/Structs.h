

/* ----------------------------------------------------------------------------
 *  Basic structure to hold a node value and coordinates ..
 */
struct Node {
  byte x;
  byte y;
  byte value;
};


/* ----------------------------------------------------------------------------
 *  Player structure to record the highlighted and selected node ..
 */
struct Player {
  Node highlightedNode;
  Node selectedNode;
};

/* ----------------------------------------------------------------------------
 *  Scroll bar structure used to record the scroll bar location and rendering 
 *  properties.  These change depending on the number of rows in the puzzle. 
 */
struct Slider {
  byte unit;                              // Number of pixels / row for the slider.
  byte overall;                           // Height of the slider portion in pixels.
};


/* ----------------------------------------------------------------------------
 *  Puzzle structure.
 */
struct Puzzle {
  byte level;                             // Level being played, eg. PUZZLE_5X5, PUZZLE_6X6 ..
  byte index;                             // Puzzle within the current level being played.
  Node maximum;                           // Used to store the dimensions of the puzzle based
                                          // on the puzzle level, eg. PUZZLE_5X5 has a maximum
                                          // x and y value of 5.
  Node offset;                            // Stores the offest x and y values to ensure the 
                                          // is rendered centrally on the screen.
  Slider slider;                          // Scrollbar slider details.
  byte board[9][9];                       // Actual board details - supports maximum of 9 x 9.
};