@echo off

::only run this if first arg is cpp
if "%1"=="cpp" goto cpp
if "%1"=="py" goto py
if "%1"=="js" goto js
echo select cpp, py, or js
goto :eof

:cpp
fut -o tests/GJGameLevelTest.cpp GJGameLevel.fu -D TEST
pushd tests
echo Compiling GJGameLevelTest.cpp...
clang++ -std=c++20 -o GJGameLevelTest.exe GJGameLevelTest.cpp
echo Running test
GJGameLevelTest.exe
popd
goto :eof

:py
fut -o tests/GJGameLevelTest.py GJGameLevel.fu -D TEST
pushd tests
echo Running GJGameLevelTest.py
python GJGameLevelTest.py
popd
goto :eof

:js
fut -o tests/GJGameLevelTest.mjs GJGameLevel.fu -D TEST
pushd tests
echo Running GJGameLevelTest.mjs
node GJGameLevelTest.mjs
popd
goto :eof