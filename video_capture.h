/*
 * video_capture.h
 *
 *  Created on: Dec 24, 2015
 *      Author: Lincoln
 */

#ifndef VIDEO_CAPTURE_H_
#define VIDEO_CAPTURE_H_

/* check the supported webcam resolutions using $v4l2-ctl --list-formats-ext */
#define IM_WIDTH 640
#define IM_HEIGHT 480
#define CLEAR(x) memset (&(x), 0, sizeof (x))

struct buffer {
	void * start;
	size_t length;
};

void init_video_capture();
char video_capture(unsigned char* dst);
void free_video_capture();

#endif /* VIDEO_CAPTURE_H_ */
