#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
int main() {
    MinesweeperBoard plansza2(5, 5, DEBUG);
    MSBoardTextView view ( plansza2 );
    MSTextController ctrl ( plansza2, view );
   // plansza2.debug_display();
    ctrl.play();
}
