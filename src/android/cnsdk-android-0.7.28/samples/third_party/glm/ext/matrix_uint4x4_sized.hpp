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

/// @ref ext_matrix_uint4x4_sized
/// @file glm/ext/matrix_uint4x4_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_uint4x4_sized GLM_EXT_matrix_uint4x4_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_uint4x4_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat4x4.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint4x4_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_uint4x4_sized
	/// @{

	/// 8 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint8, defaultp>				u8mat4x4;

	/// 16 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint16, defaultp>				u16mat4x4;

	/// 32 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint32, defaultp>				u32mat4x4;

	/// 64 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint64, defaultp>				u64mat4x4;


	/// 8 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint8, defaultp>				u8mat4;

	/// 16 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint16, defaultp>				u16mat4;

	/// 32 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint32, defaultp>				u32mat4;

	/// 64 bit unsigned integer 4x4 matrix.
	///
	/// @see ext_matrix_uint4x4_sized
	typedef mat<4, 4, uint64, defaultp>				u64mat4;

	/// @}
}//namespace glm
