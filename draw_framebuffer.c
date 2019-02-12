/*
 * draw_framebuffer.c
 *
 *  Created on: Dec 24, 2015
 *      Author: Lincoln
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h> /* for frame buffer */
#include <sys/mman.h>
#include <unistd.h>
#include "video_capture.h"

static int fd = -1;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
static char* fbp = NULL;
static unsigned int screensize = 0;

void free_framebuffer
	(
	void
	)
{
	munmap(fbp, screensize);
	close(fd);
}

void init_framebuffer
	(
	void
	)
{
	fd = open("/dev/fb0", O_RDWR);
	if (fd == -1) 
		{
		perror("Error opening framebuffer device");
		exit(EXIT_FAILURE);
		}
	// Get fixed screen information
	if (ioctl(fd, FBIOGET_FSCREENINFO, &finfo) == -1) 
		{
		perror("Error reading fixed information");
		exit(EXIT_FAILURE);
		}
	// Get variable screen information
	if (ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) == -1) 
		{
		perror("Error reading variable information");
		exit(EXIT_FAILURE);
		}
	screensize = (vinfo.xres * vinfo.yres * vinfo.bits_per_pixel) >> 3; /* (>>3): bits to bytes */

	printf("xoffset: %d, yoffset: %d\nxres: %d, yres: %d\nbits_per_pixel: %d, line_length: %d\n",
			vinfo.xoffset, vinfo.yoffset, vinfo.xres, vinfo.yres, vinfo.bits_per_pixel, finfo.line_length);
#if 0
	vinfo.xres = 800;
	vinfo.yres = 600;
	if (ioctl(fd, FBIOPUT_VSCREENINFO, &vinfo) == -1)
		{
		perror("Error puting variable information");
		exit(EXIT_FAILURE);
		}
	screensize = finfo.line_length * vinfo.yres;

	printf("xoffset: %d, yoffset: %d\nxres: %d, yres: %d\nbits_per_pixel: %d, line_length: %d\n",
			vinfo.xoffset, vinfo.yoffset, vinfo.xres, vinfo.yres, vinfo.bits_per_pixel, finfo.line_length);
#endif
	fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (fbp == (char *)-1) 
		{
		perror("Error mapping framebuffer device to memory");
		exit(EXIT_FAILURE);
		}
}

void draw_framebuffer(unsigned char* src){
	int x, y;
	unsigned int location = 0;
	int i = 0;
	for(y = 0; y < IM_HEIGHT; y++){
		for(x = 0; x < IM_WIDTH; x++){
			location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel >> 3) + (y + vinfo.yoffset) * finfo.line_length;
            *(fbp + location) = src[i*3];           //B
            *(fbp + location + 1) = src[i*3 + 1];	//G
            *(fbp + location + 2) = src[i*3 + 2];	//R
			i++;
		}
	}
}
