#!/bin/bash

WEEK_DAY=$(date +'%A')

if [ $WEEK_DAY == "Monday" ]; then

###    MONDAY
  xdg-open https://meet.google.com/lookup/g6ssaapjc6?authuser=2&hs=179
  echo "Good Monday morning!"
###

fi; if [ $WEEK_DAY == "Tuesday" ]; then

###    TUESDAY
  xdg-open https://meet.google.com/lookup/g6ssaapjc6?authuser=2&hs=179
  echo "Good Tuesday morning!"
###

fi; if [ $WEEK_DAY == "Wednesday" ]; then

###    WEDNESDAY
  xdg-open https://www.abv.bg/
  xdg-open https://meet.google.com/zsk-hrnn-afd
  echo "Good Wednesday morning!"
###

fi; if [ $WEEK_DAY == "Thursday" ]; then

###    THURSDAY
  xdg-open https://classroom.google.com/u/2/h
  xdg-open https://meet.google.com/lookup/actisihc3a?authuser=2&hs=179
  echo "Good Thursday morning!"
###

fi; if [ $WEEK_DAY == "Friday" ]; then

###    FRIDAY
  xdg-open https://zoom.us/j/92406373511
  code /home/kivag/Documents/Code-Academy
  echo "Good Friday morning!"
###

fi; if [ $WEEK_DAY == "Saturday" ]; then

###    SATURDAY
  echo "Good Saturday morning!"
###

fi; if [ $WEEK_DAY == "Sunday" ]; then

###    SUNDAY
  xdg-open https://zoom.us/j/92431178405
  code /home/kivag/Documents/Code-Academy
  echo "Good Sunday morning!"
###

fi
