#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MANUAL "\
----------------manual------------------\n\
Choose a number.\n\
(1) Calculate how many days are included between two given dates.\n\
(2) Show the day of the week for the given date.\n\
(3) Show the calendar of the date.\n\
(4) Change the date.\n\
(5) Quit.\n"

enum e_days
{
	MON,
	TUES,
	WEDS,
	THURS,
	FRI,
	SAT,
	SUN
};

char	*days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
char	*months[12] = {"January", "February", "March", "April", "May", "June", \
						"July", "August", "September", "October", "November", "December"};
int		days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int today_date[3] = {2022, 11, 29};
int today_day = TUES;

void	get_date(int d1[3])
{
	printf("Enter year: ");
	scanf("%d", &d1[0]);
	printf("Enter month: ");
	scanf("%d", &d1[1]);
	printf("Enter day: ");
	scanf("%d", &d1[2]);
}

int	get_date_diff(int d1[3], int d2[3])
{
	int	res;

	res = (d2[0] - d1[0]) * 365;
	res += (d2[0] - 1) / 4 - (d2[0] - 1) / 100 + (d2[0] - 1) / 400;
	res -= (d1[0] - 1) / 4 - (d1[0] - 1) / 100 + (d1[0] - 1) / 400;
	for (int i = 0 ; i < 12 ; i++)
	{
		if (i < d2[1] - 1)
			res += days_per_month[i] + (i == 1 && !(d2[0] % 4) && ((d2[0] % 100) || !(d2[0] % 400)));
		if (i < d1[1] - 1)
			res -= days_per_month[i] + (i == 1 && !(d1[0] % 4) && ((d1[0] % 100) || !(d1[0] % 400)));
	}
	res += (d2[2] - d1[2]);
	if (res < 0)
		res *= -1;
	return (res);
}

int	get_day_of_week(int d1[3])
{
	int	diff;

	diff = get_date_diff(d1, today_date);
	if (d1[0] > today_date[0] || \
		((d1[0] == today_date[0]) && (d1[1] > today_date[1])) || \
		((d1[0] == today_date[0]) && (d1[1] == today_date[1]) && (d1[2] > today_date[2])))
		return ((today_day + diff) % 7);
	else
		return ((today_day - (diff) % 7 + 7) % 7);

}

void	print_calendar(int d1[3])
{
	int	starting_day;
	int	days_in_month;

	starting_day = get_day_of_week((int[3]){d1[0], d1[1], 1});
	days_in_month = get_date_diff(\
	(int[3]){d1[0], d1[1], 1}, (int[3]){d1[0] + (d1[1] == 12), (d1[1] == 12) + (d1[1] + 1) % 13, 1});
	printf("-------%s %d-------\n", months[d1[1] - 1], d1[0]);
	printf("Mo  Tu  We  Th  Fr  Sa  Su\n");
	for (int i = 0 ; i < starting_day ; i++)
		printf("    ");
	for (int i = 1 ; i <= days_in_month ; i++)
	{
		printf("%-4d", i);
		if (!((i + starting_day) % 7))
			printf("\n");
	}
	printf("\n---------------------------\n");
}

int main(void)
{
	int	d1[3], d2[3], n, res;

	get_date(d1);
	while (1)
	{
		printf("%s", MANUAL);
		scanf("%d", &n);
		switch(n)
		{
			case 5 :
				printf("bye...\n");
				return (0);
			case 4 :
				get_date(d1);
				break ;
			case 3 :
				print_calendar(d1);
				break ;
			case 2 :
				res = get_day_of_week(d1);
				printf("%d-%d-%d is %s\n", d1[0], d1[1], d1[2], days[res]);
				break ;
			case 1 :
				get_date(d2);
				res = get_date_diff(d1, d2);
				printf("\ndifference between %d-%d-%d and %d-%d-%d : %d\n", \
				d1[0], d1[1], d1[2], d2[0], d2[1], d2[2], res);
				break ;
			default :
				printf("error...\n");
		}
	}
}