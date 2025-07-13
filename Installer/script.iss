[Setup]
AppPublisher=damyan94
AppPublisherURL=https://github.com/damyan94/SDL2_Engine_Project
AppSupportURL=https://github.com/damyan94/SDL2_Engine_Project
AppName=Application
AppVersion=1.0
DefaultDirName={commonpf}\Application
OutputDir=output
OutputBaseFilename=Installer
Compression=lzma
SolidCompression=yes
LicenseFile=..\LICENSE.md

[Files]
Source: "..\_Distribution\Windows\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Run]
Filename: "{tmp}\VC_redist.x64.exe"; Parameters: "/install /quiet /norestart"; StatusMsg: "Installing ..."; Check: NeedsVCredist

[Code]
function NeedsVCredist(): Boolean;
begin
  Result := not RegKeyExists(HKLM, 'SOFTWARE\Microsoft\VisualStudio\14.0\VC\Runtimes\x64');
end;