#include "chessboard.h"
#include <iostream>

ChessBoard::ChessBoard(sf::RenderWindow &window)
    : m_Window(&window)
{
    bool white = true;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ChessBoardCell chessBoardCell(window, white ? sf::Color::Green : sf::Color::Blue);
            chessBoardCell.setPosition(j * 100, i * 100);
            if (i < 2 || i > 6)
            {
                chessBoardCell.setAvailable(false);
            }
            m_ChessBoardCells.push_back(chessBoardCell);
            white = !white;
        }
        white = !white;
    }
}

void ChessBoard::draw()
{
    for (auto it = m_ChessBoardCells.begin(); it != m_ChessBoardCells.end(); it++)
    {
        it->draw();
    }
}

void ChessBoard::handleEvent(const sf::Event &event)
{
    for (auto it = m_ChessBoardCells.begin(); it != m_ChessBoardCells.end(); it++)
    {
        it->handleEvent(event);
    }
}

ChessBoardCell &ChessBoard::getActiveCell()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*m_Window);

    for (int i = 0; i < 64; i++)
    {
        if (m_ChessBoardCells[i].contains(mousePos))
        {
            return m_ChessBoardCells[i];
        }
    }

    return m_ChessBoardCells[0];
}

ChessBoardCell &ChessBoard::getSelectedCell()
{
    for (int i = 0; i < 64; i++)
    {
        if (m_ChessBoardCells[i].isSelected())
        {
            return m_ChessBoardCells[i];
        }
    }

    return m_ChessBoardCells[0];
}