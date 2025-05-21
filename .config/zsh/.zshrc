if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

export ZSH="$ZDOTDIR/oh-my-zsh"
export ZSH_CUSTOM="$ZSH/custom"

ZSH_THEME="powerlevel10k/powerlevel10k"

plugins=(
    git
)

source $ZSH/oh-my-zsh.sh

# History
HISTSIZE=10000000
SAVEHIST=10000000
HISTFILE="${XDG_CACHE_HOME:-$HOME/.cache}/zsh/history"
setopt inc_append_history

# Paths
export PATH=$PATH:$HOME/.local/bin/
export EDITOR="nvim"
export TERM="xterm-256color"
export obsidian="$HOME/.local/share/Obsidian.AppImage"

# Aliases
source $ZDOTDIR/zsh_aliases

# Cache
_comp_optio_comp_files=($XDG_CACHE_HOME/zsh/zcompcache(Nm-20))
if (( $#_comp_files )); then
    compinit -i -C -d "$XDG_CACHE_HOME/zsh/zcompcache"
else
    compinit -i -d "$XDG_CACHE_HOME/zsh/zcompcache"
fi

# p10k
[[ ! -f $ZDOTDIR/.p10k.zsh ]] || source $ZDOTDIR/.p10k.zsh

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.plugin.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.plugin.zsh
source $ZDOTDIR/plugins/catppuccin_mocha-zsh-syntax-highlighting.zsh
