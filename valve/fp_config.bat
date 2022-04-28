pushd %~dp0
set _ROOT=%~dp0
SET PATH=%_ROOT%\qtbase\bin;%_ROOT%\gnuwin32\bin;%_ROOT%\jom;%PATH%

call %~dp0\configure.bat ^
	-recheck-all ^
	-platform win32-msvc ^
	-prefix build_win64 ^
	-opensource -confirm-license ^
	-force-debug-info ^
	-release ^
	-nomake examples ^
	-nomake tests ^
	-nomake tools ^
	-no-opengl ^
	-skip 3d ^
	-skip activeqt ^
	-skip androidextras ^
	-skip charts ^
	-skip connectivity ^
	-skip datavis3d ^
	-skip declarative ^
	-skip doc ^
	-skip gamepad ^
	-skip graphicaleffects ^
	-skip location ^
	-skip lottie ^
	-skip macextras ^
	-skip multimedia ^
	-skip networkauth ^
	-skip purchasing ^
	-skip quick3d ^
	-skip quickcontrols ^
	-skip quickcontrols2 ^
	-skip quicktimeline ^
	-skip remoteobjects ^
	-skip script ^
	-skip scxml ^
	-skip sensors ^
	-skip serialbus ^
	-skip serialport ^
	-skip speech ^
	-skip svg ^
	-skip translations ^
	-skip virtualkeyboard ^
	-skip wayland ^
	-skip webchannel ^
	-skip webengine ^
	-skip webglplugin ^
	-skip websockets ^
	-skip webview ^
	-skip winextras ^
	-skip x11extras ^
	-skip xmlpatterns ^
	-no-openssl %*

popd
