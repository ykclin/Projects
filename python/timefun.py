import time
import calendar

localtime = time.localtime(time.time())
print("local time: ", localtime)

localtime = time.asctime(time.localtime(time.time()))
print("local time: ", localtime)

localtime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
print("local time: ", localtime)

cal = calendar.month(2017,7)

print("以下输出2017年7月份的日历")
print(cal)


