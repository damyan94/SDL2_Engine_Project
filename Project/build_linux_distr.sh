cd ..
copyLocation=_Distribution/Linux/

mkdir -p ./$copyLocation
mkdir -p ./$copyLocation/Assets/
mkdir -p ./$copyLocation/Config/

cp $(find ./Build/Linux_x86_64_Distribution -maxdepth 1 -type f -name "*") ./$copyLocation

cp -r ./Assets ./$copyLocation/Assets/

cp ./Config/*.cfg ./$copyLocation/Config/