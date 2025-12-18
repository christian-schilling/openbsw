set -e

#sudo ip link add dev vcan0 type vcan
#sudo ip link set vcan0 mtu 16
#sudo ip link set up vcan0

echo "\nBuilding...\n"
cmake --preset CMAKE_PRESET
cmake --build --preset CMAKE_PRESET -j 5 # -- -cache

EXEC
