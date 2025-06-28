cd ..
copyLocation=_Distribution/Linux/

mkdir -p ./$copyLocation
mkdir -p ./$copyLocation/Assets/
mkdir -p ./$copyLocation/Config/

cp $(find ./Bin/Linux/Distribution -maxdepth 1 -type f -name "Application") ./$copyLocation

cp -r ./Assets ./$copyLocation/

cp ./Config/*.cfg ./$copyLocation/Config/
