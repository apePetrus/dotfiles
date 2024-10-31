#!/usr/bin/env bash

status() {
  echo -n "Battery: $(acpi | awk '{print $4}' | sed s/,//) | $(date '+%d-%m-%Y %H:%M:%S')"
}

pipewire &

feh --no-fehbg --bg-fill "$HOME/.feh-bgs/think.jpg" &
while true; do
  NOW=$
  xsetroot -name " $(status) "
  sleep 1
done &

exec setxkbmap -option caps:swapescape &

exec dwm
