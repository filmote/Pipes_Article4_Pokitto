#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

#define MENU_GAMEOVER_OVERALL_X_POS   19
#define MENU_GAMEOVER_OVERALL_Y_POS   37
#define MENU_GAMEOVER_OVERALL_WIDTH   72
#define MENU_GAMEOVER_OVERALL_HEIGHT  13
#define MENU_GAMEOVER_TEXT_X_POS      MENU_GAMEOVER_OVERALL_X_POS + 4
#define MENU_GAMEOVER_TEXT_Y_POS      MENU_GAMEOVER_OVERALL_Y_POS + 4


/* ----------------------------------------------------------------------------
 *   Render the Game Over screen.
 *   
 *   If this is the last puzzle in the level, the message 'Level Finished' is
 *   displayed otherwise a simple 'Congratulations' is shown.
 */
void Game::gameOver() { 

  renderBackground();


  // Render message ..
  
  PD::setColor(1);
  PD::fillRect(MENU_GAMEOVER_OVERALL_X_POS, MENU_GAMEOVER_OVERALL_Y_POS, MENU_GAMEOVER_OVERALL_WIDTH, MENU_GAMEOVER_OVERALL_HEIGHT);
  PD::setColor(8);
  PD::fillRect(MENU_GAMEOVER_OVERALL_X_POS + 1, MENU_GAMEOVER_OVERALL_Y_POS + 1, MENU_GAMEOVER_OVERALL_WIDTH - 2, MENU_GAMEOVER_OVERALL_HEIGHT - 2);
  PD::setColor(4, 0);

  if (puzzle.index == getNumberOfPuzzles(puzzle.level) - 1) {

    PD::setCursor(MENU_GAMEOVER_TEXT_X_POS + 3, MENU_GAMEOVER_TEXT_Y_POS);
    PD::print("Level Finished!");

  }
  else {

    PD::setCursor(MENU_GAMEOVER_TEXT_X_POS, MENU_GAMEOVER_TEXT_Y_POS);
    PD::print("Congratulations!");

  }


  // If the user has pressed A or B, write the completed puzzle to the EEPROM and either
  // start the next puzzle (if there are more puzzles in the current level) or return to
  // the level select screen so they can choose a different level.

  if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B)) { 

    puzzle.index++;
    cookie->updateLevel(puzzle.level, puzzle.index);

    if (puzzle.index == getNumberOfPuzzles(puzzle.level)) {

      gameState = STATE_LEVEL_SELECT;

    }
    else {

      gameState = STATE_INIT_GAME;

    }

  }
    
}
