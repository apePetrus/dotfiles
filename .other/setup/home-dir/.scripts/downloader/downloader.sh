#!/usr/bin/env bash
#Website file downloader

wget="wget"
echo "enter website page url: "\n
$url
read url

case wget in
"a")
  echo "Using tool to download single file:"\n
  wget $url
  ;;
"b")
  echo "Nothing to open"\n
  ;;
"wget")
  echo "Using tool to download file in background:"\n
  wget -b $url
  ;;
esac

# curl URL > index.html
