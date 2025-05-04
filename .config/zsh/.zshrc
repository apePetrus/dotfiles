PS1="%B[%m@%n %1~]$%b "

# History
HISTSIZE=10000000
SAVEHIST=10000000
HISTFILE="${XDG_CACHE_HOME:-$HOME/.cache}/zsh/history"
setopt inc_append_history

export ZSH="$ZDOTDIR/oh-my-zsh"
source $ZSH/oh-my-zsh.sh

_comp_optio_comp_files=($XDG_CACHE_HOME/zsh/zcompcache(Nm-20))
if (( $#_comp_files )); then
    compinit -i -C -d "$XDG_CACHE_HOME/zsh/zcompcache"
else
    compinit -i -d "$XDG_CACHE_HOME/zsh/zcompcache"
fi

export PATH=$PATH:$HOME/.local/bin/
export EDITOR="nvim"
export TERM="xterm-256color"

alias py="python3"
alias sv-mods="cd $HOME/.steam/steam/steamapps/common/Stardew Valley/Mods"
alias yt="youtube-viewer"

alias td="tmux detach"

alias sts="git status"
alias gc="git commit -m"
alias gs="git switch"
alias gsc="git switch -c"
alias gp="git push"
alias gpf="git push -f"

alias updt="sudo xbps-install -Su"
alias xis="sudo xbps-install -S"
alias xs="xbps-src"

alias xq="xbps-query -Rs"
alias xql="xbps-query -l"

alias xr="sudo xbps-remove"
alias xrr="sudo xbps-remove -R"
alias xro="sudo xbps-remove -Ooy"

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.plugin.zsh
source $ZDOTDIR/plugins/catppuccin_mocha-zsh-syntax-highlighting.zsh
