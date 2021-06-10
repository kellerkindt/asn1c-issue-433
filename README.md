# Compilable example for asn1c extensible defect

See https://github.com/vlm/asn1c/issues/433

In ```proto/CMakeLists.txt``` one of the three asn1c versions can be selected for the test.

1. Run ```./build_asn1c_versions.sh```
2. Select one of the three asn1c versions in ```proto/CMakeLists.txt```
3. Run ```./build_and_run.sh```
4. Compare the hex output
```
Valid:   010100000539007b0802d693a409ad27480c01001401861a9fc000420008a8
Invalid: 010100000539007b0802d693a409ad27480c01001401861a9fc00084001150
```
5. Repeat from 2. with another asn1c version
