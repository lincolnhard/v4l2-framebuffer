# v4l2_framebuffer
Map frame from USB camera to Linux framebuffer

Check supported USB camera resolutions:
$v4l2-ctl --list-formats-ext

To change your desired resolution, edit macro IM_WIDTH, IM_HEIGHT inside video_capture.h

Press 'q' and enter to stop query(borrow the idea from OpenCV waitKey function)

