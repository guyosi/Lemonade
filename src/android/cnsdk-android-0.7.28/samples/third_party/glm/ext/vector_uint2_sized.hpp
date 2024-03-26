/*
 * Copyright (c) 2023 Leia Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/// @ref ext_vector_uint2_sized
/// @file glm/ext/vector_uint2_sized.hpp
///
/// @defgroup ext_vector_uint2_sized GLM_EXT_vector_uint2_sized
/// @ingroup ext
///
/// Exposes sized unsigned integer vector of 2 components type.
///
/// Include <glm/ext/vector_uint2_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_uint_sized
/// @see ext_vector_int2_sized

#pragma once

#include "../ext/vector_uint2.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_uint2_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_uint2_sized
	/// @{

	/// 8 bit unsigned integer vector of 2 components type.
	///
	/// @see ext_vector_uint2_sized
	typedef vec<2, uint8, defaultp>		u8vec2;

	/// 16 bit unsigned integer vector of 2 components type.
	///
	/// @see ext_vector_uint2_sized
	typedef vec<2, uint16, defaultp>	u16vec2;

	/// 32 bit unsigned integer vector of 2 components type.
	///
	/// @see ext_vector_uint2_sized
	typedef vec<2, uint32, defaultp>	u32vec2;

	/// 64 bit unsigned integer vector of 2 components type.
	///
	/// @see ext_vector_uint2_sized
	typedef vec<2, uint64, defaultp>	u64vec2;

	/// @}
}//namespace glm
