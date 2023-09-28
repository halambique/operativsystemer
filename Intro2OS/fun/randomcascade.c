#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize ncurses mode
    initscr();

    // Disable echoing of typed characters
    noecho();

    // Hide the cursor
    curs_set(FALSE);

    // Get the dimensions of the terminal window
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop to move the text around
    for (int i = 0; i < 50; ++i) {
        // Generate pseudorandom x and y coordinates within the terminal window
        int x = rand() % max_x;
        int y = rand() % max_y;

        // Move to the calculated coordinates and print the text
        mvprintw(y, x, "Catch me if you can!");

        // Update the terminal screen
        refresh();

        // Sleep for n microseconds
        usleep(1000000);

        // Clear the screen for the next iteration
        clear();
    }

    // Wait for a key press
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
