cd ..
set copyLocation=_Distribution\Windows

mkdir .\%copyLocation%
mkdir .\%copyLocation%\Assets
mkdir .\%copyLocation%\Config

xcopy .\Bin\Windows\Distribution\**.exe .\%copyLocation% /s /y
xcopy .\Bin\Windows\Distribution\**.dll .\%copyLocation% /s .y

for /r .\Dependencies %%f in (*.dll) do @copy "%%f" .\%copyLocation% /y

xcopy .\Assets .\%copyLocation%\Assets /s /y

xcopy .\Config\**.cfg .\%copyLocation%\Config /s /y

pause