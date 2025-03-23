#!/usr/bin/env bash

sound() {
  amixer get Master | awk -F'[][]' 'END{ print "Vol: "$2 }'
}

battery() {
  echo -n "Battery: $(acpi | awk '{print $4}' | sed s/,//)"
}

dateFunc() {
  echo -n $(date '+%d-%m-%Y %H:%M:%S')
}

echo -n " $(sound) | $(battery) | $(dateFunc) "
