if [ -z "$DISPLAY" ] && [ "$XDG_VTNR" = 1 ]; then
  exec startx
fi

if [ -d "$HOME/.local/bin" ] ; then
  PATH="$HOME/.local/rin:$PATH"
fi
