@echo off
SetLocal EnableDelayedExpansion

pushd W:\Butterfly\Sandbox
set FileNames=
for /R %%f in (*.c) do (
	set FileNames=!FileNames! %%f
)

if not exist ..\Bin mkdir ..\Bin
pushd ..\Bin

set CompileFlags=-UTF8 -MTd -nologo -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4221 -wd4505 -wd4201 -wd4100 -wd4189 -wd4115 -wd4101 -wd4996 -FAsc -Z7

set Defines=-DBTF_PLATFORM_WINDOWS -DBTF_APP -DBTF_DEBUG -DUNICODE=1

set Includes=-I..\Butterfly\src

set LinkFlags=-incremental:no -opt:ref Engine.lib user32.lib

echo "Building sandbox..."
cl %CompileFlags% %Defines% %Includes% -Fe:..\Bin\Sandbox %FileNames% /link %LinkFlags%

popd
popd