@echo off
for /F "delims=" %%L in ('pasteboard.exe') do (set "VAR=%%L")
%VAR%