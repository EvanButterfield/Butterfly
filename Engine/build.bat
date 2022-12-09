@echo off
SetLocal EnableDelayedExpansion

pushd W:\Butterfly\Engine
set FileNames=
for /R %%f in (*.c) do (
	set FileNames=!FileNames! %%f
)

if not exist ..\Bin mkdir ..\Bin
pushd ..\Bin

set CompileFlags=-UTF8 -MTd -nologo -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4221 -wd4505 -wd4201 -wd4100 -wd4189 -wd4115 -wd4101 -wd4996 -FAsc -Z7

set Defines=-DBTF_PLATFORM_WINDOWS -DBTF_ENGINE -DBTF_DEBUG -DUNICODE=1

set Includes=-IButterfly

set LinkFlags=-incremental:no -opt:ref user32.lib

echo "Building engine..."
cl %CompileFlags% %Defines% -LD -Fe:..\Bin\Engine %FileNames% /link %LinkFlags%

popd
popd