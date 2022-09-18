#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessboardcell.h"

class ChessBoard
{
public:
    ChessBoard(sf::RenderWindow &window);
    void draw();
    void handleEvent(const sf::Event &event);
    ChessBoardCell &getActiveCell();
    ChessBoardCell getSelectedCell() const;

private:
    sf::RenderWindow *m_Window;
    std::vector<ChessBoardCell> m_ChessBoardCells;
};

#endif