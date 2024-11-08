cd ..
set copyLocation=_Distribution\Windows

mkdir .\%copyLocation%
mkdir .\%copyLocation%\assets
mkdir .\%copyLocation%\config

xcopy .\Build\Windows_x86_64_Distribution\**.exe .\%copyLocation% /s /y
xcopy .\Build\Windows_x86_64_Distribution\**.dll .\%copyLocation% /s .y

for /r .\Dependencies %%f in (*.dll) do @copy "%%f" .\%copyLocation% /y

xcopy .\Assets .\%copyLocation%\Assets /s /y

xcopy .\Config\**.cfg .\%copyLocation%\Config /s /y

pause