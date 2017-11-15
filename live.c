/*
 ============================================================================
 Name        : live.c
 Author      : LincolnHard
 Version     :
 Copyright   : free and open
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "video_capture.h"
#include "draw_framebuffer.h"

int main(void) {
    unsigned char src_image[IM_WIDTH * IM_HEIGHT * 3];
    init_framebuffer();
	init_video_capture();
	char key = 0;

	for(; ;){
		key = video_capture(src_image);
		draw_framebuffer(src_image);
		if(key == 'q'){
			break;
		}
	}
    free_video_capture();
	free_framebuffer();
	return EXIT_SUCCESS;
}
