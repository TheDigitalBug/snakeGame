
#include "snake.h"

void		reDraw(t_snake *snake)
{
	//--------<<<<<<<<<
	t_pos	*body0;
	
	int len = 0;
	while(snake->body[len])
		len++;
	
	body0 = (t_pos*)malloc(sizeof(t_pos));
	body0->x = snake->body[0]->x + snake->move.x;
	body0->y = snake->body[0]->y + snake->move.y;
	body0->head = 2;
	
	if (snake->body[0]->x <= 1 || snake->body[0]->x >= (W - 1) || snake->body[0]->y <= 1 || snake->body[0]->y >= (H - 1))
	{
		puts("border");
		exit (0);
	}

	
	// ---
//	if (snake->grid[body0->x][body0->x] != 0)
//	{
//		puts("eat yourself");
//		exit (0);
//	}
	
	

	len--;
	free(snake->body[len]);
	while(len >= 1)
	{
		snake->body[len] = snake->body[len - 1];
		snake->body[len]->head = 1;
		len--;
	}
	snake->body[0] = body0;
}
