typedef struct node
{
  char menu;
  double sw[3];
  double td[4][3];
  double to[4];
  double transpose[3][4];
} node;

void nodeInit(node *core);
