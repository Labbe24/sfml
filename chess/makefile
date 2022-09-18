# https://en.sfml-dev.org/forums/index.php?topic=9037.0

LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX := g++ -std=c++11

all: app

%.o: %.cpp
		$(CXX) -c $< -o $@

%.o: %.hpp
		$(CXX) -c $< -o $@

app: main.o whitepawn.o blackpawn.o chesspiece.o chessboard.o chessboardcell.o 
		@echo "** Building the app"
		$(CXX) -o app main.o whitepawn.o blackpawn.o chesspiece.o  chessboard.o chessboardcell.o $(LIBS)

clean:
		@echo "** Removing object files and executable..."
		rm -f app *.o

install:
		@echo '** Installing...'
		cp app /usr/bin/

uninstall:
		@echo '** Uninstalling...'
		$(RM) /usr/bin/app
