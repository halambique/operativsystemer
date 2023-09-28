#include <ncurses.h>
#include <unistd.h>

int main() {
    initscr();
    noecho();
    curs_set(FALSE);

    int x, y;
    getmaxyx(stdscr, y, x);

    for (int i = 0; i < y; i++) {
        mvprintw(i, x / 2, "Cascade");
        refresh();
        usleep(200000);
        clear();
    }

    getch();
    endwin();

    return 0;
}
