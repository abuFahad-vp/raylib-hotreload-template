
echo "compiling plug.so..."
gcc -shared -fPIC -o libplug.so plug.c
echo "done compiling plug"

if [[ $1 = main  ]]
then
    echo "compiling main...."
    gcc -o main main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -ldl
    echo "done compiling main"
fi

if [[ $1 = web ]]
then
    echo "compiling for web..."
	emcc -o game.html main.c -Os -Wall /home/abu/raylib/src/libraylib.a -s USE_GLFW=3 -s ASYNCIFY --shell-file shell.html -DPLATFORM_WEB
fi

if [[ $2 = run ]]
then
    echo "running main.."
    ./main
fi
