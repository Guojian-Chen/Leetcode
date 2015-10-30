#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cash = 100;
void play(char* c, int bet){

	srand(time(NULL));
	int index = 0;
	printf("shuffling the card ...\n");
	for (int i = 0; i<5; i++) {
		int x = rand()%3;
		int y = rand()%3;
		char tmp = c[x];
		c[x] = c[y];
		c[y] = tmp;
	}
	printf("the position of Queen is : 1, 2 or 3 ?");
	scanf("%d", &index);
	index = (index-1)%3;
	if (c[index-1] == 'Q')
		cash += 3*bet;
	else
		cash -= bet;
}

int main()
{
	char c[3] = {'J', 'Q', 'K'};
	int bet;
	while (cash > 0) {
		printf("your current cash is %d\n", cash);
		printf("what is your bet $:");
		scanf("%d", &bet);

		if (bet == 0 || bet > cash)
			break;
		play(c, bet);
	}
}
