/*
 * video_capture.h
 *
 *  Created on: Dec 24, 2015
 *      Author: Lincoln
 */

#ifndef VIDEO_CAPTURE_H_
#define VIDEO_CAPTURE_H_

#include <stddef.h>

#define CLEAR(x) memset (&(x), 0, sizeof (x))

struct buffer {
	void * start;
	size_t length;
};

void init_video_capture(int width, int height);
char video_capture(unsigned char* dst, int width, int height);
void free_video_capture();

#endif /* VIDEO_CAPTURE_H_ */
