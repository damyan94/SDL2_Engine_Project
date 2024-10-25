cd ..
copyLocation=_distribution/Linux/

mkdir -p ./$copyLocation
mkdir -p ./$copyLocation/assets/
mkdir -p ./$copyLocation/config/

cp $(find ./build/Linux_x86_64_Distribution -maxdepth 1 -type f -name "*") ./$copyLocation

cp -r ./assets ./$copyLocation/assets/

cp ./config/*.cfg ./$copyLocation/config/