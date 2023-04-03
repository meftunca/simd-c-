clone_eve:
	cd eve;
	git clone https://github.com/jfalcou/eve.git eve_repo;cd eve_repo;
build_eve:
	cd eve/eve_repo;
	cmake -B build -G Ninja
	cmake --install build --prefix ../eve
conan-build-debug:
	conan install . -s build_type=Debug -of=conandeps -s compiler.cppstd=20 -s compiler.libcxx=libstdc++ --build=missing
conan-build-release:
	conan install . -s build_type=Release  -of conandeps
build:
	bazel build --cxxopt='-std=c++2a' //src:simd_out --spawn_strategy=local -c dbg --copt=-O3 --cxxopt=-O3
clean:
	bazel clean --expunge
run:
	bazel-bin/src/simd
debug-run:
	export json_DATA=$(PWD)/Data
	bazel build --cxxopt='-std=c++2a'  -c dbg --spawn_strategy=local -s //src:simd
	bazel-bin/src/simd
build-run:
	make build
	make run
visualize:
	bazel query 'deps(//src:simd)' --output graph > graph.in
build-ff:
	clang++ -Ofast -std=c++2a ff.cc -xc -o ff;./ff
perf-profiling:
	bazel analyze-profile ./log/perf
analyze-profiling:
	bazel build --cxxopt='-std=c++20'  --profile=./logs/analyze //src:simd
	bazel analyze-profile ./logs/analyze
test-with-optimize:
	bazel test -c dbg
test:
	bazel test --cxxopt='-std=c++20' --cxxopt=-O3 -c dbg  --test_output=all --test_arg=--verbose --spawn_strategy=local //tests:testing
bench:
	bazelisk build -c opt --strip=always //benchmark:benchmark
	bazel-bin/benchmark/benchmark --benchmark_format=console --benchmark_counters_tabular=true --benchmark_out="benchmark/benchmark__$(TIMESTAMP).json" --benchmark_out_format=json