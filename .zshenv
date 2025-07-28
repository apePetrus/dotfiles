export ZDOTDIR="$HOME/.config/zsh"

if [ "$(tty)" = "/dev/tty1" ];then
  exec Hyprland
fi
