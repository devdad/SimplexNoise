
REM GIT root for REPOSITORIES for extra drive e.g D:\source\repos\

set GITREPO=%USERPROFILE%\source\repos

REM Set the UE5 Source path name below
 
set UE5REPO=%GITREPO%\ue5

dir %UE5REPO%

REM set SimplexNoise path below using one level up from UE5REPO

set SN=%GITREPO%\ArtAndCodeSuite

REM rmdir/s %UE5REPO%\Engine\Plugins\ArtAndCodeSuite

REM rmdir/s %SN%

mkdir %SN%

mkdir %UE5REPO%\Engine\Plugins\ArtAndCodeSuite\SimplexNoise

cd %SN%

git clone https://github.com/jimshalo10/SimplexNoise.git

rem stay in Git-cmd and copy the SimplexNoise.uplugin into UE5 plugins

REM go back to original path
cd %USERPROFILE%

copy %SN%\SimplexNoise\SimplexNoise.uplugin %UE5REPO%\Engine\Plugins\ArtAndCodeSuite\SimplexNoise\SimplexNoise.uplugin 

