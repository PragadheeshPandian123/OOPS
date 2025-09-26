#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 15;

struct Point {
    int x, y;
    Point(int a=0, int b=0): x(a), y(b) {}
    bool operator==(const Point &p) const {
        return (x==p.x && y==p.y);
    }
};

class Snake {
    vector<Point> body;
    char dir;
public:
    Snake() {
        body.push_back(Point(WIDTH/2, HEIGHT/2));
        dir = 'R';
    }
    Point getHead() { return body[0]; }
    vector<Point>& getBody() { return body; }
    void changeDirection(char d) {
        if((dir=='U' && d=='D') || (dir=='D' && d=='U') ||
           (dir=='L' && d=='R') || (dir=='R' && d=='L'))
            return;
        dir = d;
    }
    void move(bool grow) {
        Point head = body[0];
        if(dir=='U') head.y--;
        else if(dir=='D') head.y++;
        else if(dir=='L') head.x--;
        else if(dir=='R') head.x++;
        body.insert(body.begin(), head);
        if(!grow) body.pop_back();
    }
    bool collideWithSelf() {
        for(size_t i=1;i<body.size();i++)
            if(body[i]==body[0]) return true;
        return false;
    }
};

class Food {
    Point pos;
public:
    Food() { generate(); }
    void generate() {
        pos.x = (rand() % (WIDTH-2)) + 1;
        pos.y = (rand() % (HEIGHT-2)) + 1;
    }
    Point getPos() { return pos; }
};

class Board {
public:
    void draw(Snake &snake, Food &food, int score) {
        system("cls"); // clear screen (Windows)
        for(int y=0;y<HEIGHT;y++) {
            for(int x=0;x<WIDTH;x++) {
                Point p(x,y);
                if(y==0 || y==HEIGHT-1 || x==0 || x==WIDTH-1) {
                    cout << "#";
                } else if(p == snake.getHead()) {
                    cout << "O";
                } else if(p == food.getPos()) {
                    cout << "*";
                } else {
                    bool isBody=false;
                    for(auto &b: snake.getBody())
                        if(p==b) { isBody=true; break; }
                    cout << (isBody ? "o" : " ");
                }
            }
            cout << "\n";
        }
        cout << "Score: " << score << endl;
    }
};

class Game {
    Snake snake;
    Food food;
    Board board;
    bool gameOver;
    int score;
    int speed;
public:
    Game() {
        srand(time(0));
        gameOver=false;
        score=0;
        speed=200; // initial delay (ms) -> higher = slower
    }
    void run() {
        while(!gameOver) {
            board.draw(snake, food, score);
            if(_kbhit()) {
                char ch=_getch();
                if(ch=='w' || ch=='W') snake.changeDirection('U');
                else if(ch=='s' || ch=='S') snake.changeDirection('D');
                else if(ch=='a' || ch=='A') snake.changeDirection('L');
                else if(ch=='d' || ch=='D') snake.changeDirection('R');
                else if(ch=='x' || ch=='X') gameOver=true;
            }
            bool grow=false;
            if(snake.getHead()==food.getPos()) {
                grow=true;
                score+=10;
                food.generate();
                if(speed>50) speed-=10; // speed up as score increases
            }
            snake.move(grow);
            Point head=snake.getHead();
            if(head.x==0 || head.x==WIDTH-1 || head.y==0 || head.y==HEIGHT-1 
               || snake.collideWithSelf())
                gameOver=true;

            Sleep(speed); // control speed
        }
        system("cls");
        cout << "Game Over! Final Score = " << score << endl;
    }
};

int main() {
    Game g;
    g.run();
    return 0;
}
