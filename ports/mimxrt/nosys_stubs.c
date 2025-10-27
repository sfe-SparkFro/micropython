/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2024 OpenMV LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>

int _open(const char *name, int flags, int mode) {
    errno = ENOSYS;
    return -1;
}

int _write(int handle, char *buffer, int size) {
    errno = ENOSYS;
    return -1;
}

int _read(int handle, char *buffer, int size) {
    errno = ENOSYS;
    return -1;
}

int _close(int f) {
    errno = ENOSYS;
    return -1;
}

int _lseek(int f, int ptr, int dir) {
    errno = ENOSYS;
    return -1;
}

int _getpid(void) {
    return 0;
}

 int _kill( int pid, int sig) {
    return -1;
}

int  _fstat( int fd,  struct stat *buf) {
    return -1;
}

int _isatty(int fd) {
    return -1;
    
}

void _exit(int err){
   
    while(1);
}

caddr_t _sbrk(int incr)
{
	extern char __end__;
    extern char *__stack;
	static char *heap_end;
	char *prev_heap_end;

	if (heap_end == 0)
		heap_end = &__end__;;



	prev_heap_end = heap_end;
	if (heap_end + incr > __stack)
	{
//		write(1, "Heap and stack collision\n", 25);
//		abort();
		errno = ENOMEM;
		return (caddr_t) -1;
	}

	heap_end += incr;

	return (caddr_t) prev_heap_end;
}

void _fini(void) __attribute__((weak));
void _fini(void) {
    // Empty function - no cleanup needed
}

int _unlink(const char *name) {
    errno = ENOSYS;
    return -1;
}

int _gettimeofday(struct timeval *tv, void *tzvp) {
  if (tv) {
    tv->tv_sec = 0;     // or read from RTC
    tv->tv_usec = 0;
  }
  return 0;
}