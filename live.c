/*
 ============================================================================
 Name        : live.c
 Author      : LincolnHard
 Version     :
 Copyright   : free and open
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "draw_framebuffer.h"
#include "video_capture.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* check the supported webcam resolutions using $v4l2-ctl --list-formats-ext */

int main(int argc, char** argv) {
	int width = 0, height = 0;

	if (argc >= 1) width = atoi(argv[0]);
	if (argc >= 2) height = atoi(argv[1]);

	if (width == 0) width = 640;
	if (height == 0) height = 480;

	printf("Using size: %dx%d.\n", width, height);
	usleep(1 * 1000000); // sleep one second

    unsigned char src_image[width * height * 3];
    init_framebuffer();
	init_video_capture(width, height);
	char key = 0;

	for(; ;){
		key = video_capture(src_image, width, height);
		draw_framebuffer(src_image, width, height);
		if(key == 'q'){
			break;
		}
	}
    free_video_capture();
	free_framebuffer();
	return EXIT_SUCCESS;
}
