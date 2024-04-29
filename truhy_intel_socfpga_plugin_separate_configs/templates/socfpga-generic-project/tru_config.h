/*
	MIT License

	Copyright (c) 2023 Truong Hy

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

	Version: 20240428

	Trulib configuration
 */

#ifndef TRU_CONFIG_H
#define TRU_CONFIG_H

// =============
// User settings
// =============

#define TRU_USER_TARGET                 TRU_C5SOC

#define TRU_USER_DEBUG_PRINT_LEVEL      1U
#define TRU_USER_DEBUG_PRINT_UART       1U
#define TRU_USER_REL_PRINT_LEVEL        0U
#define TRU_USER_REL_PRINT_UART         0U
#define TRU_USER_PRINT_UART_R_NL        1U


// ===============================
// Apply user or override settings
// ===============================

#ifdef CYCLONEV
	#define TRU_TARGET TRU_C5SOC
#else
	#ifndef TRU_TARGET
		#define TRU_TARGET TRU_USER_TARGET
	#endif
#endif

#ifdef SEMIHOSTING
	#define TRU_PRINT_UART 0U
#endif

#ifdef DEBUG
	#ifndef TRU_DEBUG_PRINT_LEVEL
		#define TRU_DEBUG_PRINT_LEVEL TRU_USER_DEBUG_PRINT_LEVEL
	#endif

	#ifndef TRU_PRINT_UART
		#define TRU_PRINT_UART TRU_USER_DEBUG_PRINT_UART
	#endif
#else
	#ifndef TRU_REL_PRINT_LEVEL
		#define TRU_DEBUG_PRINT_LEVEL TRU_USER_REL_PRINT_LEVEL
	#endif

	#ifndef TRU_PRINT_UART
		#define TRU_PRINT_UART TRU_USER_REL_PRINT_UART
	#endif
#endif

#ifndef TRU_PRINT_UART_R_NL
	// 1U == Enables insertion of '\r' for each '\n' character
	#define TRU_PRINT_UART_R_NL TRU_USER_PRINT_UART_R_NL
#endif

#endif
