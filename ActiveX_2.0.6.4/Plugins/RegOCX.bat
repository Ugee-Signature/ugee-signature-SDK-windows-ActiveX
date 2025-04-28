@echo 
@echo 跳转到当前批处理文件路径
@set root=%~dp0
taskkill /im iexplore.exe -f

if "%processor_architecture%"=="x86" goto REG32  
if "%processor_architecture%"=="AMD64" goto REG64  

:REG32 
%systemroot%\system32\regsvr32.exe -u -s %systemroot%\system32\SignViewer.ocx
%systemroot%\system32\regsvr32.exe -u -s %systemroot%\system32\SignViewer_x86.ocx
del /F /S /Q %systemroot%\system32\SignViewer.ocx
del /F /S /Q %systemroot%\system32\SignViewer_x86.ocx
COPY "%root%SignViewer_x86.ocx"  %systemroot%\system32   
%systemroot%\system32\regsvr32.exe -s %systemroot%\system32\SignViewer_x86.ocx
goto exit1  

:REG64
%systemroot%\syswow64\regsvr32.exe -u -s %systemroot%\syswow64\SignViewer_x86.ocx
%systemroot%\system32\regsvr32.exe -u -s %systemroot%\system32\SignViewer_x64.ocx
%systemroot%\system32\regsvr32.exe -u -s %systemroot%\system32\SignViewer.ocx
del /F /S /Q %systemroot%\system32\SignViewer.ocx
del /F /S /Q %systemroot%\system32\SignViewer_x86.ocx
del /F /S /Q %systemroot%\system32\SignViewer_x64.ocx

COPY "%root%SignViewer_x86.ocx"  %systemroot%\syswow64   
%systemroot%\syswow64\regsvr32.exe -s %systemroot%\syswow64\SignViewer_x86.ocx
COPY "%root%SignViewer_x64.ocx"  %systemroot%\system32   
%systemroot%\system32\regsvr32.exe -s %systemroot%\system32\SignViewer_x64.ocx
goto exit1 

:exit1
@echo 注册成功
@pause

