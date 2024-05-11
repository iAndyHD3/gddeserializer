@echo off

rmdir /s /q transpiled
mkdir transpiled
pushd transpiled

mkdir cpp
mkdir java
mkdir c
mkdir ts

set file=../GJGameLevel.fu
fut -l java -o java/GJGameLevel.java %file% -n gdd
fut -l cpp -o cpp/GJGameLevel.cpp %file% -n gdd
fut -l c -o c/GJGameLevel.c %file% -n gdd
fut -l ts -o ts/GJGameLevel.ts %file% -n gdd
fut -l d.ts -o ts/GJGameLevel.d.ts %file% -n gdd

fut -l cs -o GJGameLevel.cs %file% -n gdd
fut -l d -o GJGameLevel.d %file% -n gdd
fut -l js -o GJGameLevel.mjs %file% -n gdd
fut -l swift -o GJGameLevel.swift %file% -n gdd
fut -l py -o GJGameLevel.py %file% -n gdd

::Missing List<>
::fut -l cl -o GJGameLevel.cl %file% -n gdd

popd