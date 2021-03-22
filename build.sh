if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        premake5_os="linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
        premake5_os="mac"
elif [[ "$OSTYPE" == "cygwin" ]]; then
        premake5_os="linux"
elif [[ "$OSTYPE" == "win32" ]]; then
        error "windows not yet supported"
elif [[ "$OSTYPE" == "freebsd"* ]]; then
        error "not recognized"
fi
./vendor/premake/premake5-${premake5_os} gmake2 && make