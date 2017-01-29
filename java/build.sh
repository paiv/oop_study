#!/bin/sh

mkdir -p build && \
  find . -name "*.java" | xargs javac -d build && \
  java -cp build soup
