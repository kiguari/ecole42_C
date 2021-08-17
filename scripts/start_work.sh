#!/bin/bash
rm -rf ~/Library/Caches/
rm -rf ~/Library/*42_cache*
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage/
rm -rf ~/Library/Application\ Support/Slack/Cache/
rm -rf ~/Library/Application\ Support/Slack/Code\ Cache/
rm -rf ~/Library/Application\ Support/Code/Cache/*
rm -rf ~/Library/Application\ Support/Code/CachedData/*
rm -rf ~/Library/Application Support/Spotify/PersistentCache
rm -rf ~/Library/Application\ Support/Code/User/workspaceStorage

cd ~
rm -rf .docker
rm -rf .minikube

brew uninstall minikube
brew cleanup
brew update
brew install minikube
mkdir ~/.minikube && mv ~/.minikube ~/goinfre/ && ln -s ~/goinfre/.minikube ~/.minikube

brew uninstall docker
brew cleanup
brew update
brew install docker
mkdir ~/.docker && mv ~/.docker ~/goinfre/ && ln -s ~/goinfre/.docker ~/.docker