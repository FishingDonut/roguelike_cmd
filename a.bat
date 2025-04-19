cls

@echo off

rem Limpa o projeto (mostra só o erro, se tiver)
mingw32-make clean >nul
if errorlevel 1 (
    echo [ERRO] ao limpar:
    mingw32-make clean 2>&1
    exit /b
)

rem Compila o projeto
mingw32-make >nul
if errorlevel 1 (
    echo [ERRO] na compilação:
    mingw32-make 2>&1
    exit /b
)

rem Executa o programa
main.exe
if errorlevel 1 (
    echo [ERRO] na execução:
    main.exe 2>&1
    exit /b
)
