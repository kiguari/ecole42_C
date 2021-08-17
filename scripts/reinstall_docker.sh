#!/bin/sh

brew uninstall docker

brew cleanup

brew update

brew install docker

mkdir ~/.docker && mv ~/.docker ~/goinfre/ && ln -s ~/goinfre/.docker ~/.docker