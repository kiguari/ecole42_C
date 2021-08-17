#!/bin/sh

brew uninstall minikube

brew cleanup

brew update

brew install minikube

mkdir ~/.minikube && mv ~/.minikube ~/goinfre/ && ln -s ~/goinfre/.minikube ~/.minikube
