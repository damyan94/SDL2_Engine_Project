cd ..
set copyLocation=_distribution

mkdir .\%copyLocation%
mkdir .\%copyLocation%\assets
mkdir .\%copyLocation%\config

xcopy .\build\windows_x86_64_Distribution\**.exe .\%copyLocation% /s /y
xcopy .\build\windows_x86_64_Distribution\**.dll .\%copyLocation% /s .y

for /r .\dependencies %%f in (*.dll) do @copy "%%f" .\%copyLocation% /y

xcopy .\assets .\%copyLocation%\assets /s /y

xcopy .\config\**.cfg .\%copyLocation%\config /s /y

pause