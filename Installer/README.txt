Use Inno Setup (https://jrsoftware.org/isinfo.php) to generate an installer.

Open the script.iss and compile, the result is generated in output/Installer.exe

The script does these things:
1. It copies all files and folders from _Distribution/Windows
2. If the VC redistributables are not installed, install them

TODO Maybe I should not include the VC redist executable but have it downloaded during installation?
TODO Or should I just include the required DLLs with the project?
TODO Make an installer for Linux?