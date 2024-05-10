clone_eve:
	cd eve;
	git clone https://github.com/jfalcou/eve.git eve_repo;cd eve_repo;
build_eve:
	cd eve/eve_repo;
	cmake -B build -G Ninja
	cmake --install build --prefix ../eve
conan-build-debug:
	conan install . -s build_type=Debug  -of ./conanDeps --build=missing
conan-build-release:
	conan install . -s build_type=Release  -of ./conanDeps --build=missing -s compiler.cppstd=20 -s compiler.libcxx=libstdc++ 
build_source:
	bazel build -c dbg --save_temps  //src:bon_out --spawn_strategy=local 
clean:
	bazel clean --expunge
run:
	bazel-bin/src/bon
compile_db:
	bazel run @hedron_compile_commands//:refresh_all
debug-run:
	export json_DATA=$(PWD)/Data
	bazel build --cxxopt='-std=c++2b'  -c dbg --spawn_strategy=local -s //src:bon
	bazel-bin/src/bon
build-run:
	bazel build  --sandbox_debug --verbose_failures --cxxopt='-std=c++2b' --spawn_strategy=local //src:bon
	make run
	pprof --svg bazel-bin/src/bon ./output/cpu_profile.prof > ./output/cpu_profile.svg
visualize:
	bazel query 'deps(//src:bon)' --output graph > graph.in
build-ff:
	clang++ -Ofast -std=c++2b ff.cc -xc -o ff;./ff
perf-profiling:
	bazel analyze-profile ./log/perf
analyze-profiling:
	bazel build --cxxopt='-std=c++2b'  --profile=./logs/analyze //src:bon
	bazel analyze-profile ./logs/analyze
test-with-optimize:
	bazel test -c dbg
test:
	bazelisk test --cxxopt='-std=c++2b'  -c dbg //tests:testing  --define tcmalloc=gperftools --test_output=all --sandbox_debug 
bench:
	bazelisk build -c opt --cxxopt='-std=c++2b'  //benchmark:benchmark
	bazel-bin/benchmark/benchmark --benchmark_format=console --benchmark_counters_tabular=true --benchmark_out="benchmark/benchmark__$(TIMESTAMP).json" --benchmark_out_format=json