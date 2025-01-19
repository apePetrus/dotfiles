#!/usr/bin/env bash

# status() {
#   $HOME/.scripts/status.sh
# }

pipewire &

setxkbmap br &

picom &

feh --no-fehbg --bg-fill "$HOME/.feh-bgs/think.jpg" &

# while true; do
#   NOW=$
#   xsetroot -name " $(status) "
#   sleep 1
# done &

exec ~/.config/chadwm/scripts/run.sh
