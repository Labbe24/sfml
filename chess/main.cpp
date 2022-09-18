#include <SFML/Graphics.hpp>
#include <iostream>
#include "chesspiece.h"
#include "chessboardcell.h"
#include "chessboard.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // create game objects
    std::vector<ChessPiece> whitePieces;
    std::vector<ChessPiece> blackPieces;

    // chess pieces
    ChessPiece blackTower0(window, "assets/black_tower.png");
    blackTower0.setPosition(20.f, 20.f);
    ChessPiece blackKnight0(window, "assets/black_knight.png");
    blackKnight0.setPosition(120.f, 20.f);
    ChessPiece blackRunner0(window, "assets/black_runner.png");
    blackRunner0.setPosition(220.f, 20.f);
    ChessPiece blackKing(window, "assets/black_king.png");
    blackKing.setPosition(320.f, 20.f);
    ChessPiece blackQueen(window, "assets/black_queen.png");
    blackQueen.setPosition(420.f, 20.f);
    ChessPiece blackRunner1(window, "assets/black_runner.png");
    blackRunner1.setPosition(520.f, 20.f);
    ChessPiece blackKnight1(window, "assets/black_knight.png");
    blackKnight1.setPosition(620.f, 20.f);
    ChessPiece blackTower1(window, "assets/black_tower.png");
    blackTower1.setPosition(720.f, 20.f);

    ChessPiece blackPawn0(window, "assets/black_pawn.png");
    blackPawn0.setPosition(20.f, 120.f);
    ChessPiece blackPawn1(window, "assets/black_pawn.png");
    blackPawn1.setPosition(120.f, 120.f);
    ChessPiece blackPawn2(window, "assets/black_pawn.png");
    blackPawn2.setPosition(220.f, 120.f);
    ChessPiece blackPawn3(window, "assets/black_pawn.png");
    blackPawn3.setPosition(320.f, 120.f);
    ChessPiece blackPawn4(window, "assets/black_pawn.png");
    blackPawn4.setPosition(420.f, 120.f);
    ChessPiece blackPawn5(window, "assets/black_pawn.png");
    blackPawn5.setPosition(520.f, 120.f);
    ChessPiece blackPawn6(window, "assets/black_pawn.png");
    blackPawn6.setPosition(620.f, 120.f);
    ChessPiece blackPawn7(window, "assets/black_pawn.png");
    blackPawn7.setPosition(720.f, 120.f);

    blackPieces.push_back(blackKing);
    blackPieces.push_back(blackQueen);
    blackPieces.push_back(blackRunner0);
    blackPieces.push_back(blackKnight0);
    blackPieces.push_back(blackTower0);
    blackPieces.push_back(blackRunner1);
    blackPieces.push_back(blackKnight1);
    blackPieces.push_back(blackTower1);
    blackPieces.push_back(blackPawn0);
    blackPieces.push_back(blackPawn1);
    blackPieces.push_back(blackPawn2);
    blackPieces.push_back(blackPawn3);
    blackPieces.push_back(blackPawn4);
    blackPieces.push_back(blackPawn5);
    blackPieces.push_back(blackPawn6);
    blackPieces.push_back(blackPawn7);

    ChessPiece whiteTower0(window, "assets/white_tower.png");
    whiteTower0.setPosition(20.f, 720.f);
    ChessPiece whiteKnight0(window, "assets/white_knight.png");
    whiteKnight0.setPosition(120.f, 720.f);
    ChessPiece whiteRunner0(window, "assets/white_runner.png");
    whiteRunner0.setPosition(220.f, 720.f);
    ChessPiece whiteKing(window, "assets/white_king.png");
    whiteKing.setPosition(320.f, 720.f);
    ChessPiece whiteQueen(window, "assets/white_queen.png");
    whiteQueen.setPosition(420.f, 720.f);
    ChessPiece whiteRunner1(window, "assets/white_runner.png");
    whiteRunner1.setPosition(520.f, 720.f);
    ChessPiece whiteKnight1(window, "assets/white_knight.png");
    whiteKnight1.setPosition(620.f, 720.f);
    ChessPiece whiteTower1(window, "assets/white_tower.png");
    whiteTower1.setPosition(720.f, 720.f);

    ChessPiece whitePawn0(window, "assets/white_pawn.png");
    whitePawn0.setPosition(20.f, 620.f);
    ChessPiece whitePawn1(window, "assets/white_pawn.png");
    whitePawn1.setPosition(120.f, 620.f);
    ChessPiece whitePawn2(window, "assets/white_pawn.png");
    whitePawn2.setPosition(220.f, 620.f);
    ChessPiece whitePawn3(window, "assets/white_pawn.png");
    whitePawn3.setPosition(320.f, 620.f);
    ChessPiece whitePawn4(window, "assets/white_pawn.png");
    whitePawn4.setPosition(420.f, 620.f);
    ChessPiece whitePawn5(window, "assets/white_pawn.png");
    whitePawn5.setPosition(520.f, 620.f);
    ChessPiece whitePawn6(window, "assets/white_pawn.png");
    whitePawn6.setPosition(620.f, 620.f);
    ChessPiece whitePawn7(window, "assets/white_pawn.png");
    whitePawn7.setPosition(720.f, 620.f);

    whitePieces.push_back(whiteKing);
    whitePieces.push_back(whiteQueen);
    whitePieces.push_back(whiteRunner0);
    whitePieces.push_back(whiteKnight0);
    whitePieces.push_back(whiteTower0);
    whitePieces.push_back(whiteRunner1);
    whitePieces.push_back(whiteKnight1);
    whitePieces.push_back(whiteTower1);
    whitePieces.push_back(whitePawn0);
    whitePieces.push_back(whitePawn1);
    whitePieces.push_back(whitePawn2);
    whitePieces.push_back(whitePawn3);
    whitePieces.push_back(whitePawn4);
    whitePieces.push_back(whitePawn5);
    whitePieces.push_back(whitePawn6);
    whitePieces.push_back(whitePawn7);

    ChessBoard chessBoard(window);

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            chessBoard.handleEvent(event);
            ChessBoardCell *toChessCell = &chessBoard.getActiveCell();
            ChessBoardCell fromChessCell = chessBoard.getSelectedCell();

            for (auto it = blackPieces.begin(); it != blackPieces.end(); it++)
            {
                if (event.type == sf::Event::MouseButtonReleased && toChessCell->isAvailable())
                {
                    it->setToCell(*toChessCell);
                }
                else if (event.type == sf::Event::MouseButtonReleased && !toChessCell->isAvailable())
                {
                    it->setToCell(fromChessCell);
                }
                it->handleEvent(event);
            }

            for (auto it = whitePieces.begin(); it != whitePieces.end(); it++)
            {
                if (event.type == sf::Event::MouseButtonReleased && toChessCell->isAvailable())
                {
                    it->setToCell(*toChessCell);
                }
                else if (event.type == sf::Event::MouseButtonReleased && !toChessCell->isAvailable())
                {
                    it->setToCell(fromChessCell);
                }
                it->handleEvent(event);
            }

            if (event.type == sf::Event::Closed)
            {
                // end the program
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                // window(0, 0, event.size.width, event.size.height);
            }
        }

        window.clear(sf::Color::White);
        // draw chess board
        chessBoard.draw();

        // draw black chess pieces
        for (auto it = blackPieces.begin(); it != blackPieces.end(); it++)
        {
            it->draw();
        }

        // draw white chess pieces
        for (auto it = whitePieces.begin(); it != whitePieces.end(); it++)
        {
            it->draw();
        }
        window.display();
    }

    return 0;
}