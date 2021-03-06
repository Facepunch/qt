pushd %~dp0
set _ROOT=%~dp0
SET PATH=%_ROOT%\qtbase\bin;%_ROOT%\gnuwin32\bin;%PATH%

call %~dp0\configure.bat ^
	-recheck-all ^
	-prefix build_win64 ^
	-opensource -confirm-license ^
	-force-debug-info ^
	-debug-and-release ^
	-nomake examples ^
	-nomake tests ^
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
	-ssl -openssl-linked OPENSSL_PREFIX=%~dp0\..\openssl\result_win64\ %*

popd
