//
// Created by Pawel Czarzasty on 28/03/2024.
//

#include "MSBoardTextView.h"
using namespace std;
MSBoardTextView::MSBoardTextView(MinesweeperBoard &plansza) : plansza(plansza) {

}

void MSBoardTextView::display() {
    for(int row = 0; row<plansza.getBoardHeight(); row++){
        for(int col = 0; col<plansza.getBoardWidth(); col++){
            cout<<"[";
            if(plansza.isRevealed(row, col) == true)cout<<plansza.countMines(row, col);
            else{
                if(plansza.hasFlag(row, col)== true)cout<<"f";else cout<<" ";
            }
            cout<<"]";
        }
        cout<<endl;
    }
    cout<<endl;
}
