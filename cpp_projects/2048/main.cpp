#include "cppgraphics.hpp"

#include <array>

using Grid = std::array<std::array<int, 4>, 4>;

Grid new_grid()
{
    Grid grid;
    for (int x=0; x<4; ++x)
        for (int y=0; y<4; ++y)
            grid[x][y] = 0;
    return grid;
}


void new_number(Grid& grid)
{
    while (true) {
        int x = cg::random_int(3);
        int y = cg::random_int(3);
        if (grid[x][y] == 0) {
            grid[x][y] = 2;
            return;
        }
    }
}

bool is_full(const Grid& grid)
{
    for (int x=0; x<4; ++x)
        for (int y=0; y<4; ++y)
            if (grid[x][y] == 0)
                return false;
    return true;
}


void draw(const Grid& grid)
{
    cg::set_color(cg::Black);
    cg::set_fill_color(cg::Orange);
    cg::set_background_color(cg::Brown);

    cg::clear();
    for (int x=0; x<4; ++x) {
        for (int y=0; y<4; ++y) {
            cg::rectangle(100 + x*150, 100 + y*150, 150, 150);
            if (grid[x][y] != 0)
                cg::text_centered(std::to_string(grid[x][y]), 175+x*150, 175+y*150, 50);
        }
    }
}


void squash_column(std::array<int, 4>& col)
{
    for (int dest=3; dest>=0; --dest) {
        int src = dest-1;
        while (src >= 0 && col[src] == 0)
            --src;
        if (src < 0)
            break;
        if (col[dest] == col[src]) {
            col[dest] = col[dest] * 2;
            col[src] = 0;
        }
        if (col[dest] == 0) {
            std::swap(col[dest], col[src]);
            ++dest;
        }
    }
}


void flip_vertically(Grid& grid)
{
    for (int x=0; x<4; ++x) {
        std::swap(grid[x][0], grid[x][3]);
        std::swap(grid[x][1], grid[x][2]);
    }
}


void flip_diagonally(Grid& grid)
{
    std::swap(grid[1][0], grid[0][1]);
    std::swap(grid[2][0], grid[0][2]);
    std::swap(grid[3][0], grid[0][3]);
    std::swap(grid[2][1], grid[1][2]);
    std::swap(grid[3][1], grid[1][3]);
    std::swap(grid[3][2], grid[2][3]);
}


void squash(Grid& grid, int key)
{
    if (key == cg::KeyLeft || key == cg::KeyRight)
        flip_diagonally(grid);
    if (key == cg::KeyUp || key == cg::KeyLeft)
        flip_vertically(grid);

    for (int x=0; x<4; ++x)
        squash_column(grid[x]);

    if (key == cg::KeyUp || key == cg::KeyLeft)
        flip_vertically(grid);
    if (key == cg::KeyLeft || key == cg::KeyRight)
        flip_diagonally(grid);
}


int main()
{
    cg::create_window("2048", 800,800);

    Grid grid = new_grid();
    new_number(grid);
    while (cg::is_window_open()) {
        new_number(grid);
        draw(grid);
        int key = cg::wait_until_keypressed();
        squash(grid, key);
        if (is_full(grid))
            break;
    }

    return 0;
}
