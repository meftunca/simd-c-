#if defined(__AVX2__)
#  include "avx2.hpp"
#elif defined(__AVX__)
#  include "avx.hpp"
#elif defined(__AVX512__)
#  include "avx512.hpp"
#elif defined(__SSE4_1__)
#  include "sse41.hpp"
#elif defined(__SSE2__)
#  include "sse42.hpp"
#elif defined(__ARM_NEON__)
#  include "armneon.hpp"
#else
#  include "stdranges.hpp"
#endif