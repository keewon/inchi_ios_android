# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             inchi

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
              ../../INCHI-1-SRC/INCHI_BASE/src/ichi_bns.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichi_io.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichican2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichicano.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichicans.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichierr.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiisot.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichimak2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichimake.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichimap1.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichimap2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichimap4.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichinorm.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiparm.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiprt1.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiprt2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiprt3.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiqueu.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiread.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichiring.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr1.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr3.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr4.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr5.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr6.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichirvr7.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichisort.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichister.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ichitaut.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ikey_base26.c
              ../../INCHI-1-SRC/INCHI_BASE/src/ikey_dll.c
              ../../INCHI-1-SRC/INCHI_BASE/src/inchi_gui.c
              ../../INCHI-1-SRC/INCHI_BASE/src/mol2atom.c
              ../../INCHI-1-SRC/INCHI_BASE/src/mol_fmt1.c
              ../../INCHI-1-SRC/INCHI_BASE/src/mol_fmt2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/mol_fmt3.c
              ../../INCHI-1-SRC/INCHI_BASE/src/mol_fmt4.c
              ../../INCHI-1-SRC/INCHI_BASE/src/readinch.c
              ../../INCHI-1-SRC/INCHI_BASE/src/runichi.c
              ../../INCHI-1-SRC/INCHI_BASE/src/runichi2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/runichi3.c
              ../../INCHI-1-SRC/INCHI_BASE/src/runichi4.c
              ../../INCHI-1-SRC/INCHI_BASE/src/sha2.c
              ../../INCHI-1-SRC/INCHI_BASE/src/strutil.c
              ../../INCHI-1-SRC/INCHI_BASE/src/util.c

              ../../INCHI-1-SRC/INCHI_API/libinchi/src/ichilnct.c
              ../../INCHI-1-SRC/INCHI_API/libinchi/src/inchi_dll_a.c
              ../../INCHI-1-SRC/INCHI_API/libinchi/src/inchi_dll_a2.c
              ../../INCHI-1-SRC/INCHI_API/libinchi/src/inchi_dll_b.c
              ../../INCHI-1-SRC/INCHI_API/libinchi/src/inchi_dll_main.c
              ../../INCHI-1-SRC/INCHI_API/libinchi/src/inchi_dll.c

             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       inchi

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
