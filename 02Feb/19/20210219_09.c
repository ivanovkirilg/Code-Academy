/*  Задача 9. Направете функця add(), която събира две точки. */

struct tagPoint {
    int x, y;
};

struct tagPoint add(struct tagPoint a, struct tagPoint b) {
    struct tagPoint c = { a.x + b.x, a.y + b.y };
    return c;
}