#include <SFML/Graphics.hpp>
#include <iostream>
#include "chesspiece.h"
#include "chessboardcell.h"
#include "chessboard.h"
#include "whitepawn.cpp"
#include "blackpawn.cpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // create game objects
    std::vector<ChessPiece *> whitePieces;
    std::vector<ChessPiece *> blackPieces;

    // chess pieces
    ChessPiece blackTower0(window, "assets/black_tower.png", 20.f, 20.f);
    ChessPiece blackKnight0(window, "assets/black_knight.png", 120.f, 20.f);
    ChessPiece blackRunner0(window, "assets/black_runner.png", 220.f, 20.f);
    ChessPiece blackKing(window, "assets/black_king.png", 320.f, 20.f);
    ChessPiece blackQueen(window, "assets/black_queen.png", 420.f, 20.f);
    ChessPiece blackRunner1(window, "assets/black_runner.png", 520.f, 20.f);
    ChessPiece blackKnight1(window, "assets/black_knight.png", 620.f, 20.f);
    ChessPiece blackTower1(window, "assets/black_tower.png", 720.f, 20.f);

    BlackPawn blackPawn0(window, "assets/black_pawn.png", 20.f, 120.f);
    BlackPawn blackPawn1(window, "assets/black_pawn.png", 120.f, 120.f);
    BlackPawn blackPawn2(window, "assets/black_pawn.png", 220.f, 120.f);
    BlackPawn blackPawn3(window, "assets/black_pawn.png", 320.f, 120.f);
    BlackPawn blackPawn4(window, "assets/black_pawn.png", 420.f, 120.f);
    BlackPawn blackPawn5(window, "assets/black_pawn.png", 520.f, 120.f);
    BlackPawn blackPawn6(window, "assets/black_pawn.png", 620.f, 120.f);
    BlackPawn blackPawn7(window, "assets/black_pawn.png", 720.f, 120.f);

    blackPieces.push_back(&blackKing);
    blackPieces.push_back(&blackQueen);
    blackPieces.push_back(&blackRunner0);
    blackPieces.push_back(&blackKnight0);
    blackPieces.push_back(&blackTower0);
    blackPieces.push_back(&blackRunner1);
    blackPieces.push_back(&blackKnight1);
    blackPieces.push_back(&blackTower1);
    blackPieces.push_back(&blackPawn0);
    blackPieces.push_back(&blackPawn1);
    blackPieces.push_back(&blackPawn2);
    blackPieces.push_back(&blackPawn3);
    blackPieces.push_back(&blackPawn4);
    blackPieces.push_back(&blackPawn5);
    blackPieces.push_back(&blackPawn6);
    blackPieces.push_back(&blackPawn7);

    ChessPiece whiteTower0(window, "assets/white_tower.png", 20.f, 720.f);
    ChessPiece whiteKnight0(window, "assets/white_knight.png", 120.f, 720.f);
    ChessPiece whiteRunner0(window, "assets/white_runner.png", 220.f, 720.f);
    ChessPiece whiteKing(window, "assets/white_king.png", 320.f, 720.f);
    ChessPiece whiteQueen(window, "assets/white_queen.png", 420.f, 720.f);
    ChessPiece whiteRunner1(window, "assets/white_runner.png", 520.f, 720.f);
    ChessPiece whiteKnight1(window, "assets/white_knight.png", 620.f, 720.f);
    ChessPiece whiteTower1(window, "assets/white_tower.png", 720.f, 720.f);

    WhitePawn whitePawn0(window, "assets/white_pawn.png", 20.f, 620.f);
    WhitePawn whitePawn1(window, "assets/white_pawn.png", 120.f, 620.f);
    WhitePawn whitePawn2(window, "assets/white_pawn.png", 220.f, 620.f);
    WhitePawn whitePawn3(window, "assets/white_pawn.png", 320.f, 620.f);
    WhitePawn whitePawn4(window, "assets/white_pawn.png", 420.f, 620.f);
    WhitePawn whitePawn5(window, "assets/white_pawn.png", 520.f, 620.f);
    WhitePawn whitePawn6(window, "assets/white_pawn.png", 620.f, 620.f);
    WhitePawn whitePawn7(window, "assets/white_pawn.png", 720.f, 620.f);

    whitePieces.push_back(&whiteKing);
    whitePieces.push_back(&whiteQueen);
    whitePieces.push_back(&whiteRunner0);
    whitePieces.push_back(&whiteKnight0);
    whitePieces.push_back(&whiteTower0);
    whitePieces.push_back(&whiteRunner1);
    whitePieces.push_back(&whiteKnight1);
    whitePieces.push_back(&whiteTower1);
    whitePieces.push_back(&whitePawn0);
    whitePieces.push_back(&whitePawn1);
    whitePieces.push_back(&whitePawn2);
    whitePieces.push_back(&whitePawn3);
    whitePieces.push_back(&whitePawn4);
    whitePieces.push_back(&whitePawn5);
    whitePieces.push_back(&whitePawn6);
    whitePieces.push_back(&whitePawn7);

    ChessBoard chessBoard(window);
    bool whitesTurn = true;
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            chessBoard.handleEvent(event);
            ChessBoardCell *fromChessCell = &chessBoard.getSelectedCell();
            ChessBoardCell *toChessCell = &chessBoard.getActiveCell();

            if (whitesTurn)
            {

                for (auto wp : whitePieces)
                {
                    if (event.type == sf::Event::MouseButtonReleased && wp->containsMouse() && toChessCell->isAvailable() && wp->validMove(*toChessCell))
                    {
                        fromChessCell->setAvailable(true);
                        wp->setToCell(*toChessCell);
                        whitesTurn = false;
                    }
                    else if (event.type == sf::Event::MouseButtonReleased && wp->containsMouse() && (!toChessCell->isAvailable() || !wp->validMove(*toChessCell)))
                    {
                        wp->setToCell(*fromChessCell);
                    }
                    wp->handleEvent(event);
                }
            }
            else if (!whitesTurn)
            {

                for (auto bp : blackPieces)
                {
                    if (event.type == sf::Event::MouseButtonReleased && bp->containsMouse() && toChessCell->isAvailable() && bp->validMove(*toChessCell))
                    {
                        fromChessCell->setAvailable(true);
                        bp->setToCell(*toChessCell);
                        whitesTurn = true;
                    }
                    else if (event.type == sf::Event::MouseButtonReleased && bp->containsMouse() && (!toChessCell->isAvailable() || !bp->validMove(*toChessCell)))
                    {
                        bp->setToCell(*fromChessCell);
                    }
                    bp->handleEvent(event);
                }
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

        // draw white chess pieces
        for (auto wp : whitePieces)
        {
            wp->draw();
        }

        // draw black chess pieces
        for (auto bp : blackPieces)
        {
            bp->draw();
        }

        window.display();
    }

    return 0;
}