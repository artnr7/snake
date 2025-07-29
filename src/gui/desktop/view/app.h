/*------------------→ MISC ←---------------- */
#define INDENT_Y 10
#define INDENT_X 10

#define MULT 40

#define FRAME_DISTANCE 5

/*------------------→ GAMEFIELD ←---------------- */
#define GAMEFIELD_Y INDENT_Y
#define GAMEFIELD_X INDENT_X
#define GAMEFIELD_H (20 * MULT)
#define GAMEFIELD_W (10 * MULT)


/*------------------→ INFO FIELD ←---------------- */
#define INFO_Y INDENT_Y
#define INFO_X (INDENT_X + GAMEFIELD_W + FRAME_DISTANCE)
#define INFO_H GAMEFIELD_H
#define INFO_W (GAMEFIELD_W / 2)

/*------------------→ APP SIZE ←---------------- */
#define APP_H (INDENT_Y + GAMEFIELD_H + INDENT_Y)
#define APP_W (INDENT_X + GAMEFIELD_W + FRAME_DISTANCE + INFO_W + INDENT_X)