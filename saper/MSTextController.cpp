//
// Created by c on 4/4/24.
//
#include "MSTextController.h"
using namespace std;
MSTextController::MSTextController(MinesweeperBoard &plansza, MSBoardTextView &widok) : plansza(plansza), widok(widok) {

}

void MSTextController::play() {
    int x, y;
    string tryb;
    while(plansza.getGameState() == RUNNING){
       // plansza.debug_display();
        widok.display();
        cout<<"podaj koordy pola i tryb (f- flaga, o- odkryj)";
        cin>>x>>y>>tryb;
        if(tryb == "o"){
            plansza.revealField(x-1, y-1);
        }else{
            if(tryb == "f"){
                plansza.toggleFlag(x-1, y-1);
            }
        }
        if(plansza.getGameState() == RUNNING){
            cout<<"KONTYNUUJ"<<endl;
        }else{
            if(plansza.getGameState() == FINISHED_WIN){
                cout<<"WYGRAŁEŚ!"<<endl;
                return;
            }else{
                cout<<"PRZEGRAŁEŚ!"<<endl;
                return;
            }

        }
    }
}
