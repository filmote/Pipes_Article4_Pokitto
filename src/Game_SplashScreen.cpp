#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* ----------------------------------------------------------------------------
 *  Initialise spalsch screen counter (used to delay the heading) ..
 */
void Game::initSplash() { 

}


/* ----------------------------------------------------------------------------
 *   Render the Splash screen.
 *   
 *   The pipes are rendered one-by-one to simulate the laying of pipe.  The
 *   rendering function allows the user to press the A button to skip past the
 *   animations or the B button to toggle sounds.
 */
void Game::renderSplash() { 

  if (splash_counter < 530) { splash_counter++; }
  int counter = splash_counter / 10;

  PD::fillScreen(11);

  if (counter >= 1) PD::drawBitmap(112,  0, Pipe_Straight_TB_NoFlange);
  if (counter >= 2) PD::drawBitmap(112, 16, Pipe_Corner_TL);
  if (counter >= 3) PD::drawBitmap(96,  16, Pipe_Corner_TR_NoFlange);
  if (counter >= 4) PD::drawBitmap(96,   0, Pipe_Corner_BL);
  if (counter >= 5) PD::drawBitmap(80,   0, Pipe_Straight_LR_NoFlange);
  if (counter >= 6) PD::drawBitmap(64,   0, Pipe_Straight_LR);
  if (counter >= 7) PD::drawBitmap(48,   0, Pipe_Corner_BR);
  if (counter >= 8) PD::drawBitmap(48,  16, Pipe_Straight_TB_NoFlange);
  if (counter >= 9) PD::drawBitmap(48,  32, Pipe_Corner_TR_NoFlange);
  if (counter >= 10) PD::drawBitmap(64,  32, Pipe_Corner_BL);
  if (counter >= 11) PD::drawBitmap(64,  48, Pipe_Straight_TB_NoFlange);

  if (counter >= 12) PD::drawBitmap(64,  64, Pipe_Corner_TL);

  if (counter >= 13) {
   
    PD::drawBitmap(48,  64, Pipe_Straight_LR);
    PD::drawBitmap(32,  64, Pipe_Tee_LR_B);

  }

  if (counter >= 14) {

    PD::drawBitmap(32,  80, Pipe_Straight_TB);
    PD::drawBitmap(16,  64, Pipe_Straight_LR);

  }

  if (counter >= 15) PD::drawBitmap(0,  64, Pipe_Tee_TB_R);

  if (counter >= 16) {

    PD::drawBitmap(0,  48, Pipe_Corner_BL);
    PD::drawBitmap(0,  80, Pipe_Straight_TB);

  }

  if (counter >= 21) PD::drawBitmap(0,    0, Pipe_Straight_TB_NoFlange);
  if (counter >= 22) PD::drawBitmap(0,   16, Pipe_Straight_TB);
  if (counter >= 23) PD::drawBitmap(0,   32, Pipe_Corner_TR_NoFlange);
  if (counter >= 24) PD::drawBitmap(16,  32, Pipe_Straight_LR);
  if (counter >= 25) PD::drawBitmap(32,  32, Pipe_Corner_TL);
  if (counter >= 26) PD::drawBitmap(32,  16, Pipe_Corner_BR);
  if (counter >= 27) PD::drawBitmap(48,  16, Pipe_Cross_Underlap_NoFlange);
  if (counter >= 28) PD::drawBitmap(64,  16, Pipe_Straight_LR_NoFlange);
  if (counter >= 29) PD::drawBitmap(80,  16, Pipe_Corner_BL);
  if (counter >= 30) PD::drawBitmap(80,  32, Pipe_Corner_TR_NoFlange);
  if (counter >= 31) PD::drawBitmap(96,  32, Pipe_Straight_LR);
  if (counter >= 32) PD::drawBitmap(112, 32, Pipe_Straight_LR_NoFlange);

  if (counter >= 37) PD::drawBitmap(0,    0, Pipe_Cross_Underlap_NoFlange);
  if (counter >= 38) PD::drawBitmap(16,   0, Pipe_Corner_BL);
  if (counter >= 39) PD::drawBitmap(16,  16, Pipe_Straight_TB);
  if (counter >= 40) PD::drawBitmap(16,  32, Pipe_Cross_Overlap_NoFlange);
  if (counter >= 41) PD::drawBitmap(16,  48, Pipe_Corner_TR_NoFlange);
  if (counter >= 42) PD::drawBitmap(32,  48, Pipe_Straight_LR);
  if (counter >= 43) PD::drawBitmap(48,  48, Pipe_Straight_LR_NoFlange);
  if (counter >= 44) PD::drawBitmap(64,  48, Pipe_Cross_Underlap_NoFlange);
  if (counter >= 45) PD::drawBitmap(80,  48, Pipe_Straight_LR_NoFlange);
  if (counter >= 46) PD::drawBitmap(96,  48, Pipe_Corner_BL);

  if (counter >= 47) {
    PD::drawBitmap(96,  64, Pipe_Straight_TB);
    PD::drawBitmap(96,  80, Pipe_Corner_TR_NoFlange);
  }

  if (counter >= 53) {

    PD::setColor(0);
    PD::fillRect(9, 25, 92, 37);
    PD::drawBitmap(10, 26, Heading);
    
  }

  if (PC::buttons.pressed(BTN_A)) {
    gameState = STATE_LEVEL_SELECT;
  }
  
}
