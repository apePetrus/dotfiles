PS1="%B[%m@%n %1~]$%b "

# History
HISTSIZE=10000000
SAVEHIST=10000000
HISTFILE="${XDG_CACHE_HOME:-$HOME/.cache}/zsh/history"
setopt inc_append_history

export ZSH="$ZDOTDIR/oh-my-zsh"

export PATH=$PATH:$HOME/.local/bin/
export EDITOR="nvim"
export TERM="xterm-256color"
export obsidian="$HOME/.local/share/Obsidian.AppImage"

plugins=(
    git
)

source $ZSH/oh-my-zsh.sh
export ZSH_CUSTOM="$ZSH/custom"

source $ZDOTDIR/zsh_aliases

_comp_optio_comp_files=($XDG_CACHE_HOME/zsh/zcompcache(Nm-20))
if (( $#_comp_files )); then
    compinit -i -C -d "$XDG_CACHE_HOME/zsh/zcompcache"
else
    compinit -i -d "$XDG_CACHE_HOME/zsh/zcompcache"
fi

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.plugin.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.plugin.zsh
source $ZDOTDIR/plugins/catppuccin_mocha-zsh-syntax-highlighting.zsh
