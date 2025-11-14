#python3 .ci/build.py --preset CMAKE_PRESET --cxxid gcc
set -e
export SCCACHE_DIR=/home/ws/build/.sccache/
cmake --preset CMAKE_PRESET
cmake --build --preset CMAKE_PRESET -j 5
EXEC
sccache --show-stats
