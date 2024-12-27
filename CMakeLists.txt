cmake_minimum_required(VERSION 3.30)
project(<ScoreSystem> C)

set(CMAKE_C_STANDARD 23)

add_executable(ScoreSystem
  src/AppMain.c
  src/Menu.h
  src/Menu.c
  src/ScoreSystem.h
  src/ScoreSystem.c
  src/ScoreData.h
)