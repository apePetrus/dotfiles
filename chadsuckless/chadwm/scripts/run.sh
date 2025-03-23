#!/bin/sh

xrdb merge ~/.Xresources
xbacklight -set 10 &
# xrandr --output HDMI-A-0 --mode 1920x1080 --rate 75
feh --no-fehbg --bg-fill "$HOME/.feh-bgs/girl-and-cat-walking-through-city.jpg" &
xset r rate 200 50 &
picom &
setxkbmap br &
pipewire &
dunst &

zsh ~/.config/chadwm/scripts/bar.sh &
while type chadwm >/dev/null; do chadwm && continue || break; done
