#include<iostream>
#include <conio.h>
#include<vector>
#include<chrono>
#include<thread>
#include<random>

using std::cout;
using std::endl;

enum class Direction { STOP, LEFT, RIGHT, UP, DOWN };

struct Point {
    int x, y;
};

class Game {
private:
    bool gameOver;
    int width, height, score;
    std::vector<Point> tail;
    Point fruit, head;
    Direction dir;

public:
    Game(int width, int height) : width(width), height(height), gameOver(false), score(0), dir(Direction::STOP) {
        resetGame();
    }

    void resetGame() {
        gameOver = false;
        dir = Direction::STOP;
        head.x = width / 2;
        head.y = height / 2;
        generateFruit();
        score = 0;
        tail.clear();
    }

    void generateFruit() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, width - 1);

        fruit.x = dis(gen);
        fruit.y = dis(gen);
    }

    void draw() {
        system("cls");

        for (int i = 0; i < width + 2; ++i) cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "#";

                if (i == head.y && j == head.x) cout << "0";
                else if (i == fruit.y && j == fruit.x) cout << "&";
                else {
                    bool print = false;
                    for (auto t : tail) {
                        if (t.x == j && t.y == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }

                if (j == width - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; ++i) cout << "#";
        cout << endl;
        cout << "Score: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                dir = Direction::LEFT;
                break;
            case 'd':
                dir = Direction::RIGHT;
                break;
            case 'w':
                dir = Direction::UP;
                break;
            case 's':
                dir = Direction::DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            default:
                break;
            }
        }
    }

    void logic() {
        Point prev = { head.x, head.y };
        if (tail.size() > 0) {
            tail.insert(tail.begin(), { head.x, head.y });
            tail.pop_back();
        }

        switch (dir) {
        case Direction::LEFT:
            head.x--;
            break;
        case Direction::RIGHT:
            head.x++;
            break;
        case Direction::UP:
            head.y--;
            break;
        case Direction::DOWN:
            head.y++;
            break;
        default:
            break;
        }

        if (head.x >= width || head.x < 0 || head.y >= height || head.y < 0) gameOver = true;

        for (auto t : tail) {
            if (t.x == head.x && t.y == head.y) gameOver = true;
        }

        if (head.x == fruit.x && head.y == fruit.y) {
            score += 10;
            generateFruit();
            tail.push_back({ prev.x, prev.y });
        }
    }

    bool isGameOver() {
        return gameOver;
    }
};

int main() {
    Game game(20, 20);
    char inputChar;
    while (!game.isGameOver())
    {
        game.draw();
        game.input();
        game.logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    cout << "You lost" << endl;
    system("pause");
    return 0;
}
