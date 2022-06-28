"""
ID: Devworm
LANG: PYTHON3
TASK: friday
"""

def check_leap_year(year):
    if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
        return True
    else:
        return False


with open('friday.in', 'r') as fin:
    data = fin.readlines()
    N = int(data[0].strip())

    day_of_week_count = [0] * 7
    month_day_count = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    start_weekday = 1
    start_month = 0

    for year in range(1900, 1900 + N):
        if check_leap_year(year):
            month_day_count[1] = 29
        else:
            month_day_count[1] = 28

        for month in month_day_count:
            for day in range(month):
                start_weekday += 1
                if start_weekday == 7:
                    start_weekday %= 7
                if day == 12:
                    day_of_week_count[start_weekday] += 1 

with open('friday.out', 'w') as fout:
    answer = [str(item) for item in day_of_week_count]
    fout.write(' '.join(answer) + '\n')
