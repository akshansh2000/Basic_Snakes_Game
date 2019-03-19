#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

bool gameover;
const int height = 25, width = 50;
int x, y, ntail, tailx[100], taily[100], fruitx, fruity, score;
enum Direction { STOP,
                 LEFT,
                 RIGHT,
                 UP,
                 DOWN };
Direction dir;

void Setup() {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
    ntail = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < width; ++i)
        cout << '#';
    cout << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j == 0 || j == width - 1)
                cout << '#';
            else if (j == x && i == y)
                cout << '0';
            else if (j == fruitx && i == fruity)
                cout << 'F';
            else {
                bool print = false;
                for (int k = 0; k < ntail; ++k) {
                    if (tailx[k] == j && taily[k] == i) {
                        cout << 'o';
                        print = true;
                    }
                }
                if (!print)
                    cout << ' ';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; ++i)
        cout << '#';
    cout << endl
         << endl;
    cout << "Your score: " << score;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir == RIGHT)
                break;
            dir = LEFT;
            break;
        case 's':
            if (dir == UP)
                break;
            dir = DOWN;
            break;
        case 'd':
            if (dir == LEFT)
                break;
            dir = RIGHT;
            break;
        case 'w':
            if (dir == DOWN)
                break;
            dir = UP;
            break;
        case 't':
            gameover = true;
            break;
        }
    }
}

void Logic() {
    int prevx = tailx[0], prevy = taily[0], prev2x, prev2y;
    tailx[0] = x, taily[0] = y;
    for (int i = 1; i < ntail; ++i) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch (dir) {
    case RIGHT:
        ++x;
        break;
    case LEFT:
        --x;
        break;
    case UP:
        --y;
        break;
    case DOWN:
        ++y;
        break;
    }
    if (x == width)
        x = -1;
    else if (x == -1)
        x = width;
    else if (y == height + 1)
        y = -1;
    else if (y == -1)
        y = height + 1;
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == x && taily[i] == y)
            gameover = true;
    if (x == fruitx && y == fruity) {
        fruitx = rand() % width;
        fruity = rand() % height;
        ++score;
        ++ntail;
    }
}

int main() {
    Setup();
    while (!gameover) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}

