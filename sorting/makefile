# https://en.sfml-dev.org/forums/index.php?topic=9037.0

LIBS=-lsfml-graphics -lsfml-window -lsfml-system -pthread
CXX := g++ -std=c++11

all: app

%.o: %.cpp
		$(CXX) -c $< -o $@

%.o: %.hpp
		$(CXX) -c $< -o $@

app: main.o merge_sort.o bubble_sort.o sort_algo.o button.o slider.o sprite_button.o gui_component.o
		@echo "** Building the app"
		$(CXX) -o app main.o merge_sort.o bubble_sort.o sort_algo.o button.o slider.o sprite_button.o gui_component.o $(LIBS)

clean:
		@echo "** Removing object files and executable..."
		rm -f app *.o

install:
		@echo '** Installing...'
		cp app /usr/bin/

uninstall:
		@echo '** Uninstalling...'
		$(RM) /usr/bin/app