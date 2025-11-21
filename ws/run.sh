#python3 .ci/build.py --preset CMAKE_PRESET --cxxid gcc
set -e
export FASTBUILD_CACHE_PATH=build/fbcache
echo "\nBuilding...\n"
cmake --preset CMAKE_PRESET -G FASTBuild
cmake --build --preset CMAKE_PRESET -j 5 -- -cache
EXEC
