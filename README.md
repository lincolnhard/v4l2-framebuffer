# v4l2_framebuffer
Maps the frames from a camera to the display framebuffer.

To check the supported resolutions:
```sh
$ v4l2-ctl --list-formats-ext
```

By default, `640x480` is used. You can specify the resolution via commandline paramters. <br>
The first parameters will be the width, the second one will be the height.

To change your desired resolution, edit macro IM_WIDTH, IM_HEIGHT inside video_capture.h

Press `q`, followed by a press of return, to quit.
#### This was borrowed from OpenCV's `waitKey` function.

![Example](https://cloud.githubusercontent.com/assets/16308037/21586605/dbcd6192-d10d-11e6-86d8-a9c4ed490f5b.jpg)
