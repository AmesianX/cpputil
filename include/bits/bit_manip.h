// Copyright 2014 eric schkufza
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CPPUTIL_INCLUDE_BITS_BIT_MANIP_H
#define CPPUTIL_INCLUDE_BITS_BIT_MANIP_H

#include <stdint.h>

#include <immintrin.h>

namespace cpputil {

template <typename T>
class BitManip;

template <>
class BitManip<uint64_t> {
	public:
		static size_t ntz(uint64_t x) {
#ifdef __BMI__	
			return _tzcnt_u64(x);
#else
			assert(false);
			return 0;
#endif
		}

		static uint64_t& unset_rightmost(uint64_t& x) {
#ifdef __BMI__
			return (x = _blsr_u64(x));
#else
			return (x &= (x-1));
#endif
		}
};

} // namespace cpputil

#endif
