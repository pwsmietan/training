import time
import datetime
from iterations import Days
from calendar import *

print(f"Epoch since 1970: {time.time()}")
print(f"Time Structure: {time.localtime()}")
print(f"time: ({time.time()} / 2) {time.time() / 2}")

dt = datetime.datetime.today()
print(dt)

dt1 = datetime.datetime(2010, 10, 1, 10, 20, 30)
dt2 = datetime.datetime(2011, 10, 1, 10, 20, 30)
td = dt2 - dt1
print(datetime.timedelta(days=365))
dm = divmod(td.days, 30)
print(dm)

print(f"Is 2024 leap year? {isleap(2024)}")
print(f"Leap days 2000 through 2024: {leapdays(2000, 2024)}")
