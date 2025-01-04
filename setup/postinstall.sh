#!/usr/bin/env bash

# necessary pkgs
sudo xbps-install -S $(cat ./voidpkgs.txt)

# daemons
sudo ln -s /etc/sv/dbus /var/service/
sudo ln -s /etc/sv/elogind /var/service
sudo ln -s /etc/sv/polkitd /var/service

# touchpad
sudo mkdir -p /etc/X11/xorg.conf.d/
sudo cp 30-touchpad.conf /etc/X11/xorg.conf.d/

# pipewire
sudo mkdir -p /etc/pipewire/pipewire.conf.d
sudo mkdir -p /etc/alsa/conf.d

sudo ln -s /usr/share/examples/wireplumber/10-wireplumber.conf /etc/pipewire/pipewire.conf.d
sudo ln -s /usr/share/examples/pipewire/20-pipewire-pulse.conf /etc/pipewire/pipewire.conf.d
sudo ln -s /usr/share/alsa/alsa.conf.d/50-pipewire.conf /etc/alsa/conf.d
sudo ln -s /usr/share/alsa/alsa.conf.d/99-pipewire-default.conf /etc/alsa/conf.d

# .config, .themes, .icons, .xinitrc, scripts, feh-bgs and zsh files
cp -rf ./home-dir/. /home/petrus/

# zsh and p10k
mkdir -p /home/petrus/.oh-my-zsh/custom/themes
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git /home/petrus/.oh-my-zsh/custom/themes/powerlevel10k
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
