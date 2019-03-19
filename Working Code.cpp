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

int main() {
    Setup();
    while (!gameover) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}

