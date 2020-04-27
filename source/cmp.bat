@echo
:loop
rand.exe
test.exe
std.exe
fc std.out test.out
if not errorlevel 1 goto loop
pause
goto loop
