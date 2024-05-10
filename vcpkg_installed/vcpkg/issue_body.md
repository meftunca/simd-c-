Package: gperftools:arm64-osx@2.10#1

**Host Environment**

- Host: arm64-osx
- Compiler: AppleClang 15.0.0.15000309
-    vcpkg-tool version: 2024-03-14-2024.03.14
    vcpkg-scripts version: 80403036a 2024-02-02 (3 months ago)

**To Reproduce**

`vcpkg install `
**Failure logs**

```
-- Using cached gperftools-gperftools-gperftools-2.10.tar.gz.
-- Cleaning sources at /Users/mapletechnologies/vcpkg/buildtrees/gperftools/src/tools-2.10-f6f5d5bdde.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /Users/mapletechnologies/vcpkg/downloads/gperftools-gperftools-gperftools-2.10.tar.gz
-- Using source at /Users/mapletechnologies/vcpkg/buildtrees/gperftools/src/tools-2.10-f6f5d5bdde.clean
-- Found external ninja('1.12.0').
-- Getting CMake variables for arm64-osx-dbg
-- Getting CMake variables for arm64-osx-rel
-- Generating configure for arm64-osx
-- Finished generating configure for arm64-osx
-- Configuring arm64-osx-dbg
-- Configuring arm64-osx-rel
-- Building arm64-osx-dbg
CMake Error at scripts/cmake/vcpkg_execute_build_process.cmake:134 (message):
    Command failed: /usr/bin/make V=1 -j 13 -f Makefile all
    Working Directory: /Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/
    See logs for more information:
      /Users/mapletechnologies/vcpkg/buildtrees/gperftools/build-arm64-osx-dbg-out.log
      /Users/mapletechnologies/vcpkg/buildtrees/gperftools/build-arm64-osx-dbg-err.log

Call Stack (most recent call first):
  scripts/cmake/vcpkg_build_make.cmake:136 (vcpkg_execute_build_process)
  scripts/cmake/vcpkg_install_make.cmake:2 (vcpkg_build_make)
  /Users/mapletechnologies/.cache/vcpkg/registries/git-trees/ebb8ef920067346d4633cc78ee176f7ed9bc89d4/portfile.cmake:64 (vcpkg_install_make)
  scripts/ports.cmake:170 (include)



```
<details><summary>/Users/mapletechnologies/vcpkg/buildtrees/gperftools/build-arm64-osx-dbg-out.log</summary>

```
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -D_THREAD_SAFE  -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_la-tcmalloc.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_la-tcmalloc.Tpo -c -o src/libtcmalloc_minimal_la-tcmalloc.lo `test -f 'src/tcmalloc.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/tcmalloc.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-common.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-common.Tpo -c -o src/libtcmalloc_minimal_internal_la-common.lo `test -f 'src/common.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/common.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-internal_logging.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-internal_logging.Tpo -c -o src/libtcmalloc_minimal_internal_la-internal_logging.lo `test -f 'src/internal_logging.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/internal_logging.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-system-alloc.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-system-alloc.Tpo -c -o src/libtcmalloc_minimal_internal_la-system-alloc.lo `test -f 'src/system-alloc.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/system-alloc.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-memfs_malloc.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-memfs_malloc.Tpo -c -o src/libtcmalloc_minimal_internal_la-memfs_malloc.lo `test -f 'src/memfs_malloc.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/memfs_malloc.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-central_freelist.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-central_freelist.Tpo -c -o src/libtcmalloc_minimal_internal_la-central_freelist.lo `test -f 'src/central_freelist.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/central_freelist.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-page_heap.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-page_heap.Tpo -c -o src/libtcmalloc_minimal_internal_la-page_heap.lo `test -f 'src/page_heap.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/page_heap.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-sampler.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-sampler.Tpo -c -o src/libtcmalloc_minimal_internal_la-sampler.lo `test -f 'src/sampler.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/sampler.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-span.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-span.Tpo -c -o src/libtcmalloc_minimal_internal_la-span.lo `test -f 'src/span.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/span.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-stack_trace_table.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-stack_trace_table.Tpo -c -o src/libtcmalloc_minimal_internal_la-stack_trace_table.lo `test -f 'src/stack_trace_table.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/stack_trace_table.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-static_vars.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-static_vars.Tpo -c -o src/libtcmalloc_minimal_internal_la-static_vars.lo `test -f 'src/static_vars.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/static_vars.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-symbolize.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-symbolize.Tpo -c -o src/libtcmalloc_minimal_internal_la-symbolize.lo `test -f 'src/symbolize.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/symbolize.cc
/bin/sh ./libtool  --tag=CXX   --mode=compile /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src  -I./../src/tools-2.10-f6f5d5bdde.clean/src  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -MT src/libtcmalloc_minimal_internal_la-thread_cache.lo -MD -MP -MF src/.deps/libtcmalloc_minimal_internal_la-thread_cache.Tpo -c -o src/libtcmalloc_minimal_internal_la-thread_cache.lo `test -f 'src/thread_cache.cc' || echo './../src/tools-2.10-f6f5d5bdde.clean/'`src/thread_cache.cc
...
Skipped 420 lines
...
mv -f benchmark/.deps/malloc_bench-malloc_bench.Tpo benchmark/.deps/malloc_bench-malloc_bench.Po
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o getpc_test src/tests/getpc_test.o  
mv -f src/.deps/libtcmalloc_internal_la-memory_region_map.Tpo src/.deps/libtcmalloc_internal_la-memory_region_map.Plo
cat libtcmalloc.pc | sed s/-ltcmalloc/-ltcmalloc_minimal/ > "libtcmalloc_minimal.pc"
cat libtcmalloc.pc | sed s/-ltcmalloc/-ltcmalloc_debug/ > "libtcmalloc_debug.pc"
cat libtcmalloc.pc | sed s/-ltcmalloc/-ltcmalloc_minimal_debug/ > "libtcmalloc_minimal_debug.pc"
cat libtcmalloc.pc | sed s/-ltcmalloc/-lprofiler/ > "libprofiler.pc"
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o libspinlock.la  src/base/spinlock.lo src/base/spinlock_internal.lo src/base/atomicops-internals-x86.lo   
libtool: compile:  /opt/homebrew/opt/ccache/libexec/cc -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -fPIC -g -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src -I./../src/tools-2.10-f6f5d5bdde.clean/src -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -fPIC -g -MT benchmark/run_benchmark.lo -MD -MP -MF benchmark/.deps/run_benchmark.Tpo -c ./../src/tools-2.10-f6f5d5bdde.clean/benchmark/run_benchmark.c -o benchmark/run_benchmark.o
libtool: compile:  /opt/homebrew/opt/ccache/libexec/cc -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -fPIC -g -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src -I./../src/tools-2.10-f6f5d5bdde.clean/src -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -fPIC -g -MT src/base/dynamic_annotations.lo -MD -MP -MF src/base/.deps/dynamic_annotations.Tpo -c ./../src/tools-2.10-f6f5d5bdde.clean/src/base/dynamic_annotations.c -o src/base/dynamic_annotations.o
libtool: compile:  /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src -I./../src/tools-2.10-f6f5d5bdde.clean/src -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -MT src/base/logging.lo -MD -MP -MF src/base/.deps/logging.Tpo -c ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.cc -o src/base/logging.o
libtool: compile:  /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src -I./../src/tools-2.10-f6f5d5bdde.clean/src -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -MT src/base/sysinfo.lo -MD -MP -MF src/base/.deps/sysinfo.Tpo -c ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc -o src/base/sysinfo.o
libtool: compile:  /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DHAVE_CONFIG_H -I. -I./../src/tools-2.10-f6f5d5bdde.clean -I./src -I./../src/tools-2.10-f6f5d5bdde.clean/src -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -MT src/maybe_threads.lo -MD -MP -MF src/.deps/maybe_threads.Tpo -c ./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc -o src/maybe_threads.o
/bin/sh ./libtool  --tag=CC   --mode=link /opt/homebrew/opt/ccache/libexec/cc -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -fPIC -g  -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o librun_benchmark.la  benchmark/run_benchmark.lo  
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o liblogging.la  src/base/logging.lo src/base/dynamic_annotations.lo   
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o libsysinfo.la  src/base/sysinfo.lo    
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o libmaybe_threads.la   src/maybe_threads.lo  
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/libfake_stacktrace_scope.a  src/fake_stacktrace_scope.o
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/libfake_stacktrace_scope.a
libtool: link: /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o getpc_test src/tests/getpc_test.o -Wl,-bind_at_load  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib
libtool: link: ( cd ".libs" && rm -f "libfake_stacktrace_scope.la" && ln -s "../libfake_stacktrace_scope.la" "libfake_stacktrace_scope.la" )
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/libspinlock.a  src/base/spinlock.o src/base/spinlock_internal.o src/base/atomicops-internals-x86.o
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/libspinlock.a
libtool: link: ( cd ".libs" && rm -f "libspinlock.la" && ln -s "../libspinlock.la" "libspinlock.la" )
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/librun_benchmark.a  benchmark/run_benchmark.o
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/librun_benchmark.a
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/liblogging.a  src/base/logging.o src/base/dynamic_annotations.o
libtool: link: ( cd ".libs" && rm -f "librun_benchmark.la" && ln -s "../librun_benchmark.la" "librun_benchmark.la" )
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/libsysinfo.a  src/base/sysinfo.o
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/liblogging.a
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/libmaybe_threads.a  src/maybe_threads.o
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/libsysinfo.a
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/libmaybe_threads.a
libtool: link: ( cd ".libs" && rm -f "liblogging.la" && ln -s "../liblogging.la" "liblogging.la" )
libtool: link: ( cd ".libs" && rm -f "libsysinfo.la" && ln -s "../libsysinfo.la" "libsysinfo.la" )
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -g -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o addressmap_unittest src/tests/addressmap_unittest-addressmap_unittest.o   liblogging.la 
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -export-symbols-regex '(GetStackTrace|GetStackFrames|GetStackTraceWithContext|GetStackFramesWithContext)' -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o libstacktrace.la  src/stacktrace.lo src/base/elf_mem_image.lo src/base/vdso_support.lo    libspinlock.la libsysinfo.la liblogging.la 
libtool: link: ( cd ".libs" && rm -f "libmaybe_threads.la" && ln -s "../libmaybe_threads.la" "libmaybe_threads.la" )
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o atomicops_unittest src/tests/atomicops_unittest.o  libspinlock.la libsysinfo.la liblogging.la 
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -DNDEBUG -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o libtcmalloc_minimal_internal.la  src/libtcmalloc_minimal_internal_la-common.lo src/libtcmalloc_minimal_internal_la-internal_logging.lo src/libtcmalloc_minimal_internal_la-system-alloc.lo src/libtcmalloc_minimal_internal_la-memfs_malloc.lo src/libtcmalloc_minimal_internal_la-central_freelist.lo src/libtcmalloc_minimal_internal_la-page_heap.lo src/libtcmalloc_minimal_internal_la-sampler.lo src/libtcmalloc_minimal_internal_la-span.lo src/libtcmalloc_minimal_internal_la-stack_trace_table.lo src/libtcmalloc_minimal_internal_la-static_vars.lo src/libtcmalloc_minimal_internal_la-symbolize.lo src/libtcmalloc_minimal_internal_la-thread_cache.lo src/libtcmalloc_minimal_internal_la-malloc_hook.lo src/libtcmalloc_minimal_internal_la-malloc_extension.lo    libspinlock.la libsysinfo.la liblogging.la libmaybe_threads.la 
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DNO_TCMALLOC_SAMPLES -fPIC -g -no-undefined  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o low_level_alloc_unittest src/base/low_level_alloc_unittest-low_level_alloc.o src/low_level_alloc_unittest-malloc_hook.o src/tests/low_level_alloc_unittest-low_level_alloc_unittest.o   libspinlock.la libsysinfo.la liblogging.la libmaybe_threads.la 
/bin/sh ./libtool  --tag=CXX   --mode=link /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -D_THREAD_SAFE  -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare  -Wno-unused-result -fsized-deallocation -faligned-new   -fPIC -g -D_THREAD_SAFE   -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o tcm_min_asserts_unittest src/tests/tcm_min_asserts_unittest-tcmalloc_unittest.o src/tests/tcm_min_asserts_unittest-testutil.o src/tcm_min_asserts_unittest-common.o src/tcm_min_asserts_unittest-internal_logging.o src/tcm_min_asserts_unittest-system-alloc.o src/tcm_min_asserts_unittest-memfs_malloc.o src/tcm_min_asserts_unittest-central_freelist.o src/tcm_min_asserts_unittest-page_heap.o src/tcm_min_asserts_unittest-sampler.o src/tcm_min_asserts_unittest-span.o src/tcm_min_asserts_unittest-stack_trace_table.o src/tcm_min_asserts_unittest-static_vars.o src/tcm_min_asserts_unittest-symbolize.o src/tcm_min_asserts_unittest-thread_cache.o src/tcm_min_asserts_unittest-malloc_hook.o src/tcm_min_asserts_unittest-malloc_extension.o    src/tcm_min_asserts_unittest-tcmalloc.o    libspinlock.la libsysinfo.la liblogging.la libmaybe_threads.la liblogging.la  
libtool: link: /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -g -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o addressmap_unittest src/tests/addressmap_unittest-addressmap_unittest.o -Wl,-bind_at_load  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib ./.libs/liblogging.a
libtool: link: /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o atomicops_unittest src/tests/atomicops_unittest.o -Wl,-bind_at_load  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib ./.libs/libspinlock.a ./.libs/libsysinfo.a ./.libs/liblogging.a
libtool: link: (cd .libs/libstacktrace.lax/libspinlock.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/libspinlock.a")
libtool: link: /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DNO_TCMALLOC_SAMPLES -fPIC -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o low_level_alloc_unittest src/base/low_level_alloc_unittest-low_level_alloc.o src/low_level_alloc_unittest-malloc_hook.o src/tests/low_level_alloc_unittest-low_level_alloc_unittest.o -Wl,-bind_at_load  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib ./.libs/libspinlock.a ./.libs/libsysinfo.a ./.libs/liblogging.a ./.libs/libmaybe_threads.a
libtool: link: (cd .libs/libtcmalloc_minimal_internal.lax/libspinlock.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/libspinlock.a")
libtool: link: /opt/homebrew/opt/ccache/libexec/c++ -std=gnu++11 -std=gnu++11 -DNO_TCMALLOC_SAMPLES -DNO_HEAP_CHECK -D_THREAD_SAFE -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Wno-unused-result -fsized-deallocation -faligned-new -fPIC -g -D_THREAD_SAFE -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk -o tcm_min_asserts_unittest src/tests/tcm_min_asserts_unittest-tcmalloc_unittest.o src/tests/tcm_min_asserts_unittest-testutil.o src/tcm_min_asserts_unittest-common.o src/tcm_min_asserts_unittest-internal_logging.o src/tcm_min_asserts_unittest-system-alloc.o src/tcm_min_asserts_unittest-memfs_malloc.o src/tcm_min_asserts_unittest-central_freelist.o src/tcm_min_asserts_unittest-page_heap.o src/tcm_min_asserts_unittest-sampler.o src/tcm_min_asserts_unittest-span.o src/tcm_min_asserts_unittest-stack_trace_table.o src/tcm_min_asserts_unittest-static_vars.o src/tcm_min_asserts_unittest-symbolize.o src/tcm_min_asserts_unittest-thread_cache.o src/tcm_min_asserts_unittest-malloc_hook.o src/tcm_min_asserts_unittest-malloc_extension.o src/tcm_min_asserts_unittest-tcmalloc.o -Wl,-bind_at_load  -L/Users/mapletechnologies/Desktop/big_projects/bon/vcpkg_installed/arm64-osx/debug/lib -L/opt/homebrew/opt/libpq/lib ./.libs/libspinlock.a ./.libs/libsysinfo.a ./.libs/libmaybe_threads.a ./.libs/liblogging.a
libtool: link: (cd .libs/libstacktrace.lax/libsysinfo.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/libsysinfo.a")
libtool: link: (cd .libs/libtcmalloc_minimal_internal.lax/libsysinfo.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/libsysinfo.a")
libtool: link: (cd .libs/libstacktrace.lax/liblogging.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/liblogging.a")
libtool: link: (cd .libs/libtcmalloc_minimal_internal.lax/liblogging.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/liblogging.a")
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/libstacktrace.a  src/stacktrace.o src/base/elf_mem_image.o src/base/vdso_support.o  .libs/libstacktrace.lax/libspinlock.a/atomicops-internals-x86.o .libs/libstacktrace.lax/libspinlock.a/spinlock.o .libs/libstacktrace.lax/libspinlock.a/spinlock_internal.o  .libs/libstacktrace.lax/libsysinfo.a/sysinfo.o  .libs/libstacktrace.lax/liblogging.a/dynamic_annotations.o .libs/libstacktrace.lax/liblogging.a/logging.o 
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/libstacktrace.a
libtool: link: rm -fr .libs/libstacktrace.lax
libtool: link: ( cd ".libs" && rm -f "libstacktrace.la" && ln -s "../libstacktrace.la" "libstacktrace.la" )
libtool: link: (cd .libs/libtcmalloc_minimal_internal.lax/libmaybe_threads.a && /opt/homebrew/opt/binutils/bin/ar x "/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/./.libs/libmaybe_threads.a")
libtool: link: /opt/homebrew/opt/binutils/bin/ar cr .libs/libtcmalloc_minimal_internal.a  src/libtcmalloc_minimal_internal_la-common.o src/libtcmalloc_minimal_internal_la-internal_logging.o src/libtcmalloc_minimal_internal_la-system-alloc.o src/libtcmalloc_minimal_internal_la-memfs_malloc.o src/libtcmalloc_minimal_internal_la-central_freelist.o src/libtcmalloc_minimal_internal_la-page_heap.o src/libtcmalloc_minimal_internal_la-sampler.o src/libtcmalloc_minimal_internal_la-span.o src/libtcmalloc_minimal_internal_la-stack_trace_table.o src/libtcmalloc_minimal_internal_la-static_vars.o src/libtcmalloc_minimal_internal_la-symbolize.o src/libtcmalloc_minimal_internal_la-thread_cache.o src/libtcmalloc_minimal_internal_la-malloc_hook.o src/libtcmalloc_minimal_internal_la-malloc_extension.o  .libs/libtcmalloc_minimal_internal.lax/libspinlock.a/atomicops-internals-x86.o .libs/libtcmalloc_minimal_internal.lax/libspinlock.a/spinlock.o .libs/libtcmalloc_minimal_internal.lax/libspinlock.a/spinlock_internal.o  .libs/libtcmalloc_minimal_internal.lax/libsysinfo.a/sysinfo.o  .libs/libtcmalloc_minimal_internal.lax/liblogging.a/dynamic_annotations.o .libs/libtcmalloc_minimal_internal.lax/liblogging.a/logging.o  .libs/libtcmalloc_minimal_internal.lax/libmaybe_threads.a/maybe_threads.o 
libtool: link: /opt/homebrew/opt/binutils/bin/ranlib .libs/libtcmalloc_minimal_internal.a
libtool: link: rm -fr .libs/libtcmalloc_minimal_internal.lax
libtool: link: ( cd ".libs" && rm -f "libtcmalloc_minimal_internal.la" && ln -s "../libtcmalloc_minimal_internal.la" "libtcmalloc_minimal_internal.la" )
```
</details>

<details><summary>/Users/mapletechnologies/vcpkg/buildtrees/gperftools/build-arm64-osx-dbg-err.log</summary>

```
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:36:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.h:45:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:311:9: warning: '_dyld_present' is deprecated: first deprecated in macOS 10.5 - always true [-Wdeprecated-declarations]
    if (_dyld_present()) {
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/dyld.h:263:13: note: '_dyld_present' has been explicitly marked deprecated here
extern bool _dyld_present(void)                                                              __API_UNAVAILABLE(ios, tvos, watchos)  DYLD_DRIVERKIT_UNAVAILABLE DYLD_EXCLAVEKIT_UNAVAILABLE __OSX_DEPRECATED(10.1, 10.5, "always true");
            ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:36:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.h:45:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:317:21: warning: 'getsectdatafromheader_64' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader_64((mach_header_64*)hdr,
                    ^~~~~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:130:14: note: 'getsectdatafromheader_64' has been explicitly marked deprecated here
extern char *getsectdatafromheader_64(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:36:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.h:45:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:328:21: warning: 'getsectdatafromheader' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader(hdr, "__TEXT", name, &len);
                    ^~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:110:14: note: 'getsectdatafromheader' has been explicitly marked deprecated here
extern char *getsectdatafromheader(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:36:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.h:45:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:339:15: warning: 'getsectdata' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
    *pstart = getsectdata("__TEXT", name, &len);
              ^~~~~~~~~~~
              use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:46:14: note: 'getsectdata' has been explicitly marked deprecated here
extern char *getsectdata(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:107:3: warning: 'OSMemoryBarrier' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_thread_fence() from <atomic> instead [-Wdeprecated-declarations]
  OSMemoryBarrier();
  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:751:9: note: 'OSMemoryBarrier' has been explicitly marked deprecated here
void    OSMemoryBarrier( void );
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:117:9: warning: 'OSAtomicCompareAndSwap32' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong_explicit(std::memory_order_relaxed) from <atomic> instead [-Wdeprecated-declarations]
    if (OSAtomicCompareAndSwap32(old_value, new_value,
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:504:9: note: 'OSAtomicCompareAndSwap32' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap32( int32_t __oldValue, int32_t __newValue, volatile int32_t *__theValue );
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:131:13: warning: 'OSAtomicCompareAndSwap32' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong_explicit(std::memory_order_relaxed) from <atomic> instead [-Wdeprecated-declarations]
  } while (!OSAtomicCompareAndSwap32(old_value, new_value,
            ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:504:9: note: 'OSAtomicCompareAndSwap32' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap32( int32_t __oldValue, int32_t __newValue, volatile int32_t *__theValue );
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:141:13: warning: 'OSAtomicCompareAndSwap32Barrier' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong() from <atomic> instead [-Wdeprecated-declarations]
  } while (!OSAtomicCompareAndSwap32Barrier(old_value, new_value,
            ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:520:9: note: 'OSAtomicCompareAndSwap32Barrier' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap32Barrier( int32_t __oldValue, int32_t __newValue, volatile int32_t *__theValue );
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:156:9: warning: 'OSAtomicCompareAndSwap32Barrier' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong() from <atomic> instead [-Wdeprecated-declarations]
    if (OSAtomicCompareAndSwap32Barrier(old_value, new_value,
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:520:9: note: 'OSAtomicCompareAndSwap32Barrier' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap32Barrier( int32_t __oldValue, int32_t __newValue, volatile int32_t *__theValue );
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:197:9: warning: 'OSAtomicCompareAndSwap64' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong_explicit(std::memory_order_relaxed) from <atomic> instead [-Wdeprecated-declarations]
    if (OSAtomicCompareAndSwap64(old_value, new_value,
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:630:9: note: 'OSAtomicCompareAndSwap64' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap64( int64_t __oldValue, int64_t __newValue,
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:211:13: warning: 'OSAtomicCompareAndSwap64' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong_explicit(std::memory_order_relaxed) from <atomic> instead [-Wdeprecated-declarations]
  } while (!OSAtomicCompareAndSwap64(old_value, new_value,
            ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:630:9: note: 'OSAtomicCompareAndSwap64' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap64( int64_t __oldValue, int64_t __newValue,
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-macosx.h:221:13: warning: 'OSAtomicCompareAndSwap64Barrier' is deprecated: first deprecated in macOS 10.12 - Use std::atomic_compare_exchange_strong() from <atomic> instead [-Wdeprecated-declarations]
  } while (!OSAtomicCompareAndSwap64Barrier(old_value, new_value,
            ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/libkern/OSAtomicDeprecated.h:647:9: note: 'OSAtomicCompareAndSwap64Barrier' has been explicitly marked deprecated here
bool    OSAtomicCompareAndSwap64Barrier( int64_t __oldValue, int64_t __newValue,
        ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/common.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/spinlock.h:43:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops.h:114:
...
Skipped 24257 lines
...
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:110:14: note: 'getsectdatafromheader' has been explicitly marked deprecated here
extern char *getsectdatafromheader(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-x86.cc:37:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:339:15: warning: 'getsectdata' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
    *pstart = getsectdata("__TEXT", name, &len);
              ^~~~~~~~~~~
              use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:46:14: note: 'getsectdata' has been explicitly marked deprecated here
extern char *getsectdata(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/atomicops-internals-x86.cc:38:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/googleinit.h:37:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:207:3: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
  WRITE_TO_STDERR(buf, strlen(buf));
  ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:61:35: note: expanded from macro 'WRITE_TO_STDERR'
#define WRITE_TO_STDERR(buf, len) syscall(SYS_write, STDERR_FILENO, buf, len)
                                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
14 warnings generated.
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.cc:35:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:49:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/commandlineflags.h:56:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:311:9: warning: '_dyld_present' is deprecated: first deprecated in macOS 10.5 - always true [-Wdeprecated-declarations]
    if (_dyld_present()) {
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/dyld.h:263:13: note: '_dyld_present' has been explicitly marked deprecated here
extern bool _dyld_present(void)                                                              __API_UNAVAILABLE(ios, tvos, watchos)  DYLD_DRIVERKIT_UNAVAILABLE DYLD_EXCLAVEKIT_UNAVAILABLE __OSX_DEPRECATED(10.1, 10.5, "always true");
            ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.cc:35:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:49:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/commandlineflags.h:56:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:317:21: warning: 'getsectdatafromheader_64' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader_64((mach_header_64*)hdr,
                    ^~~~~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:130:14: note: 'getsectdatafromheader_64' has been explicitly marked deprecated here
extern char *getsectdatafromheader_64(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.cc:35:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:49:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/commandlineflags.h:56:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:328:21: warning: 'getsectdatafromheader' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader(hdr, "__TEXT", name, &len);
                    ^~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:110:14: note: 'getsectdatafromheader' has been explicitly marked deprecated here
extern char *getsectdatafromheader(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.cc:35:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:49:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/commandlineflags.h:56:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:339:15: warning: 'getsectdata' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
    *pstart = getsectdata("__TEXT", name, &len);
              ^~~~~~~~~~~
              use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:46:14: note: 'getsectdata' has been explicitly marked deprecated here
extern char *getsectdata(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.cc:35:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:207:3: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
  WRITE_TO_STDERR(buf, strlen(buf));
  ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:61:35: note: expanded from macro 'WRITE_TO_STDERR'
#define WRITE_TO_STDERR(buf, len) syscall(SYS_write, STDERR_FILENO, buf, len)
                                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
5 warnings generated.
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:59:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.h:49:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:311:9: warning: '_dyld_present' is deprecated: first deprecated in macOS 10.5 - always true [-Wdeprecated-declarations]
    if (_dyld_present()) {
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/dyld.h:263:13: note: '_dyld_present' has been explicitly marked deprecated here
extern bool _dyld_present(void)                                                              __API_UNAVAILABLE(ios, tvos, watchos)  DYLD_DRIVERKIT_UNAVAILABLE DYLD_EXCLAVEKIT_UNAVAILABLE __OSX_DEPRECATED(10.1, 10.5, "always true");
            ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:59:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.h:49:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:317:21: warning: 'getsectdatafromheader_64' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader_64((mach_header_64*)hdr,
                    ^~~~~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:130:14: note: 'getsectdatafromheader_64' has been explicitly marked deprecated here
extern char *getsectdatafromheader_64(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:59:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.h:49:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:328:21: warning: 'getsectdatafromheader' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader(hdr, "__TEXT", name, &len);
                    ^~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:110:14: note: 'getsectdatafromheader' has been explicitly marked deprecated here
extern char *getsectdatafromheader(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:59:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.h:49:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:339:15: warning: 'getsectdata' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
    *pstart = getsectdata("__TEXT", name, &len);
              ^~~~~~~~~~~
              use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:46:14: note: 'getsectdata' has been explicitly marked deprecated here
extern char *getsectdata(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:59:
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.h:50:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:207:3: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
  WRITE_TO_STDERR(buf, strlen(buf));
  ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:61:35: note: expanded from macro 'WRITE_TO_STDERR'
#define WRITE_TO_STDERR(buf, len) syscall(SYS_write, STDERR_FILENO, buf, len)
                                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:178:14: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
    int fd = safeopen("/proc/self/environ", O_RDONLY);
             ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:92:36: note: expanded from macro 'safeopen'
# define safeopen(filename, mode)  syscall(SYS_open, filename, mode)
                                   ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:181:9: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
        saferead(fd, envbuf, sizeof(envbuf) - 2) < 0) { // error reading file
        ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:97:38: note: expanded from macro 'saferead'
# define saferead(fd, buffer, size)  syscall(SYS_read, fd, buffer, size)
                                     ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:184:21: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
      if (fd != -1) safeclose(fd);
                    ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:102:25: note: expanded from macro 'safeclose'
# define safeclose(fd)  syscall(SYS_close, fd)
                        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:187:5: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
    safeclose(fd);
    ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:102:25: note: expanded from macro 'safeclose'
# define safeclose(fd)  syscall(SYS_close, fd)
                        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:350:5: warning: unused function 'StringToInteger<int>' [-Wunused-function]
int StringToInteger<int>(char *text, char **endptr, int base) {
    ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:355:7: warning: unused function 'StringToInteger<long long>' [-Wunused-function]
int64 StringToInteger<int64>(char *text, char **endptr, int base) {
      ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:360:8: warning: unused function 'StringToInteger<unsigned long long>' [-Wunused-function]
uint64 StringToInteger<uint64>(char *text, char **endptr, int base) {
       ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:388:14: warning: unused function 'CopyStringUntilChar' [-Wunused-function]
static char *CopyStringUntilChar(
             ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:411:13: warning: unused function 'ParseProcMapsLine' [-Wunused-function]
static bool ParseProcMapsLine(char *text, uint64 *start, uint64 *end,
            ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.cc:59:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/sysinfo.h:216:8: warning: private field 'flags_' is not used [-Wunused-private-field]
  char flags_[10];
       ^
15 warnings generated.
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc:50:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:311:9: warning: '_dyld_present' is deprecated: first deprecated in macOS 10.5 - always true [-Wdeprecated-declarations]
    if (_dyld_present()) {
        ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/dyld.h:263:13: note: '_dyld_present' has been explicitly marked deprecated here
extern bool _dyld_present(void)                                                              __API_UNAVAILABLE(ios, tvos, watchos)  DYLD_DRIVERKIT_UNAVAILABLE DYLD_EXCLAVEKIT_UNAVAILABLE __OSX_DEPRECATED(10.1, 10.5, "always true");
            ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc:50:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:317:21: warning: 'getsectdatafromheader_64' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader_64((mach_header_64*)hdr,
                    ^~~~~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:130:14: note: 'getsectdatafromheader_64' has been explicitly marked deprecated here
extern char *getsectdatafromheader_64(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc:50:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:328:21: warning: 'getsectdatafromheader' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
          *pstart = getsectdatafromheader(hdr, "__TEXT", name, &len);
                    ^~~~~~~~~~~~~~~~~~~~~
                    use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:110:14: note: 'getsectdatafromheader' has been explicitly marked deprecated here
extern char *getsectdatafromheader(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc:50:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/basictypes.h:339:15: warning: 'getsectdata' is deprecated: first deprecated in macOS 13.0 [-Wdeprecated-declarations]
    *pstart = getsectdata("__TEXT", name, &len);
              ^~~~~~~~~~~
              use getsectiondata()
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/mach-o/getsect.h:46:14: note: 'getsectdata' has been explicitly marked deprecated here
extern char *getsectdata(
             ^
In file included from ./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc:51:
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:207:3: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
  WRITE_TO_STDERR(buf, strlen(buf));
  ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:61:35: note: expanded from macro 'WRITE_TO_STDERR'
#define WRITE_TO_STDERR(buf, len) syscall(SYS_write, STDERR_FILENO, buf, len)
                                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
./../src/tools-2.10-f6f5d5bdde.clean/src/maybe_threads.cc:173:5: warning: 'syscall' is deprecated: first deprecated in macOS 10.12 - syscall(2) is unsupported; please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost(). [-Wdeprecated-declarations]
    CHECK(rv == 0);
    ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:87:7: note: expanded from macro 'CHECK'
      WRITE_TO_STDERR("Check failed: " #condition "\n",                 \
      ^
./../src/tools-2.10-f6f5d5bdde.clean/src/base/logging.h:61:35: note: expanded from macro 'WRITE_TO_STDERR'
#define WRITE_TO_STDERR(buf, len) syscall(SYS_write, STDERR_FILENO, buf, len)
                                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/include/unistd.h:748:6: note: 'syscall' has been explicitly marked deprecated here
int      syscall(int, ...);
         ^
6 warnings generated.
ld: warning: -bind_at_load is deprecated on macOS
ld: warning: -bind_at_load is deprecated on macOS
ld: archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/liblogging.a'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [addressmap_unittest] Error 1
make: *** Waiting for unfinished jobs....
ld: warning: -bind_at_load is deprecated on macOS
ld: multiple errors: archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libspinlock.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libsysinfo.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/liblogging.a'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [atomicops_unittest] Error 1
ld: warning: -bind_at_load is deprecated on macOS
ld: multiple errors: archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libmaybe_threads.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libsysinfo.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/liblogging.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libspinlock.a'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [low_level_alloc_unittest] Error 1
ld: warning: -bind_at_load is deprecated on macOS
ld: multiple errors: archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libspinlock.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libmaybe_threads.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/liblogging.a'; archive member '/' not a mach-o file in '/Users/mapletechnologies/vcpkg/buildtrees/gperftools/arm64-osx-dbg/.libs/libsysinfo.a'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [tcm_min_asserts_unittest] Error 1
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "name": "bon",
  "version": "1.0.0",
  "description": "Bon is a high-performance, distributed, columnar, in-memory store with a SQL query interface.",
  "homepage": "https://github.com/meftunca/bon",
  "license": "MIT",
  "supports": "native",
  "dependencies": [
    "eve",
    "simdjson",
    "mio",
    "taskflow",
    "zstd",
    "lz4",
    "fast-float",
    "gperftools"
  ]
}

```
</details>
