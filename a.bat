cls

@echo off

rem Limpa o projeto (mostra só o erro, se tiver)
make clean >nul
if errorlevel 1 (
    echo [ERRO] ao limpar:
    make clean 2>&1
    exit /b
)

rem Compila o projeto
make -j >nul
if errorlevel 1 (
    echo [ERRO] na compilação:
    make 2>&1
    exit /b
)

rem Executa o programa
main.exe
if errorlevel 1 (
    echo [ERRO] na execução:
    main.exe 2>&1
    exit /b
)
