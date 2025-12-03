export PS1="%{$(tput setaf 165)%}%n%{$(tput setaf 171)%}@%{$(tput setaf 213)%}%m %{$(tput setaf 219)%}%1~ %{$(tput sgr0)%}$ "

fastfetch --kitty /home/petrus/media/img/robin-cute-resize.jpg

# exports
source $ZDOTDIR/zsh_exports
export ZSH="$ZDOTDIR/oh-my-zsh"
export ZSH_CUSTOM="$ZSH/custom"

ZSH_THEME=""

plugins=(
    git
)

source $ZSH/oh-my-zsh.sh

# History
HISTSIZE=10000000
SAVEHIST=10000000
HISTFILE="${XDG_CACHE_HOME:-$HOME/.cache}/zsh/history"
setopt inc_append_history

# Aliases
source $ZDOTDIR/zsh_aliases

# Cache
_comp_optio_comp_files=($XDG_CACHE_HOME/zsh/zcompcache(Nm-20))
if (( $#_comp_files )); then
    compinit -i -C -d "$XDG_CACHE_HOME/zsh/zcompcache"
else
    compinit -i -d "$XDG_CACHE_HOME/zsh/zcompcache"
fi

# zsh plugins
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.plugin.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.plugin.zsh
source $ZDOTDIR/plugins/catppuccin_mocha-zsh-syntax-highlighting.zsh
