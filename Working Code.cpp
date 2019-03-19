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

int main() {
    Setup();
    while (!gameover) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}

