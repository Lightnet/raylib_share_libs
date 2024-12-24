@echo off
cd build
cmake --build .
cd ..
"build/bin/Debug/raylibapp.exe"
::pause