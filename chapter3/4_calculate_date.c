// 주어진 두 날짜 사이에 며칠이 포함되었는지를 계산하는 함수
// 주어진 날짜가 무슨 요일인지를 리턴하는 함수
// 주어진 연도와 달에 대한 달력을 문자의 배열로 생성하는 함수

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MANUAL "\
----------------manual------------------\n\
Choose a number.\n\
(1) Calculate how many days are included between two given dates.\n\
(2) Show the day of the week for the given date.\n\
(3) Show the calender of the date.\n\
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

int date_of_today[3] = {2022, 11, 29};
int day_of_today = TUES;

void	get_date(int date[3])
{
	printf("Enter year: ");
	scanf("%d", &date[0]);
	printf("Enter month: ");
	scanf("%d", &date[1]);
	printf("Enter day: ");
	scanf("%d", &date[2]);
}

int	get_difference_between_two_dates(int date[3], int date2[3])
{
	const int	days_in_normal_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			res;

	res = (date2[0] - date[0]) * 365;
	res += (date2[0] - 1) / 4 - (date2[0] - 1) / 100 + (date2[0] - 1) / 400;
	res -= (date[0] - 1) / 4 - (date[0] - 1) / 100 + (date[0] - 1) / 400;
	for (int i = 0 ; i < 12 ; i++)
	{
		if (i < date2[1] - 1)
			res += days_in_normal_year[i] + (i == 1 && !(date2[0] % 4) && ((date2[0] % 100) || !(date2[0] % 400)));
		if (i < date[1] - 1)
			res -= days_in_normal_year[i] + (i == 1 && !(date[0] % 4) && ((date[0] % 100) || !(date[0] % 400)));
	}
	res += (date2[2] - date[2]);
	if (res < 0)
		res *= -1;
	return (res);
}

void	print_difference_between_two_dates(int date[3], int date2[3])
{
	int	diff;

	diff = get_difference_between_two_dates(date, date2);
	printf("\ndifference between %d-%d-%d and %d-%d-%d : %d\n", date[0], date[1], date[2], date2[0], date2[1], date2[2], diff);

}

void	print_day_of_week(int date[3])
{
	const char	*days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	int			diff;
	int			day_of_date;

	diff = get_difference_between_two_dates(date, date_of_today);
	if (date[0] > date_of_today[0] || \
		((date[0] == date_of_today[0]) && (date[1] > date_of_today[1])) || \
		((date[0] == date_of_today[0]) && (date[1] == date_of_today[1]) && (date[2] > date_of_today[2])))
		day_of_date = (day_of_today + diff) % 7;
	else
		day_of_date = 
	printf("%d-%d-%d is %s\n", date[0], date[1], date[2], days[day_of_date]);

}

void	print_calender(int date[3])
{

}

int main(void)
{
	int	date[3], date2[3], n;

	get_date(date);
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
				get_date(date);
				break ;
			case 3 :
				print_calender(date);
				break ;
			case 2 :
				print_day_of_week(date);
				break ;
			case 1 :
				get_date(date2);
				print_difference_between_two_dates(date, date2);
				break ;
			default :
				printf("error...\n");
		}
	}
}