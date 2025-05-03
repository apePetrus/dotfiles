if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

export ZSH="$HOME/.oh-my-zsh"
ZSH_THEME="powerlevel10k/powerlevel10k"

ENABLE_CORRECTION="true"

plugins=(
  git
  zsh-autosuggestions
  tmux
)

[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh
source $ZSH/oh-my-zsh.sh
source ~/.zsh/catppuccin_mocha-zsh-syntax-highlighting.zsh
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

export PATH=$PATH:/home/petrus/.local/bin/
export EDITOR='nvim'
export TERM='xterm-256color'
export BROWSER='librewolf'

alias py='python3'
alias code='code-oss'
alias sv-mods='cd "/home/petrus/.steam/steam/steamapps/common/Stardew Valley/Mods"'
alias td='tmux detach'
alias yt='youtube-viewer'

alias updt='sudo xbps-install -Su'
alias xis='sudo xbps-install -S'
alias xs='xbps-src'

alias xq='xbps-query -Rs'
alias xql='xbps-query -l'

alias xr='sudo xbps-remove'
alias xrr='sudo xbps-remove -R'
alias xro='sudo xbps-remove -Ooy'
