LeapCodeExample Project
=======================

This project shows how to use & link to Leap Motion Controller plugin from C++ code. This project requires Leap Motion Controller plugin to be installed in your Engine. 
To interact with the demos have your physical Leap Motion controller connected to your computer. Run the demos & just wave your hands above the device.

It introduces a single class LeapMotionDebugInfo, which uses both the plugin code, and also accesses LeapSDK directly. The class displays hand info on the screen.

That requires adding both the plugin & LeapSDK modules as dependencies inLeapCodeExample.Build.cs.
