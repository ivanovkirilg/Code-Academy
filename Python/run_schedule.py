#!/bin/python3.9

import webbrowser
import subprocess
import shlex
import os

from datetime import datetime

### Customizable:
sched_path = "schedule.txt"
week = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun', 'End']
###

def write_example_file():
  sched_file = open(sched_path, 'w')
  
  for day in week:
    sched_file.write(f"\t{day}\n")
    
    if day == week[0]:
      sched_file.write('URL: example.org\n\n')
    elif day == week[1]:
      sched_file.write('CMD: echo "Good morning!"\nURL: example.com\n\n')
    else:
      sched_file.write('\n')
  
  sched_file.close()
  print(f"Created example file {sched_path} in {os.getcwd()}.")


### Main:

try:
  sched_file = open(sched_path)
except:
  print(f"ERROR: {sched_path} was not found in {os.getcwd()}.")
  inp = input("Would you like to create an example file? [Y/n] ")
  if 'Y' in inp.upper() or inp == '':
    write_example_file()
  exit()

current_time = datetime.now()

for day in range(len(week)):
  if day != current_time.weekday():
    continue

  # read and discard other days
  line = sched_file.readline()
  while week[day] not in line:
    line = sched_file.readline()
  line = sched_file.readline()
  
  while week[day + 1] not in line:

    if 'URL:' in line:
      webbrowser.open(line[5:-1], 2)

    elif 'CMD:' in line:
      subprocess.run(shlex.split(line[5:-1]))

    elif line.isspace():
      pass

    else:
      print(f"Error in {sched_path}:\n{line}\n"+\
            f"Expected 'URL:', 'CMD:', or an empty line.")

    line = sched_file.readline()

  break

sched_file.close()