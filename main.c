#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

#define COMMAND_SIZE 5
#define FOOD_SIZE 10
#define MAX_LENGTH 10

enum Direction {
    LEFT,
    DOWN,
    RIGHT,
    UP
};

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW
};

struct Point {
    int x;
    int y;
};

struct Snake {
    struct Point head;
    struct Point body[MAX_LENGTH - 1];
};

struct Food {
    struct Point food[FOOD_SIZE];
    int index;
};

void printMenu();
void print snake(struct Snake* snake);
void printFood(struct Food* food, int index);
struct Snake* createSnake();
void setRandomFood(struct Food* food);
void updateSnake(struct Snake* snake, int direction);
void moveSnake(struct Snake* snake);
void checkCollision(struct Snake* snake);
void drawBackground();
void drawSnake(struct Snake* snake);
void drawFood(struct Food* food);
void drawLine(int x1, int y1, int x2, int y2, enum Color color);
void delay(int ms);
int convertKey(int key);
int main() {
    struct Snake* snake;
    struct Food* food;
    enum Color color;
    int direction, i, j, x, y;

    printMenu();
    snake = createSnake();
    food = (struct Food*)malloc(sizeof(struct Food));
    setRandomFood(food);
    color = RED;
    direction = RIGHT;

    do {
        printBackground();
        printSnake(snake);
        printFood(food, food->index);
        drawBackground();
        drawSnake(snake);
        drawFood(food);
        drawLine(0, 150, 200, 150, color);
        delay(50);
        updateSnake(snake, direction);
        if (checkCollision(snake)) {
            free(snake);
            snake = createSnake();
            setRandomFood(food);
        } else {
            food->index = (food->index + 1) % FOOD_SIZE;
            if (food->index == 0) {
                setRandomFood(food);
            }
        }
    } while (1```c
);

    return 0;
}

void#include <stdio.h>
#include <stdlib printMenu() {
    printf("1. Create a new snake\n");
   .h>
#include <time.h>

#define printf("2. Play again\n");
 LEFT 0
#define DOWN 1    printf("3. Exit game\n
#define RIGHT 2
#define UP");
    printf("Please select an option 3

#defineSnakeLength 1: ");
}

void printSnake(struct Snake0
#define FoodX 20* snake) {
    int i,
#define FoodY 20
 j;
    for (i = #define CellSize 10
#define0, j = 0; i CellNumberX 5
#define Cell < snake->body.length; i++,NumberY 5
#define MaxBody j += 3) {
        printfCount 15
#define Score ("%3d %3d | ",0.01

enum Direction
 snake->body.body[i].x,{
    LEFT,
    DOWN,
    snake->body.body[i].y);
 RIGHT,
    UP
};

typedef struct        if (j == 29
{
    int x;
    int) {
            printf("\n");
        y;
}Point;

typedef struct
 }
    }
}

void printFood(struct{
    Point head;
    Point body Food* food, int index) {
[SnakeLength];
}Snake;

void InitializeSnake(Snake *snake);
    printf("Food: %3dvoid InitializeFood(Point *food);
int %3d | ", food->food IsInCell(int x, int y[index].x, food->food[index);
void MoveSnake(Snake *].y);
}

void createSnake() {
    struct Snake snake;

    snakesnake, enum Direction direction);
void Draw.head.x = 100;
Background();
void DrawSnake(Snake    snake.head.y = 10 snake);
void DrawFood(Point food);
0;
    snake.body.length = 0;

    return &snake;
}

void UpdateSnake();
void UpdateScore(floatvoid setRandomFood(struct Food* food score);
void KeyHandler(bool isKeyDown, enum Direction *direction);

int main) {
    int index;

    do()
{
    enum Direction direction;
    {
        index = rand() % FOOD_SIZE;
    } while (index == Snake snake;
    Point food;
    food->index);

    food->index = index;
}

void updateSnake(struct float score;
    bool isGameOn Snake* snake, int direction) {
    struct Point head;
    head.x;

    InitializeFood(&food);
    = snake->head.x + (direction == LEFT ? -10 : direction InitializeSnake(&snake);
    score = == DOWN ? 0 : direction == 0;
    isGameOn = true;

    while (isGameOn RIGHT ? 10 : 0)
    {
        DrawBackground();

        DrawSnake(snake);
        DrawFood);
    head.y = snake->head(food);

        UpdateSnake();

        Update.y + (direction == UP ? -Score(score);

        scanf("%c",10 : direction == DOWN ?  &direction);

        KeyHandler(isKeyDown0 : direction == RIGHT ? 1, &direction);

        if (is0 : 0);

    if (KeyDown == false)
        {
            ishead.x >= 0 && head.xGameOn = false;
        }
    <= 200 && head.y }

    return 0;
}

void InitializeSnake(Snake *snake)
 >= 0 && head.y <= {
    snake->head.x = CellNumberX / 2 * CellSize200) {
        for (;
    snake->head.y = CellNumberY / 2 * CellSizei = 0; i < snake;
    snake->body[0]->body.length; i++) {
            if (snake->body.body[i]. = snake->head;

    for (x == head.x && snake->body.body[i].y == head.y)int i = 1; i < {
                snake->body.body[i] SnakeLength; i++)
    {
        = head;
                snake->body.length snake->body[i].x = snake++;
                return;
            }
        }
->body[i - 1].x    }

    snake->head = head;
        snake->body[i].y = snake->body[i - 1;
}

void moveSnake(struct Snake*].y + CellSize;
    }
 snake) {
    int direction;

   }

void InitializeFood(Point *food)
 do {
        direction = convertKey(get{
    food->x = FoodXchar());
        if (direction == LEFT) {
            snake->head.x -=;
    food->y = FoodY 10;
        } else if;
}

int IsInCell(int x (direction == DOWN) {
            snake->head.y += 10;
, int y)
{
    if (        } else if (direction == RIGHTx >= 0 && x < Cell) {
            snake->head.x +=NumberX * CellSize && y >= 0 && y < CellNumberY 10;
        } else if * CellSize)
    {
        return (direction == UP) {
            snake 1;
    }

    return ->head.y -= 10;
0;
}

void MoveSnake(Sn        }
    } while (snake->ake *snake, enum Direction direction)
body.body[0].x != snake{
    Point *temp;

    switch->head.x && snake->body.body[0].y != snake->head (direction)
    {
        case LEFT.y);
}

void checkCollision(struct Snake:
            if (snake->body[* snake) {
    int i;

0].x > 0)
            {
                temp = &snake->body    if (snake->head.x <[0];
                snake->body[ 0 || snake->head.x >0].x--;
                temp->x = snake->body[1].x 200 || snake->head;
                temp->x--;
            }
.y < 0 || snake->head            break;

        case DOWN:
           .y > 200) {
        return 1;
    }

    if (snake->body[0]. for (i = 1; iy + CellSize < CellNumberY < snake->body.length; i++) {
        if (snake->body.body * CellSize)
            {
                temp[i].x == snake->body.body = &snake->body[0];
[0].x && snake->body                snake->body[0].y += CellSize;
                temp->y.body[i].y == snake->body += CellSize;
            }
            break.body[0].y) {
           ;

        case RIGHT:
            if ( return 1;
        }
    }
snake->body[0].x <}

void drawBackground() {
    drawLine(0, 0,  CellNumberX * CellSize)
           200, 0, RED {
                temp = &snake->body);
    drawLine(0, 0, 0, 20[0];
                snake->body[0, RED);
    drawLine(0].x++;
                temp->x++;
            }
            break;

        case0, 150,  UP:
            if (snake->body200, 150[0].y > 0)
, GREEN);
    drawLine(2            {
                temp = &snake->00, 0, 2body[0];
                snake->body00, 150,[0].y -= CellSize;
 BLUE);
    drawLine(0,                temp->y -= CellSize;
 150, 100, 150, YELLOW            }
            break;
    }
}

);
    drawLine(100void DrawBackground()
{
    for (int i = 0; i <, 150, 2 CellNumberX * CellSize; i00, 150, += CellSize)
    {
        printf YELLOW);
}

void drawSnake(struct Snake("\n");
        for (int j* snake) {
    int i;

 = 0; j < CellNumber    for (i = 0;Y * CellSize; j += Cell i < snake->body.length; iSize)
        {
            if (i++) {
        drawLine(snake->body.body[i].x, snake-> == CellNumberX / 2 *body.body[i].y, snake-> CellSize * CellSize && j ==body.body[i].x, snake->body.body[i].y + 1 CellNumberY / 2 * Cell0, BLACK);
        drawLine(snSize * CellSize)
            {
               ake->body.body[i].x, printf("O");
            }
            else snake->body.body[i].y +
            {
                printf(" ");
            10, snake->body.body }
        }
    }
}

void Draw[i].x + 10,Snake(Snake snake)
{
    snake->body.body[i].y + 10, BLACK);
    }
 for (int i = 0; i < SnakeLength; i++)
   }

void drawFood(struct Food* food {
        if (i == SnakeLength) {
    drawLine(food->food - 1)
        {
            printf[food->index].x, food("\n");
            printf("%3d", snake.body[i].x / Cell->food[food->index].ySize);
            printf("%3d",, food->food[food->index snake.body[i].y);
        }
].x, food->food[food        else
        {
            printf("%->index].y + 103d", snake.body[i].x, RED);
    drawLine(food-> / CellSize);
            printf("%3food[food->index].x,d", snake.body[i].y);
 food->food[food->index].            printf("\n");
        }
   y + 10, food-> }
}

void DrawFood(Point food)
food[food->index].x +{
    printf("%3d", food.x / CellSize);
    printf("% 10, food->food[3d", food.y);
    printffood->index].y + 1("\n");
}

void UpdateSnake()
0, RED);
}

void drawLine{
    enum Direction nextDirection;

   (int x1, int y1, if (snake.body[0].x int x2, int y2, enum Color color) {
    static int == food.x && snake.body[0 lastX, lastY;

    if].y == food.y)
    {
 (x1 == lastX && y        for (int i = 1; i < SnakeLength; i++)
1 == lastY) {
        return        {
            snake.body[i - ;
    }

    switch (color)1] = snake.body[i];
        {
        case RED:
            printf("\ }

        score += Score;
        Initializex1b[41m");
Food(&food);
    }

    do            break;
        case GREEN:
           
    {
        nextDirection = direction printf("\x1b[42;
        MoveSnake(&snake, nextm");
            break;
        case BLUE:
            printf("\x1b[Direction);
    }
    while (Is44m");
            break;
       InCell(snake.body[0]. case YELLOW:
            printf("\x1x, snake.body[0].yb[43m");
            break) == 0);

    if (;
    }

    for (x =nextDirection == LEFT)
    {
        min(x1, x2); x snake.body[0].x--;
    <= max(x1, x2); }
    else if (nextDirection == x++) {
        printf("%c", DOWN)
    {
        snake.body[ x == x1 ? '|' : '-0].y += CellSize;
   ');
    }

    switch (color) {
        case RED:
            printf("\ }
    else if (nextDirection == RIGHT)
    {
        snake.body[x1b[0m");
           0].x++;
    }
    else break;
        case GREEN:
            printf if (nextDirection == UP)
   ("\x1b[0m");
 {
        snake.body[0].y -= CellSize;
    }

    for            break;
        case BLUE:
            (int i = 1; i printf("\x1b[0m");
            break;
        case YELLOW:
 < SnakeLength; i++)
    {
        if (IsInCell(snake            printf("\x1b[0m");
            break;
    }

   .body[i].x, snake.body[i lastX = x1;
    last].y) == 1)
       Y = y1;
}

void delay {
            printf("游戏结束！\(int ms) {
    srandom(timen");
            isGameOn = false;
        }
    }
}

void Update(NULL));
    sleep(random() % msScore(float score)
{
    printf(" + 1);
}

int convertKeyScore: %3.2f",(int key) {
    int direction;

 score);
}

void KeyHandler(bool is    switch (key) {
        caseKeyDown, enum Direction *direction)
{
 'a':
            direction = LEFT;
    int code;

    if (is            break;
        case 'd':
            direction = RIGHT;
            break;
KeyDown == true)
    {
        switch        case 'w':
            direction = (code = getchar())
        {
            UP;
            break;
        case ' case 'q':
            case 'Qs':
            direction = DOWN;
           ':
                isGameOn = false;
 break;
        default:
            direction =                break;

            case 'a':
            case 'A':
                *direction LEFT;
            break;
    }

    return direction;
}
``` = LEFT;
                break;

            case# include <stdlib.h>

int main() {
    // 创建蛇和食物
    struct Snake snake;
    struct Food *food;
    int direction, x, y;

    // 初始化蛇的位置
    snake.head.x = 100;
    snake.head.y = 100;
    snake.body.length = 0;

    // 创建食物
    food = createFood();

    // 设置蛇的初始方向
    direction = RIGHT;

    // 游戏循环
    while (1) {
        // 更新蛇的位置
        updateSnake(&snake, direction);

        // 判断蛇是否吃到食物
        if (snake.head.x == food->x && snake.head.y == food->y) {
            // 吃到食物，增加蛇的长度并生成新的食物
            snake.body.length++;
            food = createFood();
        } else {
            // 撞到墙壁或自己的身体，游戏结束
            if (snake.head.x < 0 || snake.head.x > 200 || snake.head.y < 0 || snake.head.y > 200) {
                break;
            } else {
                for (y = 0; y < snake.body.length; y++) {
                    if (snake.body.body[y].x == snake.head.x && snake.body.body[y].y == snake.head.y) {
                        break;
                    }
                }
                if (y == snake.body.length) {
                    break;
                }
            }
        }

        // 判断是否需要刷新屏幕
        if (snake.body.length % 10 == 0) {
            drawBackground();
        }

        // 等待一段时间使得游戏速度变慢
        delay(50);
    }

    return 0;
}