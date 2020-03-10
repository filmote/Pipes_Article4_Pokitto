#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


// Level select menu ..

#define MENU_LEVEL_SELECT_OVERALL_WIDTH      74
#define MENU_LEVEL_SELECT_OVERALL_X_POS      18
#define MENU_LEVEL_SELECT_OVERALL_Y_POS      18
#define MENU_LEVEL_SELECT_OVERALL_HEIGHT     52

#define MENU_LEVEL_SELECT_ITEM_X_POS         MENU_LEVEL_SELECT_OVERALL_X_POS + 4
#define MENU_LEVEL_SELECT_ITEM_1_Y_POS       MENU_LEVEL_SELECT_OVERALL_Y_POS + 3
#define MENU_LEVEL_SELECT_ITEM_2_Y_POS       MENU_LEVEL_SELECT_ITEM_1_Y_POS + 10
#define MENU_LEVEL_SELECT_ITEM_3_Y_POS       MENU_LEVEL_SELECT_ITEM_2_Y_POS + 10
#define MENU_LEVEL_SELECT_ITEM_4_Y_POS       MENU_LEVEL_SELECT_ITEM_3_Y_POS + 10
#define MENU_LEVEL_SELECT_ITEM_5_Y_POS       MENU_LEVEL_SELECT_ITEM_4_Y_POS + 10
#define MENU_LEVEL_SELECT_ITEM_WIDTH         68   
#define MENU_LEVEL_SELECT_ITEM_HEIGHT        7


// Quit / restart menu ..

#define MENU_QUIT_RESTART_OVERALL_WIDTH      74
#define MENU_QUIT_RESTART_OVERALL_X_POS      18
#define MENU_QUIT_RESTART_OVERALL_Y_POS      30
#define MENU_QUIT_RESTART_OVERALL_HEIGHT     22

#define MENU_QUIT_RESTART_ITEM_X_POS         MENU_QUIT_RESTART_OVERALL_X_POS + 4
#define MENU_QUIT_RESTART_ITEM_1_Y_POS       MENU_QUIT_RESTART_OVERALL_Y_POS + 3
#define MENU_QUIT_RESTART_ITEM_2_Y_POS       MENU_QUIT_RESTART_ITEM_1_Y_POS + 10

#define MENU_QUIT_RESTART_ITEM_WIDTH         68   
#define MENU_QUIT_RESTART_ITEM_HEIGHT        7


/* ----------------------------------------------------------------------------
 *   Handle the scolling and selection of the levels.  
 */
void Game::levelSelect() {

  clearHighlightAndSelection();

  if (PC::buttons.pressed(BTN_UP) && levelSelect_selectedItem > 0) 					      { levelSelect_selectedItem--; }
  if (PC::buttons.pressed(BTN_DOWN) && levelSelect_selectedItem < sizeof(levels) - 1) 	  { levelSelect_selectedItem++; }
  if (PC::buttons.pressed(BTN_B)) 												          { gameState = STATE_SPLASH_INIT; }

  if (PC::buttons.pressed(BTN_A)) { 

    puzzle.level = levels[levelSelect_selectedItem];
    puzzle.index = 0;


    // If the player has completed some puzzles, give them the option to restart  
    // the level or puzzle.  Otherwise simply start the puzzle ..

    if (cookie->getLevelIndex(puzzle.level) > 0) {

      gameState = STATE_PUZZLE_SELECT;
      prevState = STATE_LEVEL_SELECT;
      puzzleSelect_selectedItem = 0;

    }
    else {

      gameState = STATE_INIT_GAME;

    }

  }
	
  
  // Render menu ..
  
  renderBackground(SPLASH_INCREMENTS_MAX);

  PD::setColor(1);
  PD::fillRect(MENU_LEVEL_SELECT_OVERALL_X_POS, MENU_LEVEL_SELECT_OVERALL_Y_POS, MENU_LEVEL_SELECT_OVERALL_WIDTH, MENU_LEVEL_SELECT_OVERALL_HEIGHT);
  PD::setColor(8);
  PD::fillRect(MENU_LEVEL_SELECT_OVERALL_X_POS + 1, MENU_LEVEL_SELECT_OVERALL_Y_POS + 1, MENU_LEVEL_SELECT_OVERALL_WIDTH - 2, MENU_LEVEL_SELECT_OVERALL_HEIGHT - 2);

  renderLevelDetail(MENU_LEVEL_SELECT_ITEM_X_POS, MENU_LEVEL_SELECT_ITEM_1_Y_POS, levels[0], levelSelect_selectedItem == 0);
  renderLevelDetail(MENU_LEVEL_SELECT_ITEM_X_POS, MENU_LEVEL_SELECT_ITEM_2_Y_POS, levels[1], levelSelect_selectedItem == 1);
  renderLevelDetail(MENU_LEVEL_SELECT_ITEM_X_POS, MENU_LEVEL_SELECT_ITEM_3_Y_POS, levels[2], levelSelect_selectedItem == 2);
  renderLevelDetail(MENU_LEVEL_SELECT_ITEM_X_POS, MENU_LEVEL_SELECT_ITEM_4_Y_POS, levels[3], levelSelect_selectedItem == 3);
  renderLevelDetail(MENU_LEVEL_SELECT_ITEM_X_POS, MENU_LEVEL_SELECT_ITEM_5_Y_POS, levels[4], levelSelect_selectedItem == 4);

}


/* ----------------------------------------------------------------------------
 *   Render a single level menu item.  
 */
void Game::renderLevelDetail(byte x, byte y, byte level, byte highlight) {

  if (highlight) {
	  
  	PD::setColor(1);
  	PD::fillRect(x - 1, y - 1, MENU_LEVEL_SELECT_ITEM_WIDTH, MENU_LEVEL_SELECT_ITEM_HEIGHT);
    PD::setColor(8, 1);
	  
  }
  else {

    PD::setColor(4, 8);

  }
	
  PD::setCursor(x, y);
  
  switch (level) {

    case PUZZLE_5X5:
      PD::print("Practice");
      PD::setCursor(x + 48, y);
      PD::print(cookie->getLevelIndex(PUZZLE_5X5) < 10 ? " " : "");
      PD::print(cookie->getLevelIndex(PUZZLE_5X5), 10);
      PD::print("/");
      PD::print(puzzles_5x5_count, 10);
      break;

    case PUZZLE_6X6:
      PD::print("Easy");
      PD::setCursor(x + 48, y);
      PD::print(cookie->getLevelIndex(PUZZLE_6X6) < 10 ? " " : "");
      PD::print(cookie->getLevelIndex(PUZZLE_6X6), 10);
      PD::print("/");
      PD::print(puzzles_6x6_count, 10);
      break;

    case PUZZLE_7X7:
      PD::print("Medium");
      PD::setCursor(x + 48, y);
      PD::print(cookie->getLevelIndex(PUZZLE_7X7) < 10 ? " " : "");
      PD::print(cookie->getLevelIndex(PUZZLE_7X7), 10);
      PD::print("/");
      PD::print(puzzles_7x7_count, 10);
      break;

    case PUZZLE_8X8:
      PD::print("Hard");
      PD::setCursor(x + 48, y);
      PD::print(cookie->getLevelIndex(PUZZLE_8X8) < 10 ? " " : "");
      PD::print(cookie->getLevelIndex(PUZZLE_8X8), 10);
      PD::print("/");
      PD::print(puzzles_8x8_count, 10);
      break;

    case PUZZLE_9X9:
      PD::print("Extreme");
      PD::setCursor(x + 48, y);
      PD::print(cookie->getLevelIndex(PUZZLE_9X9) < 10 ? " " : "");
      PD::print(cookie->getLevelIndex(PUZZLE_9X9), 10);
      PD::print("/");
      PD::print(puzzles_9x9_count, 10);
      break;  		

    }
  
}


/* ----------------------------------------------------------------------------
 *   Handle the puzzle select menu.  
 *   
 *   Users can simply restart the level or continue playing.  If this screen
 *   was accessed via the 'level select' screen the "Continue Playing" message  
 *   is shown otherwise the "Restart Puzzle" message is displayed.
 */
void Game::puzzleSelect() {

  clearHighlightAndSelection();
   
  if (PC::buttons.pressed(BTN_UP) && puzzleSelect_selectedItem > 0)         { puzzleSelect_selectedItem--; }
  if (PC::buttons.pressed(BTN_DOWN) && puzzleSelect_selectedItem < 1)       { puzzleSelect_selectedItem++; }
  if (PC::buttons.pressed(BTN_B))                                           { gameState = STATE_LEVEL_SELECT; }
  
  if (PC::buttons.pressed(BTN_A)) { 
	  
	  if (puzzleSelect_selectedItem == 1) {
		  
		puzzle.index = 0;
        cookie->updateLevel(puzzle.level, puzzle.index);
           
	  }
	  
	  if (puzzleSelect_selectedItem == 0) {


          // If all puzzles in the current level are completed, simply re-show the last puzzle ..
          
          if (cookie->getLevelIndex(puzzle.level) == getNumberOfPuzzles(puzzle.level)) {
      		  puzzle.index = cookie->getLevelIndex(puzzle.level) - 1;
          }
          else {
            cookie->getLevelIndex(puzzle.level);
          }
    		  
	  }
	  
	  gameState = STATE_INIT_GAME;
	  
  }
  
	
  
  // Render menu ..

  renderBackground(SPLASH_INCREMENTS_MAX);

  PD::setColor(1);
  PD::fillRect(MENU_QUIT_RESTART_OVERALL_X_POS, MENU_QUIT_RESTART_OVERALL_Y_POS, MENU_QUIT_RESTART_OVERALL_WIDTH, MENU_QUIT_RESTART_OVERALL_HEIGHT);
  PD::setColor(8);
  PD::fillRect(MENU_QUIT_RESTART_OVERALL_X_POS + 1, MENU_QUIT_RESTART_OVERALL_Y_POS + 1, MENU_QUIT_RESTART_OVERALL_WIDTH - 2, MENU_QUIT_RESTART_OVERALL_HEIGHT - 2);

  const char s1[] = {"Continue Playing"};
  const char s2[] = {"  Restart Puzzle "};
  const char s3[] = {"    Reset Level"};

  if (prevState == STATE_LEVEL_SELECT) {
    renderPuzzleOption(MENU_QUIT_RESTART_ITEM_X_POS, MENU_QUIT_RESTART_ITEM_1_Y_POS, s1, (puzzleSelect_selectedItem == 0));
  }
  else {
    renderPuzzleOption(MENU_QUIT_RESTART_ITEM_X_POS, MENU_QUIT_RESTART_ITEM_1_Y_POS, s2, (puzzleSelect_selectedItem == 0));
  }
  renderPuzzleOption(MENU_QUIT_RESTART_ITEM_X_POS, MENU_QUIT_RESTART_ITEM_2_Y_POS, s3, (puzzleSelect_selectedItem == 1));

}


/* ----------------------------------------------------------------------------
 *   Render a single puzzle menu item.  
 */
void Game::renderPuzzleOption(byte x, byte y, const char* message, byte highlight) {

  if (highlight) {
	  
    PD::setColor(1);
    PD::fillRect(x - 1, y - 1, MENU_QUIT_RESTART_ITEM_WIDTH, MENU_QUIT_RESTART_ITEM_HEIGHT);
    PD::setColor(8, 1);
	  
  }
  else {

    PD::setColor(4, 8);

  }
	
  PD::setCursor(x, y);
  PD::print(message);
  
}
